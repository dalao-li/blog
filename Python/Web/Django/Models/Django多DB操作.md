<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-01 16:49:59
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-16 15:02:59
-->

## 多DB

建立Django项目，在建立两个应用app1与app2

修改settings.py文件中的`DATABASES`配置，此处以连接sqlite，mysql数据为例

```py
DATABASES = {
    # 默认数据库
    'default': {
        'ENGINE': 'django.db.backends.sqlite3'，
        'NAME': os.path.join(BASE_DIR， 'db.sqlite3')，
    }，
    # MySQL
    'test_mysql': {
        'ENGINE': 'django.db.backends.mysql'，
        # 数据库名
        'NAME': 'test_mysql'，
        'USER': 'root'，
        'PASSWORD': '123456'，
        # 数据库ip地址
        'HOST': '123.56.233.200'，
        # 访问端口
        'PORT': 3306，
        #设置mysql启用严格模式
        'OPTIONS': {
            'init_command': "SET sql_mode='STRICT_TRANS_TABLES'"，
            'charset': 'utf8'
        }
    }
```

## 数据库路由方法类

与settings.py同级目录下建立database_router.py文件
```py
from django.conf import settings

DATABASE_MAPPING = settings.DATABASE_APPS_MAPPING


class DatabaseAppsRouter(object):
    """
    A router to control all database operations on models for different
    databases.

    In case an app is not set in settings.DATABASE_APPS_MAPPING， the router
    will fallback to the `default` database.

    Settings example:

    DATABASE_APPS_MAPPING = {'app1': 'db1'， 'app2': 'db2'}
    """

    def db_for_read(self， model， **hints):
        """"Point all read operations to the specific database."""
        if model._meta.app_label in DATABASE_MAPPING:
            return DATABASE_MAPPING[model._meta.app_label]
        return None

    def db_for_write(self， model， **hints):
        """Point all write operations to the specific database."""
        if model._meta.app_label in DATABASE_MAPPING:
            return DATABASE_MAPPING[model._meta.app_label]
        return None

    def allow_relation(self， obj1， obj2， **hints):
        """Allow any relation between apps that use the same database."""
        db_obj1 = DATABASE_MAPPING.get(obj1._meta.app_label)
        db_obj2 = DATABASE_MAPPING.get(obj2._meta.app_label)
        if db_obj1 and db_obj2:
            if db_obj1 == db_obj2:
                return True
            else:
                return False
        return None

    def allow_syncdb(self， db， model):
        """Make sure that apps only appear in the related database."""

        if db in DATABASE_MAPPING.values():
            return DATABASE_MAPPING.get(model._meta.app_label) == db
        elif model._meta.app_label in DATABASE_MAPPING:
            return False
        return None

    def allow_migrate(self， db， app_label， model=None， **hints):
        """
        Make sure the auth app only appears in the 'auth_db'
        database.
        """
        if db in DATABASE_MAPPING.values():
            return DATABASE_MAPPING.get(app_label) == db
        elif app_label in DATABASE_MAPPING:
            return False
        return None
```

## 增加数据路由表与规则方法

settings.py文件中添加内容，此处项目名为demo
```py
# 数据库路由规则方法
DATABASE_ROUTERS = ['项目名.database_router.DatabaseAppsRouter']

# 数据库路由表
DATABASE_APPS_MAPPING = {
    'app1':'default'，
    'app2': 'test_mysql'，
}
``` 