<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-05-09 17:35:26
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-16 15:03:34
-->

## DRF

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
from .views import UserList，UserDetail
from rest_framework.routers import DefaultRouter
from django.urls import path

# 路由列表
urlpatterns = [
    path("user/"，UserList.as_view()，name="user_list")，
    path("user/<str:pk>"，UserDetail.as_view()，name="user_detail")
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
    path('admin/', admin.site.urls)，
    path('app/', include("app.urls"))，
]
```

