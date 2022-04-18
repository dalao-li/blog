<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 10:20:52
-->

## 完整代码

> https://github.com/Dalao-Li/WebNotepad-Django.git


## 运行结果

![](https://cdn.hurra.ltd/img/20200809153325.png)

![](https://cdn.hurra.ltd/img/20200809153600.png)

![](https://cdn.hurra.ltd/img/20200809153721.png)

![](https://cdn.hurra.ltd/img/20200809153802.png)

![](https://cdn.hurra.ltd/img/20200809154003.png)

![](https://cdn.hurra.ltd/img/20200816225928.png)


## 涉及技术

> - CSS : BootStrap4 , Font Awesome,
> - JS : JQuery , SweetAlery2
> - Web 框架 : Django
> - 数据库 : Sqlite3


## 概要设计


### 前端

显示设计

1. 主页面

显示进行中与已经完成的记事

每一行显示记事的序号、标题、内容与状态

- 完成按钮

可完成记事

- 添加按钮

点击后可添加新记事

- 编辑记事

对进行中的记事,当点击对应行时会弹出修改页面,用户可对其进行修改

对进行中记事可进行的操作为 : 修改,标记完成,删除

对已完成记事可进行的操作为 : 删除

2. 回收站

显示所有已经删除的记事


### 数据库

sqlite3

表设计

note

| 列名   | 说明           | 备注                                                                                                       |
| ------ | -------------- | ---------------------------------------------------------------------------------------------------------- |
| id     | 每条记事的序号 | Django 自定义主键                                                                                          |
| name   | 每条记事的标题 | 限定 2-15 字                                                                                               |
| text   | 记事的内容     | 限定 2-15 字                                                                                               |
| s_time | 开始时间       | 必须比结束时间早                                                                                           |
| e_time | 结束时间       | 必须比开始时间晚                                                                                           |
| status | 该记事状态     | U(underway): 进行中<br>F(finish) : 已完成<br>D(deleted) : 已删除 <br> O(Overtime):已超时<br>P(Plan):未开始 |


## 具体实现


### 初始化项目

建立项目

建立一个应用 app

```py
python manage.py startapp app
```

修改 settings.py 文件

在 INSTALLED_APPS 中添加刚创建的应用

![](https://cdn.hurra.ltd/img/20200805182554.png)

在 MIDDLEWARE 中注释 django.middleware.csrf.CsrfViewMiddleware

![](https://cdn.hurra.ltd/img/20200805182720.png)

修改语言与时区

![](https://cdn.hurra.ltd/img/20200805182830.png)

在 app 目录下新建 static 与 templates 目录,用于存放静态文件和模板文件



### 前端

app/templates 目录下新建 main.html 文件

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>记事本</title>

    {% load static %}
    <link rel="stylesheet" href="https://cdn.staticfile.org/font-awesome/4.7.0/css/font-awesome.css">
    <link rel="stylesheet" href="{% static "css/bootstrap.min.css" %}">
    <link rel="stylesheet" href="{% static 'css/sweetalert.css' %}">
    <link rel="stylesheet" href="{% static 'css/bootstrap-table.min.css' %">
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
    <h2><i class="fa fa-book"></i>
        记事本
    </h2>
</div>

<button id="addNoteButton" type="button" class="btn btn-primary btn-lg">添加
    <i class="fa fa-plus-square" style="font-size:20px"></i>
</button>


<table id="noteTable" class="table table-hover">
    <thead>
    <tr>
        <th>序号</th>

        <th>标题</th>
        <th>正文</th>
        <th>开始时间</th>
        <th>结束时间</th>
        <th>状态</th>
        <th>
            <i class="fa fa-cog"></i>
            操作
        </th>
    </tr>
    </thead>
    <tbody>
    {% for i in note %}
        <tr>
            <td>{{ i.id }}</td>
            <td>{{ i.name }}</td>
            <td>{{ i.text }}</td>
            <td>{{ i.s_time }}</td>
            <td>{{ i.e_time }}</td>
            {% if i.status == 'F' %}
                <td class="danger">已完成</td>
            {% elif i.status == 'U' %}
                <td class="safe">进行中</td>
            {% endif %}
            <td>
                {% if i.status == 'F' %}
                    <button type="button" class="btn btn-success" onclick="" disabled>完成
                        <i class="fa fa-check-square-o" style="font-size:20px"></i>
                    </button>
                {% elif i.status == 'U' %}
                    <button type="button" class="btn btn-success" onclick=finishNote("{{ i.id }}")>完成
                        <i class="fa fa-check-square-o" style="font-size:20px"></i>
                    </button>
                {% endif %}
                <button type="button" class="btn btn-danger" onclick=delNote("{{ i.id }}")>删除
                    <i class="fa fa-trash" style="font-size:20px"></i>
                </button>
            </td>
        </tr>
    {% endfor %}
    </tbody>
</table>

<!--添加笔记弹出框-->
<div id="newNoteAlert" class="modal fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h4 class="modal-title" id="myModalLabel">
                    <i class="fa fa-user-plus" style="font-size:28px"></i>
                    新增记事
                </h4>
            </div>
            <div class="modal-body">
                <!--上传信息表格-->
                <form id="newNoteForm" action="" onsubmit="return false">
                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">标题</span>
                        </div>
                        <label for="name"></label>
                        <input type="text" class="form-control" id="name" name="name" required>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">内容</span>
                        </div>
                        <label for="text"></label>
                        <input type="text" class="form-control" id="text" name="text" required>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">开始时间</span>
                        </div>
                        <label for="startTime"></label>
                        <input type="datetime-local" class="form-control" id="startTime" name="startTime"
                               placeholder="请选择开始时间"
                               required>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">结束时间</span>
                        </div>
                        <label for="endTime"></label>
                        <input type="datetime-local" class="form-control" id="endTime" name="endTime"
                               placeholder="请选择结束时间"
                               required>
                    </div>

                    <div class="modal-footer">
                        <button type="button" class="btn btn-primary" onclick=addNote()>提交
                            <i class="fa fa-pencil-square-o" style="font-size:20px"></i>
                        </button>
                        <button type="button" class="btn btn-danger" data-dismiss="modal">关闭
                            <i class="fa fa-times" style="font-size:20px"></i>
                        </button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>


<!--修改笔记弹出框-->
<div id="modifyNoteAlert" class="modal fade" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
     aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h4 class="modal-title" id="myModalLabel">
                    <i class="fa fa-wrench"> 修改记事</i>
                </h4>
            </div>
            <div class="modal-body">
                <form id="modifyNoteForm" action="" onsubmit="return false">
                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">记事序号</span>
                        </div>
                        <label for="id"></label>
                        <input type="text" class="form-control" id="id" name="id" required disabled>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">标题</span>
                        </div>
                        <label for="names"></label>
                        <input type="text" class="form-control" id="names" name="names" required>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">内容</span>
                        </div>
                        <label for="texts"></label>
                        <input type="text" class="form-control" id="texts" name="texts" required>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">开始时间</span>
                        </div>
                        <label for="startTimes"></label>
                        <input type="datetime-local" class="form-control" id="startTimes" name="startTimes"
                               placeholder="请选择开始时间"
                               required>
                    </div>

                    <div class="input-group mb-3">
                        <div class="input-group-prepend">
                            <span class="input-group-text">结束时间</span>
                        </div>
                        <label for="endTimes"></label>
                        <input type="datetime-local" class="form-control" id="endTimes" name="endTimes"
                               placeholder="请选择结束时间"
                               required>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-primary" onclick=modifyNote()>提交
                            <i class="fa fa-pencil-square-o" style="font-size:20px"></i>
                        </button>
                        <button type="button" class="btn btn-danger" data-dismiss="modal">关闭
                            <i class="fa fa-times" style="font-size:20px"></i>
                        </button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>

<script>

    $('#noteTable').bootstrapTable({
        //点击行事件
        onDblClickRow: function (row) {
            if (row[5] === '进行中') {
                $('#modifyNoteAlert').modal('show')
                $('#id').val(row[0])
                $('#names').val(row[1])
                $('#texts').val(row[2])
            }
        },
        //是否显示分页条
        pagination: true,
        //首页页码
        pageNumber: 1,
        //一页显示的行数
        pageSize: 10,
        //是否开启分页条无限循环,最后一页时点击下一页是否转到第一页
        paginationLoop: false,
        //选择每页显示多少行,数据过少时可能会没有效果
        pageList: [10, 20],
        //启用关键字搜索框
        search: true,
    })

    $('#addNoteButton').click(function () {
        $('#newNoteAlert').modal('show')
    })

</script>
</body>
</html>
```

app/static 目录下新建 api.js 文件

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
    success: function (data) {
      callback(data.result);
    },
    error: function (data) {
      //错误处理
    },
  });
}

function addNote() {
  var d = {};
  //表单是否存在空值
  var isNull = false;
  var t = $("#newNoteForm").serializeArray();
  $.each(t, function () {
    if (this.value === "") {
      isNull = true;
      addCallback(0);
      // return false才代表退出each()函数
      return false;
    }
    d[this.name] = this.value;
  });
  //若存在空值则不发送ajax
  if (isNull) {
    return;
  }
  sendAjax(d, "/app/add/", function (value) {
    if (value === 1) {
      swal(
        { title: "添加成功", text: "", type: "success", timer: 2000 },
        function () {
          location.href = "/app/";
        }
      );
    }
    if (value === 0) {
      swal("填写内容不能为空", "请重写填写", "error");
    }
  });
}

function delNote(n_id) {
  swal(
    {
      title: "确定要删除该记事吗？",
      text: "删除不可恢复",
      type: "warning",
      showCancelButton: true,
      confirmButtonColor: "#DD6B55",
      confirmButtonText: "确认",
      cancelButtonText: "取消",
      closeOnConfirm: false,
      closeOnCancel: false,
    },
    function (isConfirm) {
      if (!isConfirm) {
        swal({
          title: "已取消",
          text: "您取消了删除操作！",
          type: "warning",
        });
        return;
      }
      var data = {
        n_id: n_id,
      };
      sendAjax(data, "/app/del/", function (value) {
        if (value === 1) {
          swal(
            { title: "删除成功", text: "", type: "success", timer: 2000 },
            function () {
              location.reload();
            }
          );
        }
        if (value === -1) {
          swal("删除失败", "请重试", "error");
        }
      });
    }
  );
}

function finishNote(n_id) {
  var data = {
    n_id: n_id,
    status: "F",
  };
  sendAjax(data, "/app/change/", function (value) {
    if (value === 1) {
      swal(
        { title: "记事已完成", text: "", type: "success", timer: 2000 },
        function () {
          location.reload();
        }
      );
    }
    if (value === -1) {
      swal("网络异常", "请重试", "error");
    }
  });
}

function modifyNote() {
  var d = {};
  //表单是否存在空值
  var isNull = false;
  var t = $("#modifyNoteForm").serializeArray();
  $.each(t, function () {
    if (this.value === "") {
      isNull = true;
      addCallback(0);
      // return false才代表退出each()函数
      return false;
    }
    d[this.name] = this.value;
  });
  //若存在空值则不发送ajax
  if (isNull) {
    return;
  }
  sendAjax(d, "/app/add/", function (value) {
    if (value === 1) {
      swal(
        {
          title: "修改成功",
          text: "",
          type: "success",
          timer: 2000,
        },
        function () {
          location.href = "/app/";
        }
      );
    }
    if (value === 0) {
      swal("填写内容不能为空", "请重写填写", "error");
    }
  });
}
```

## 后端

### 数据库

编辑 app/models.py 文件

```py
from django.db import models


# Create your models here.

class Note(models.Model):
    choices = (
        ('U', 'Underway'),
        ('F', 'Finish'),
        ('D', 'Deleted')
    )

    name = models.CharField(verbose_name='标题', help_text='请输入记事标题', max_length=5)
    text = models.TextField(verbose_name='内容', help_text='请输入记事内容', max_length=20)
    s_time = models.DateTimeField(verbose_name='开始时间', help_text='请选择开始时间')
    e_time = models.DateTimeField(verbose_name='结束时间', help_text='请选择结束时间')
    status = models.CharField(verbose_name='状态', help_text='请选择状态', default='U', choices=choices, max_length=1)
```

编辑完成后终端执行:

```py
# 为改动创建迁移记录
python manage.py makemigrations

# 将操作同步到数据库
python manage.py migrate
```

![](https://cdn.hurra.ltd/img/20200809154710.png)


### 视图函数

编辑 app/views.py

```py
import json

from django.shortcuts import render, HttpResponse
from app.models import Note


# Create your views here.

# 主页面
def main_page(request):
    # 获取所有未被删除的文章
    notes = [i for i in Note.objects.exclude(status='D')]
    return render(request, 'main.html', {'note': notes})



def add_note(request):
    data = json.loads(request.body)
    name, text, s_time, e_time = data.values()
    Note.objects.create(name=name, text=text, s_time=s_time, e_time=e_time, status='U')
    return HttpResponse(json.dumps({'result': 1}))


def modify_note(request):
    data = json.loads(request.body)
    n_id, name, text, s_time, e_time = data.values()
    Note.objects.filter(id=n_id).update(name=name, text=text,s_time=s_time, e_time=e_time)
    return HttpResponse(json.dumps({'result': 1}))


def del_note(request):
    data = json.loads(request.body)
    n_id = list(data.values())[0]
    Note.objects.filter(id=n_id).delete()
    if Note.objects.filter(id=n_id).exists():
        return HttpResponse(json.dumps({'result': -1}))
    return HttpResponse(json.dumps({'result': 1}))

def change_note_status(request):
    data = json.loads(request.body)
    n_id, status = data.values()
    Note.objects.filter(id=n_id).update(status=status)
    if Note.objects.filter(id=n_id, status=status).exists():
        return HttpResponse(json.dumps({'result': 1}))
    return HttpResponse(json.dumps({'result': -1}))

```

### 绑定路由

在 app 目录下新建 urls.py文件

```py
from django.urls import path
from app import views

urlpatterns = [
    # 将函数绑定至对应路由
    path('', views.main_page),

    path('add/',views.add_note),

    path('del/',views.del_note),

    path('modify/',views.modify_note),

    path('change/',views.change_note_status)


]
```

编辑主目录下 urls.py文件

```py
from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('admin/', admin.site.urls),
    path('app/', include('app.urls'))
]

```

