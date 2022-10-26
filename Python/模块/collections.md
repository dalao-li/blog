<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-10-26 19:54:27
 * @LastEditors: daLao
 * @LastEditTime: 2022-10-26 22:04:26
-->

## collections 模块

collections 是 python 的内置模块, 提供了很多方便且高性能的关于集合的操作, 掌握这些知识有助于提高代码的性能和可读性


### namedtuple 功能

namedtuple() 返回一个新的元组子类

其规定元组的元素的个数, 同时除了使用下标获取元素之外, 还可以通过属性直接获取

```py
from collections import namedtuple

User = namedtuple("User",["name", "age", "weight"])

user = User("admin", "20", "60")

name, age, weight = user

# admin
print(user[0])

# admin 20 60
print(name, age, weight)

# admin 20 60
print(user.name, user.age, user.weight)
```


namedtuple() 相当于直接定义了一个新的类, 其比直接定义 class 的方式省很多空间, 同时其返回值是一个 tuple, 支持 tuple 的各种操作


- 将序列直接转换为新的 tuple 对象

```py
user = ["root", 32, 65]
user = User._make(user) 

# User(name='root', age=32, weight=65)
print(user) 
```


- 返回一个 dict

```py
user = User("admin", 20, 60)

# OrderedDict([('name', 'admin'), ('age', 20), ('weight', 60)])
print(user._asdict()) 
```


## ChainMap

ChainMap() 可以将多个字典集合到一个字典中去, 对外提供一个统一的视图

该操作并是不将所有字典做了一次拷贝, 实际上是在多个字典的上层又进行了一次封装

```py
from collections import ChainMap

user1 = {"name":"admin", "age":"20"}
user2 = {"name":"root", "weight": 65}

users = ChainMap(user1, user2)

# [{'name': 'admin', 'age': '20'}, {'name': 'root', 'weight': 65}]
print(users.maps)

users.maps[0]["name"] = "tiger"

# [{'name': 'tiger', 'age': '20'}, {'name': 'root', 'weight': 65}]
print(users.maps)

# name tiger
# weight 65
# age 20
for key, value in users.items():
    print(key, value)
```


如果 ChainMap() 中的多个字典有重复 key, 查看的时候可以看到所有的 key, 但遍历的时候却只会遍历 key 第一次出现的位置, 其余的忽略

同时可通过返回的新的视图来更新原来的的字典数据, 进一步验证了该操作不是做的拷贝, 而是直接指向原字典, 


## deque 功能

dqueue指 double-ended queue, 是一种类似列表(list)的容器, 实现了在两端快速添加(append)和弹出(pop)操作, 大大加快了遍历速度

```py
from collections import deque

q = deque([1, 2, 3])

q.append('4')

q.appendleft('0')

# deque(['0', 1, 2, 3, '4'])
print(q)

# 0
print(q.popleft())
```


## Counter

Counter 可以简单理解为一个计数器, 可以统计每个元素出现的次数, 同样 Counter() 是需要接受一个可迭代的对象的, 

```py
from collections import Counter

animals = ["cat", "dog", "cat", "bird", "horse", "tiger", "horse", "cat"]
animals_counter = Counter(animals)

# Counter({'cat': 3, 'horse': 2, 'dog': 1, 'bird': 1, 'tiger': 1}) 
print(animals_counter)

# [('cat', 3), ('horse', 2)]
print(animals_counter.most_common(2))
```
