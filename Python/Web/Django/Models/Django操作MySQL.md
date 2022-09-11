<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 19:47:12
-->

## Django 操作MySQL


建立应用 app

```py
python3 manage.py startapp app
```

![](https://cdn.hurra.ltd/img/20200802134308.png)


主目录下 settings.py文件中的DATABASES为默认配置, 会建立 sqlite3 数据库

![](https://cdn.hurra.ltd/img/20200802140333.png)

若使用其他数据库, 需进行修改, 此处以 MySQL 为例:

```sh
DATABASES = {
    'default': {
        # 数据库引擎
        'ENGINE': 'django.db.backends.mysql', 
        'NAME': 数据库名, 
        'USER': 用户名, 
        'PASSWORD': 密码, 
        'HOST': IP, 
        'PORT': 端口, 
    }
}
```


### 建表


编辑 app/models.py

```py
from django.db import models

# 学生表
class Stu(models.Model):
    choices=(('M',  '男'), ('W',  '女')), 
    num = models.CharField(primary_key=True, verbose_name='学号', help_text='请输入学号', max_length=5)
    name = models.CharField(verbose_name='姓名', help_text='请输入姓名', max_length=5)
    age = models.IntegerField(verbose_name='年龄', help_text='请输入年龄')
    sex = models.CharField(verbose_name='性别', help_text='请选择性别', default='M', max_length=1)

    # 元数据
    class Meta:
        # 按'age'字段升序排列
        ordering = ['age']

    # 显示类信息
    def __str__(self):
        sex = '男' if self.sex == 'M' else '女'
        return '学号:%s  姓名:%s  年龄:%s 性别:%s' % (self.num,  self.name,  self.age, sex)
```


### 字段


| 类型          | 说明                                                                                                                            |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| AutoField     | 一个自动增加的整数类型字段.通常不需要自己编写, Django 会自动添加自增字段:id = models.AutoField(primary_key=True), 从 1 开始计数 |
| CharField     | 字符串类型.必须接收一个 max_length 参数, 表示字符串长度不能超过该值.默认的表单标签是 input text                                 |
| TextField     | 大量文本内容, 在 HTML 中表现为 Textarea 标签                                                                                    |
| IntegerField  | 整数类型, 取值范围-2147483648 到 2147483647                                                                                     |
| DateField     | 日期类型, Python 中的 datetime.date()实例, 例如 2020-08-05                                                                      |
| DateTimeField | 日期时间类型, Python datetime.datetime()实例.多了小时、分和秒的显示, 例如 2020-08-05 23:08                                      |
| FileField     | 上传文件类型                                                                                                                    |
| ImageField    | 图像类型                                                                                                                        |


### 字段参数


| 类型         | 说明                                                                                                        |
| ------------ | ----------------------------------------------------------------------------------------------------------- |
| default      | 字段的默认值, 可以是值或者一个可调用对象                                                                    |
| help_text    | 额外显示在表单部件上的帮助文本                                                                              |
| primary_key  | 若为字段设置了 primary_key=True, 则当前字段变为主键; primary_key=True 隐含 null=False 和 unique=True 的意思 |
| verbose_name | 为字段设置可读, 直观的别名                                                                                  |
| choices      | 选择框标签, 值为一个二维的二元元组;第一个元素表示数据库内的真实值, 第二个表示页面上的显示内容               |


```py
# 为改动创建迁移记录
python manage.py makemigrations

# 将操作同步到数据库
python manage.py migrate
```

![](https://cdn.hurra.ltd/img/20200802152633.png)

此时 app/migrations 下生成 0001_initial.py 文件

![](https://cdn.hurra.ltd/img/20200802233105.png)


### 管理


Django 自带后台管理页面, 使用前需创建管理员用户

```py
python manage.py createsuperuser
```

输入用户名和密码, 邮箱地址可选

![](https://cdn.hurra.ltd/img/20200802153640.png)

启动项目, 访问http://127.0.0.1:8000/admin/

![](https://cdn.hurra.ltd/img/20200802153902.png)
![](https://cdn.hurra.ltd/img/20200802154127.png)

现在还无法看到建好的表, 需在 admin 中注册, 将 app 的模型加入站点内, 接受站点管理

打开 app/admin.py 文件, 修改为:

```py
from django.contrib import admin
from .models import Stu
# Register your models here.

# 注册Stu
admin.site.register(Stu)
```


![](https://cdn.hurra.ltd/img/20200802213738.png)



### 新增


可视化, 直接使用 Django 管理页面新增数据

![](https://cdn.hurra.ltd/img/20200802223956.png)

![](https://cdn.hurra.ltd/img/20200802224031.png)

由于之前设定了 ordering = ['age'], 故添加的数据会按从小到大的顺序排列


命令行执行

```py
s = Stu(num='D-123', name='强', age=19, sex='M')

s.save()

或

s = Stu.objects.create(num='D-123', name='强', age=19, sex='M')
```

![](https://cdn.hurra.ltd/img/20200802235206.png)

![](https://cdn.hurra.ltd/img/20200802235230.png)



### 查询


- 获取所有对象

```py
stu_list = Stu.objects.all()
```

![](https://cdn.hurra.ltd/img/20200802235655.png)


- 过滤查询

```py
# 查询所有男性同学
stu = Stu.objects.filter(sex='M')
```

![](https://cdn.hurra.ltd/img/20200803001551.png)


- 单一查询

```py
# 查询学号为 A-123 的同学
stu = Stu.objects.get(num='A-123')
```

![](https://cdn.hurra.ltd/img/20200803001831.png)


- 查询是否存在

```py
# 查询学号为 B-456 的同学是否存在
Stu.objects.filter(num='B-456').exists()
```

![](https://cdn.hurra.ltd/img/20200803004453.png)


### 修改


![](https://cdn.hurra.ltd/img/20200803002039.png)

```py
# 所有男性同学年龄改为 18 岁
Stu.objects.filter(sex='M').update(age=18)
```

![](https://cdn.hurra.ltd/img/20200803004011.png)

![](https://cdn.hurra.ltd/img/20200803004052.png)



### 删除


```py
# 删除学号为 A-123 的同学信息
Stu.objects.filter(num='A-123').delete()
```

![](https://cdn.hurra.ltd/img/20200803004719.png)

![](https://cdn.hurra.ltd/img/20200803004753.png)