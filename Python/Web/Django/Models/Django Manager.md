<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 21:43:48
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-10 00:58:04
-->

## Django Manager

```py
class User(models.Model):
    name = models.CharField(max_length = 10)
    pwd = models.CharField(max_length = 300)
```

此时对数据库进行操作需通过，

```py
User.objects.create(name = name, pwd = pwd)

User.objects.filter(name = name)

...
```

若想在操作过程中执行其他操作，则显得异常麻烦，因此可以自定义管理器

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
    name = models.CharField(max_length=10)
    pwd = models.CharField(max_length=300)
    
    # 赋值objects
    objects = UserManager()
```

这样,对User类的相关操作可简化为

```py
User.objects.add_user(name, pwd)

User.objects.find_name(name)
```
