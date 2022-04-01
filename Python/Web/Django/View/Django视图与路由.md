<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-01 23:07:59
-->

 
## Django 路由与视图

访问网站的本质即为访问对应的 html 文件，后在由浏览器等对其进行渲染，最终展示出页面


### 静态读取

访问http://127.0.0.1:8000/app/index，读取index.html，显示内容

在 app 目录下新建 templates 文件夹

![](https://cdn.hurra.ltd/img/20200803191147.png)

注册模板目录，新建的模板目录需在项目设置文件中进行注册

打开主目录 settings.py文件，找到 TEMPLATES，将新增模板的路径添加至'DIRS'项中:

```py
TEMPLATES = [
  {
    ...
    'DIRS': [
        os.path.join(BASE_DIR, 'templates'),

        # 新建的模板目录
        os.path.join(BASE_DIR, 'app/templates')
    ],
    ...
  },
]
```

在 demo/app/templates 目录下新建 index.html

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Title</title>
  </head>
  <body>
    <h1>Hello World!</h1>
  </body>
</html>
```

- 编写视图函数

编辑app/views.py 文件

```py
from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, 'index.html')
```

- 绑定子路由

编写好函数后，需将其绑定到对应路由，由于此处是在项目中的应用里配置，故为子路由

在 app 目录下新建 urls.py 文件

```py
from django.urls import path
from app import views

urlpatterns = [
    # 将函数绑定至对应路由
    path('index/', views.index)
]
```

- 注册子路由

绑定还本应用的路由后，还需在项目中进行注册

主目录urls.py文件添加

```py
from django.contrib import admin
from django.urls import path，include

urlpatterns = [
    ...
    # 注册app应用的路由
    path('app/', include('app.urls'))
    ...
]
```

此处 include()函数含义为包含 app 中的所有路由，即实现路由的转发(从主路由分发至子路由)

运行项目，访问http://127.0.0.1:8000/app/index

![](https://cdn.hurra.ltd/img/20200803193631.png)


### 读取数据

访问http://127.0.0.1:8000/app/db，在网页上显示数据库中所有元素信息

在 demo/app/templates 目录下新建 db.html

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Title</title>
  </head>
  <body>
    {% for i in data %}
    <h1>学号 : {{ i.num }}</h1>
    <h2>姓名 : {{ i.name }}</h2>
    <h2>年龄 : {{ i.age }}</h2>
    {% if i.sex == 'M' %}
    <h2>性别 : 男</h2>
    {% elif i.sex == 'W' %}
    <h2>性别 : 男</h2>
    {% endif %} {% endfor %}
  </body>
</html>
```

此处 data 为从数据库中获取的值，读取 html 作为参数传入

- 编写视图函数

编辑 app/views.py，增加

```py
...

def db(request):
    # 获取数据中全部信息
    stu_list = [i for i in Stu.objects.all()]

    return render(request, 'db.html', {'data' : stu_list})
```

- 添加路由

编辑 app/urls.py，增加

```py
urlpatterns = [
    ...

    path('db/', views.db)
]
```

运行项目，访问http://127.0.0.1:8000/app/db

![](https://cdn.hurra.ltd/img/20200803222027.png)


