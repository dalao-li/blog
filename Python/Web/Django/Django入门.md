<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 00:51:25
-->

## Django入门


### 创建项目

![](https://cdn.hurra.ltd/img/20200801113226.png)

创建名为 demo 的 Django 项目

- init: 一个空文件, 声明所在目录的包为一个 Python 包

- settings: 管理项目的配置信息

- urls: 声明请求 url 的映射关系

- wsgi: python 程序和 web 服务器的通信协议

- manage: 一个命令行工具, 用来和 Django 项目进行交互



### 创建应用

创建名为 app 的应用

```py
python manage.py startapp app
```

![](https://cdn.hurra.ltd/img/20200801112336.png)

应用目录结构:

- admin: app 应用后台管理配置文件

- apps: app 应用的配置文件

- models: 数据模块, 用于设计数据库等

- tests: 编写测试脚本

- views: 视图层, 直接和浏览器进行交互


### 应用注册

新建应用需在 settings.py文件中的 INSTALLED_APPS 列表中注册, 使程序找到该服务

![](https://cdn.hurra.ltd/img/20200801112631.png)

setting.py 默认内容:

```py
import os

# 项目的相对路径, 启动服务的时候会运行这个文件所在路径的manage.py
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# 安全密钥
SECRET_KEY = 'oyj48d_pm2jhr2!4e9cmv+&h5j^4y6im_a7t)pqs87q0!5p4+4'

# 是否开启Debug
DEBUG = True

# 允许访问的主机ip, 可以用通配符*
ALLOWED_HOSTS = []

# Application definition

# 用来注册App 前6个是django自带的应用
INSTALLED_APPS = [
    'django.contrib.admin', 
    'django.contrib.auth', 
    'django.contrib.contenttypes', 
    'django.contrib.sessions', 
    'django.contrib.messages', 
    'django.contrib.staticfiles', 
]

# 中间件, 需要加载的中间件.比如在请求前和响应后根据规则去执行某些代码的方法
MIDDLEWARE = [
    'django.middleware.security.SecurityMiddleware', 
    'django.contrib.sessions.middleware.SessionMiddleware', 
    'django.middleware.common.CommonMiddleware', 
    'django.middleware.csrf.CsrfViewMiddleware', 
    'django.contrib.auth.middleware.AuthenticationMiddleware', 
    'django.contrib.messages.middleware.MessageMiddleware', 
    'django.middleware.clickjacking.XFrameOptionsMiddleware', 
]

# 指定URL列表文件 父级URL配置
ROOT_URLCONF = 'demo.urls'

# 加载网页模板路径
TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates', 
        'DIRS': [], 
        'APP_DIRS': True, 
        'OPTIONS': {
            'context_processors': [
                'django.template.context_processors.debug', 
                'django.template.context_processors.request', 
                'django.contrib.auth.context_processors.auth', 
                'django.contrib.messages.context_processors.messages', 
            ], 
        }, 
    }, 
]

# WSGI的配置文件路径
WSGI_APPLICATION = 'demo.wsgi.application'

# 数据库配置 默认的数据库为sqlite
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3', 
        'NAME': os.path.join(BASE_DIR, 'db.sqlite3'), 
    }
}

# 相关密码验证
AUTH_PASSWORD_VALIDATORS = [
    {
        'NAME': 'django.contrib.auth.password_validation.UserAttributeSimilarityValidator', 
    }, 
    {
        'NAME': 'django.contrib.auth.password_validation.MinimumLengthValidator', 
    }, 
    {
        'NAME': 'django.contrib.auth.password_validation.CommonPasswordValidator', 
    }, 
    {
        'NAME': 'django.contrib.auth.password_validation.NumericPasswordValidator', 
    }, 
]

# 语言设置 默认英语, 中文是zh-hans
LANGUAGE_CODE = 'en-us'

# 时区设置, 中国的是:Asia/Shanghai
TIME_ZONE = 'UTC'

# i18n字符集是否支持
USE_I18N = True

USE_L10N = True

# 是否使用timezone
# 保证存储到数据库中的是 UTC 时间;
# 在函数之间传递时间参数时, 确保时间已经转换成 UTC 时间;
USE_TZ = True

# 静态文件路径
STATIC_URL = '/static/'
```


### 视图

编辑app/view.py文件

```py
from django.http import HttpResponse
from django.shortcuts import render

# Create your views here.
def hello(request):
    return HttpResponse('Hello World')
```


### 路由

编辑app/urls.py文件

```py
from django.contrib import admin
from django.urls import path
import app.views

urlpatterns = [
    path('admin/', admin.site.urls), 
    # 将hello()函数绑定路由
    path('hello/', app.views.hello)
]
```


### 测试

运行, 访问http://127.0.0.1:8000/hello

![](https://cdn.hurra.ltd/img/20200801113106.png)

![](https://cdn.hurra.ltd/img/20200801113140.png)



