<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 00:46:56
-->

## Django动态路由


### 关键字实现


#### 单关键字

views.py文件

```py
def dis(request, value):
    return HttpResponse(value)
```

urls.py文件

```py
urlpatterns = [
    url(r'^dis/(\w+)$', views.dis), 
]
```

| 参数 | 含义                                       |
| ---- | ------------------------------------------ |
| `\w` | 匹配字母、数字、下划线, 等价于[A-Za-z0-9_] |
| `+`  | 匹配前面的子表达式一次或多次               |
| `$`  | 表示结尾                                   |

此时可匹配`127.0.0.1:8000/dis/<字符>`这类 url, 并且<字符>部分的值将作为 dis 函数的第二个参数


![](https://cdn.hurra.ltd/img/20200903085713.png)

![](https://cdn.hurra.ltd/img/20200903091232.png)



#### 多关键字

views.py文件

```py
from django.http import HttpResponse

def dis(request, v1, v2):
    res = "v1:%s v2:%s"%(v1, v2)
    return HttpResponse(res)
```

urls.py文件

```py
urlpatterns = [
    url(r'^dis/(?P<v1>\w+)/(?P<v2>\w+)', views.dis), 
]
```

前面的 w+传给 v1, 后面的 w+传给 v2此时可以匹配`127.0.0.1:8000/dis/<字符1>/<字符2>`这类 url, 并且字符 1 将传给 dis 函数的 v1 参数;字符 2 将传给 dis 函数的 v2 参数



### 反射实现


反射, 通过输入的函数名调用函数

urls.py文件

```py
urlpatterns = [
    re_path(r'^dis/(?P<fuc_name>\w+)/$', views.use_fuc_byname), 
]
```

views.py
```py
from django.http import HttpResponse

def use_fuc_byname(request, fuc_name):
    return eval(fuc_name)(request)


def hello_world(request):
    return HttpResponse('HELLO WORLD')

def goodbye_world(request):
    return HttpResponse('GOODBYE WORLD')
```

访问`http:127.0.0.1:8000/dis/hello_world`, 会自动调用 hello_world()

![](https://cdn.hurra.ltd/img/20200903103754.png)



###  删除硬编码URL


硬编码即href里的"/polls/"部分

```html
<li><a href="/polls/{{ question.id }}/">{{ question.question_text }}</a></li>
```
它对于代码修改非常不利, 前面给urls定义了一个name别名, 可以用它来解决这个问题, 具体代码如下:

```html
<li><a href="{% url 'detail' question.id %}">{{ question.question_text }}</a></li>
```
Django会在polls.urls文件中查找name='detail'的路由, 具体的就是下面这行:

```py
path('<int:question_id>/', views.detail, name='detail'), 
```

如果想将polls的detail视图的URL更换为polls/specifics/12/, 那么仅仅只需要在polls/urls.py文件中, 将对应的正则表达式改成下面这样的就行, 所有模板中对它的引用都会自动修改成新的链接

```py
# 添加新的单词'specifics'
path('specifics/<int:question_id>/', views.detail, name='detail'), 
```