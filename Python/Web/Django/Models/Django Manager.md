<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-02-04 21:43:48
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 19:46:21
-->

## Django Manager


### Models

```py
class User(models.Model):
    name = models.CharField(max_length = 10)
    pwd = models.CharField(max_length = 300)
```

此时对数据库进行操作需通过, 

```py
User.objects.create(name = name, pwd = pwd)

User.objects.filter(name = name)

...
```

若在操作过程中执行其他操作显得异常麻烦, 因此可以自定义管理器

```py
class UserManager(models.Manager):
    def add_user(self, name, pwd):
        # 可执行若干代码
        ...
        user = self.create(name = name, pwd = generate_password_hash(pwd))
        return user

    def get_user(self, name):
        # 可执行若干代码
        ...
        return self.get(name = name)

    def find_name(self, name):
        # 可执行若干代码
        ...
        return self.filter(name = name).exists()


class User(models.Model):
    name = models.CharField(max_length = 10)
    pwd = models.CharField(max_length = 300)
    
    # 赋值objects
    objects = UserManager()
```

对User类的相关操作可简化为

```py
User.objects.add_user(name, pwd)

User.objects.find_name(name)
```


### DRF


models.py

```py
import uuid as uuid
from werkzeug.security import generate_password_hash
from django.db import models


class User(models.Model):
    uuid = models.UUIDField(primary_key=True, auto_created=True, default=uuid.uuid4, editable=False)
    name = models.CharField(max_length=300)
    pwd = models.CharField(default=generate_password_hash('123456'), max_length=300)
    time = models.DateTimeField(auto_now_add=True)



from django.shortcuts import render
from rest_framework import generics
from rest_framework.viewsets import ModelViewSet
from .models import User
from .serializers import UserModelSerializer


class UserList(generics.ListCreateAPIView):
    """
        get:返回全部数据
        post:创建新数据
    """
    queryset = User.objects.all()
    serializer_class = UserModelSerializer


class UserDetail(generics.RetrieveUpdateDestroyAPIView):
    """
        get:返回指定数据
        put:更新数据
    """
    queryset = User.objects.all()
    serializer_class = UserModelSerializer
```

app/urls.py

```py
from .views import UserList, UserDetail
from rest_framework.routers import DefaultRouter
from django.urls import path

# 路由列表
urlpatterns = [
    path("user/", UserList.as_view(), name="user_list"), 
    path("user/<str:pk>", UserDetail.as_view(), name="user_detail")
]
```

urls.py

```py
from rest_framework import serializers
from app.models import User

class UserModelSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = "__all__"


from django.contrib import admin
from django.urls import path, include


urlpatterns = [
    path('admin/', admin.site.urls), 
    path('app/', include("app.urls")), 
]
```