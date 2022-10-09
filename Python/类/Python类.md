<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-02-01 12:29:16
 * @LastEditors: daLao
 * @LastEditTime: 2022-10-09 22:23:21
-->

## 类


### 定义


```py
class Stu:
    def __init__(self, num: str, name: str, age: str) -> None:
        self._num = num
        self._name = name
        self._age = age
```

self代表类的实例, 而非类

类的方法与普通的函数的区别为它们必须有一个额外的首参数名称self



### 方法

```py
class Person:
    def __init__(self, name: str) -> None:
        self._name = name

    # get方法
    @property
    def name(self) -> None:
        return self._name

    # set方法
    @name.setter
    def name(self, value: str) -> None:
        if not isinstance(value, str):
            raise TypeError('Expected a string')
        self._name = value
```



### 操作


#### 获值

```py
class Person(object):
    def __init__(self, name: str, age: str) -> None:
        self.name = name
        self.age = age

p = Person('lili', 23)

# {'name': 'lili', 'age': 23}
print(p.__dict__)
```


#### 赋值

```py
class Person:
    # _obj为字典
    def __init__(self, _obj) -> None:
        self.__dict__.update(_obj)
```