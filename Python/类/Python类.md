<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-01 12:29:16
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-10 00:49:15
-->

## 定义

```py
class Stu:
    def __init__(self, num, name, age):
        self.num = num
        self.name = name
        self.age = age
```

self代表类的实例，而非类

类的方法与普通的函数的区别为它们必须有一个额外的首参数名称self

## 方法

```py
class Person:
    def __init__(self, name):
        self.name = name

    # get方法
    @property
    def name(self):
        return self._name

    # set方法
    @name.setter
        def name(self, value):
            if not isinstance(value, str):
                raise TypeError('Expected a string')
            self._name = value
```

## 获值

```py
class A(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

a = A('lili'， 23)

# {'name': 'lili'， 'age': 23}
print(a.__dict__)
```

## 赋值

```py
class Person:
    # _obj为字典
    def __init__(self, _obj):
        self.__dict__.update(_obj)
```