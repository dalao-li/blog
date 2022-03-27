<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-28 22:29:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 23:20:41
-->

## Django命令


### 建立项目

```sh
django-admin.py startproject 项目名
```


### 运行

```sh
python manage.py runserver [0.0.0.0:8000]
```


### 新建应用

```sh
python manage.py startapp app
```


### 迁移数据库

```sh
# 终端执行，为改动创建迁移记录
python manage.py makemigrations

# 将操作同步到数据库
python manage.py migrate  
```
- 同步到多个数据库

```sh
python manage.py migrate --database=路由表中应用对应的数据库
```


### 创建管理员用户

```sh
python manage.py createsuperuser
```