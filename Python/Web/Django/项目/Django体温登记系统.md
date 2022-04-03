<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-03 21:55:37
-->

> github 地址 : `https://github.com/Dalao-Li/RegisterSystem-Django.git`


## 技术

```sh
CSS : Bootstrap
JS : JQuery
弹窗控件 : SweetAlert2
Web 框架 : Django
数据库 : Sqlite3
```

## 初始化

- 建立 Django 项目

![](https://cdn.hurra.ltd/img/20200805181844.png)

```py
# 建立一个应用 app
python manage.py startapp app
```

项目结构

![](https://cdn.hurra.ltd/img/20200805182327.png)

- 修改 settings.py文件

在 INSTALLED_APPS 中添加刚创建的应用

![](https://cdn.hurra.ltd/img/20200805182554.png)

在 MIDDLEWARE 中注释 django.middleware.csrf.CsrfViewMiddleware

![](https://cdn.hurra.ltd/img/20200805182720.png)

修改语言与时区

![](https://cdn.hurra.ltd/img/20200805182830.png)

## 数据库设计

- 表设计

| 名称      | 类型          | 说明           |
| --------- | ------------- | -------------- |
| num       | CharField     | 学号           |
| name      | CharField     | 姓名           |
| temperate | FloatField    | 温度           |
| date      | DateTimeField | 上传日期与时间 |

编辑 app/models.py 文件

```py
from django.db import models

# Create your models here.

class Reocrd(models.Model):
    num = models.CharField(verbose_name='学号', max_length=8)
    name = models.CharField(verbose_name='姓名',max_length=5)
    temperature = models.FloatField(verbose_name='体温')
    date = models.DateTimeField(verbose_name='日期')

    def __str__(self):
        return self.num
```

```py
# 为改动创建迁移记录
python manage.py makemigrations

# 将操作同步到数据库
python manage.py migrate
```

- 创建管理员用户

```py
python manage.py createsuperuser
```

输入用户名和密码,邮箱地址可选

![](https://cdn.hurra.ltd/img/20200802153640.png)

## 视图 

在 app 目录下新建 templates 文件夹

编辑 settings.py文件,找到 TEMPLATES,将新增模板的路径添加至 DIRS 项中:

![](https://cdn.hurra.ltd/img/20200805185510.png)

在 app/templates 下新建 index.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>体温登记系统</title>
    {% load static %}
    <link rel="stylesheet" href="{% static 'css/bootstrap.min.css' %}">
    <link rel="stylesheet" href="{% static 'css/sweetalert.css' %}">
    <link rel="stylesheet" href="{% static 'css/bootstrap-table.min.css' %}">
    <script src="{% static 'js/jquery.min.js' %}"></script>
    <script src="{% static 'js/popper.min.js' %}"></script>
    <script src="{% static 'js/bootstrap.min.js' %}"></script>
    <script src="{% static 'js/sweetalert-dev.js' %}"></script>
    <script src="{% static 'js/bootstrap-table.min.js' %}"></script>
    <script src="{% static 'js/bootstrap-table-zh-CN.min.js' %}"></script>
    <script src="{% static 'js/api.js' %}"></script>
    <style>
        .danger {
            color: red;
            font-weight: bold;
        }

        .safe {
            color: green;
            font-weight: bold;
        }
    </style>
</head>
<body>
<div style="text-align: center;">
    <h2>体温登记</h2>
</div>

<table class="table table-hover">
    <form id="recordForm">
        <td>
            <div class="input-group">
                <label for="num"></label>
                <input type="text" class="form-control" id="num" name="num" placeholder="请输入学号" minlength="8"
                       maxlength="8">
            </div>
        </td>
        <td>
            <div class="input-group">
                <label for="name"></label>
                <input type="text" class="form-control" id="name" name="name" placeholder="请输入姓名" required >
            </div>
        </td>
        <td>
            <div class="input-group">
                <label for="tem"></label>
                <input type="number" class="form-control" id="tem" name="tem" placeholder="请输入体温" min="35" max="43"
                       step="0.1" required>
            </div>
        </td>
        <td>
            <div class="input-group">
                <label for="date"></label>
                <input type="datetime-local" class="form-control" id="date" name="date" placeholder="请选择日期" required>
            </div>
        </td>
        <td>
            <button type="submit" class="btn btn-primary" onclick=addRecord()>提交</button>
        </td>
    </form>
</table>
<table class="table table-hover" id="recordTable">
    <thead>
    <tr>
        <th>序号</th>
        <th>学号</th>
        <th>姓名</th>
        <th>体温</th>
        <th>提交日期与时间</th>
        <th>操作</th>
    </tr>
    </thead>
    <tbody>
    {% for i in record %}
        <tr>
            <td>{{ i.id }}</td>
            <td>{{ i.num }}</td>
            <td>{{ i.name }}</td>
            {% if i.temperature > 37.5 %}
                <td class="danger">
                    {{ i.temperature }}
                </td>
            {% else %}
                <td class="safe">
                    {{ i.temperature }}
                </td>
            {% endif %}
            <td>{{ i.date }}</td>
            <td>
                <button type="button" class="btn btn-danger" onclick=delRecord("{{ i.num }}")>删除</button>
            </td>
        </tr>
    {% endfor %}
    </tbody>
</table>


<script>
    $('#recordTable').bootstrapTable({
        //是否显示分页条
        pagination: true,
        //首页页码
        pageNumber: 1,
        //一页显示的行数
        pageSize: 5,
        //是否开启分页条无限循环,最后一页时点击下一页是否转到第一页
        paginationLoop: false,
        //选择每页显示多少行,数据过少时可能会没有效果
        pageList: [5, 10, 20],
        //启用关键字搜索框
        search: true
    })
</script>
</body>
</html>
```

## JS

app 目录下新建 static 目录,存放静态文件

app/static/js 目录下新建 api.js:

```js
function sendAjax(param, url, callback) {
  $.ajax({
    async: false,
    ache: false,
    type: "POST",
    url: url,
    //JSON对象转化JSON字符串
    data: JSON.stringify(param),
    //服务器返回的数据类型
    dataType: "json",
    //清除浏览器缓存
    beforeSend: function (xmlHttp) {
      xmlHttp.setRequestHeader("If-Modified-Since", "0");
      xmlHttp.setRequestHeader("Cache-Control", "no-cache");
    },
    success: function (data) {
      callback(data.result);
    },
    error: function (data) {
      //错误处理
    },
  });
}

function addRecord() {
  var data = {
    num: $("#num").val(),
    name: $("#name").val(),
    tem: $("#tem").val(),
    date: $("#date").val(),
  };
  //判断非空
  for (var k in data) {
    if (data[k] === "") {
      return;
    }
  }
  sendAjax(data, "/app/add/", addCallback);
}

function addCallback(value) {
  if (value === 1) {
    swal(
      {
        title: "提交成功",
        text: "",
        type: "success",
        timer: 2000,
      },
      function () {
        location.reload();
      }
    );
  }
  if (value === 0) {
    swal("上交失败", "请重试", "error");
  }
  if (value === -1) {
    swal(
      {
        title: "该学生体温已提交",
        text: "请勿重复提交",
        type: "warning",
      },
      function () {
        $("#recordForm")[0].reset();
      }
    );
  }
}

function delRecord(id) {
  swal(
    {
      title: "您确定要删除该记录吗",
      text: "删除后将无法恢复,请谨慎操作！",
      type: "warning",
      showCancelButton: true,
      confirmButtonColor: "#DD6B55",
      confirmButtonText: "确认",
      cancelButtonText: "取消",
      closeOnConfirm: false,
      closeOnCancel: false,
    },
    function (isConfirm) {
      if (isConfirm) {
        var data = { num: id };
        sendAjax(data, "/app/del/", delCallback);
      } else {
        swal({
          title: "已取消",
          text: "您取消了删除操作！",
          type: "warning",
        });
      }
    }
  );
}

function delCallback(value) {
  if (value === 1) {
    swal(
      {
        title: "删除成功",
        text: "",
        type: "success",
        timer: 2000,
      },
      function () {
        location.reload();
      }
    );
    return;
  }
  if (value === -1) {
    swal("删除失败", "请重试", "error");
  }
}
```

项目最终结构

![](https://cdn.hurra.ltd/img/20200805190123.png)

`完整代码请访问博主的Github`

## 视图函数

编辑 app/views.py 文件:

```py
import json

from django.shortcuts import render, HttpResponse
from app.models import Reocrd


# Create your views here.

# 显示主页面
def index(request):
    record = [i for i in Reocrd.objects.all()]
    return render(request, 'index.html', {'record': record})


def add_record(request):
    data = json.loads(request.body)
    num, name, tem, date = data.values()
    # 查询是否已经提交
    if Reocrd.objects.filter(num=num).exists():
        return HttpResponse(json.dumps({'result': -1}))
    Reocrd.objects.create(num=num, name=name, temperature=tem, date=date)
    return HttpResponse(json.dumps({'result': 1}))


def del_record(request):
    data = json.loads(request.body)
    num = list(data.values())[0]
    Reocrd.objects.filter(num=num).delete()
    if Reocrd.objects.filter(num=num).exists():
        return HttpResponse(json.dumps({'result': -1}))
    return HttpResponse(json.dumps({'result': 1}))

```

## 绑定路由

在 app 目录下新建 urls.py 文件:

```py
from django.urls import path
from app import views

urlpatterns = [
    # 将函数绑定至对应路由
    path('', views.index),

    path('add/', views.add_record),

    path('del/', views.del_record)
]

```

编辑主目录下的 urls.py 文件:

```py
from django.contrib import admin
from django.urls import path,include

urlpatterns = [

    path('admin/', admin.site.urls),
    # 注册应用app的路由
    path('app/',include('app.urls'))
]
```

运行项目,访问http://127.0.0.1/app/,查看

![](https://cdn.hurra.ltd/img/20200806160425.png)

## 部署

本项目采用 Docker + Gunicorn 方式进行部署

- 部署后可能会出现无法访问静态文件的情况,因此编辑主目录下 urls.py文件,新增:

```py
from django.contrib import admin
from django.urls import path,include

# 新增
from django.contrib.staticfiles.urls import staticfiles_urlpatterns

......

# 新增
urlpatterns += staticfiles_urlpatterns()
```

- 主目录下新建 gunicorn_config.py文件:

```py
# 定义同时开启的处理请求的进程数量,根据网站流量适当调整
workers = 5

# 采用gevent库,支持异步处理请求,提高吞吐量
worker_class = "gevent"

# 这里8000可以随便调整
bind = "0.0.0.0:8000"

# 超时
timeout = 30
```

- 生成项目依赖文件

```py
pip freeze > requirements.txt
```

```shell
asgiref==3.2.10
cffi==1.14.1
Django==3.0.8
gevent==20.6.2
greenlet==0.4.16
gunicorn==20.0.4
pycparser==2.20
pytz==2020.1
sqlparse==0.3.1
zope.event==4.4
zope.interface==5.1.0
```


- 编写 Dockerfile

```docker
#所采用的基础镜像
FROM python:3.7

# 为镜像添加标签
LABEL version="v1" description="Docker deploy Django" by="Dalao"

#程序的运行目录
WORKDIR /usr/django

#导入库依赖文件
COPY requirements.txt ./

#安装库
RUN pip install -r requirements.txt -i https://pypi.tuna.tsinghua.edu.cn/simple/

# 复制项目文件
COPY . .

# 容器启动时执行指令,每个Dockerfile只能有一条CMD命令
CMD ["gunicorn", "demo.wsgi", "-c", "gunicorn_config.py"]
```

将文件夹上传至服务器


```shell
docker build -t mydemo .
```

![](https://cdn.hurra.ltd/img/20200806185516.png)

运行容器,查看结果

```shell
docker run -itd -p 80:8000 --name django_test mydemo
```

![](https://cdn.hurra.ltd/img/20200806190407.png)

---


