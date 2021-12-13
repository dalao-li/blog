<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-01 12:29:16
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 20:27:11
-->

## 类定义

```py
class Stu:
    def __init__(self，num，name，age):
        self.num = num
        self.name = name
        self.age = age
```

self代表类的实例，而非类，类的方法与普通的函数只有一个特别的区别——它们必须有一个额外的第一个参数名称，按照惯例它的名称是 self

## 继承

```py
class People:
    def __init__(self，name，age):
        self.name = name
        self.age = age
    def speak(self):
        print(self.name，self.age)


class Student(People):
    def __init__(self，name，age，num):
        People.__init__(self，name，age)
        self.num = num
    
    def speak(self):
        print(self.name，self.age，self.num)
```

## 获取类值

```py
class A(object):
    def __init__(self， name， age):
        self.name = name
        self.age = age

a = A('lili'， 23)

# {'name': 'lili'， 'age': 23}
print(a.__dict__)
```

## 给类赋值

```py
class Person:
    # _obj为字典
    def __init__(self，_obj):
        self.__dict__.update(_obj)
```