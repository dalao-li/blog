<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-28 22:29:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 00:50:35
-->

## Django命令


### 初始化


#### 建立项目

```py
django-admin.py startproject [项目名]
```


#### 新建应用

```py
python manage.py startapp 应用名
```


#### 运行

```py
python manage.py runserver [0.0.0.0:8000]
```



### 数据库


#### 迁移

```sh
# 终端执行, 为改动创建迁移记录
python manage.py makemigrations

# 将操作同步到数据库
python manage.py migrate
```

- 同步到多个数据库

```sh
python manage.py migrate --database=路由表中应用对应的数据库
```


#### 创建管理员用户

```sh
python manage.py createsuperuser
```