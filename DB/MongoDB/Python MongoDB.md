<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 19:54:50
-->

## 连接

```py
import pymongo

client = pymongo.MongoClient("mongodb://user_name:password@ip:port/")

db_list = client.list_database_names()

print(db_list)
```

![](https://cdn.hurra.ltd/img/20201014211648.png)

## 获取集合

```py
# 获取数据库
db = client[collect_name]

# 获取改数据库中所有集合
collect_list = db.list_collection_names()

print(collect_list)
```

![](https://cdn.hurra.ltd/img/20201014212147.png)


## 获取文档

```py
db = client[db_name]

# 获取集合
collect = db[collect_name]

for i in collect.find():
    ...
```

![](https://cdn.hurra.ltd/img/20201014213434.png)

- 按条件获取

find()函数里添加{key:value}对即可

例如获取 name 为 new_name2 的人员信息

```py
# 获取集合
collect = db['stu']

data = collect.find({"name":"new_name2"})[0]

print(data)
```

![](https://cdn.hurra.ltd/img/20201029161327.png)

## 插入文档

```py
import pymongo

client = pymongo.MongoClient("mongodb://admin:123456@192.168.0.110:27017/")
db = client['test']

# 获取集合
collect = db['stu']

# 单条插入
data = {"name":"new_name"，"num":"0-CVNMAS-123"，"age":19}
collect.insert_one(data)

# 多条插入
data_list = [
    {"name":"new_name2"，"num":"0-WER"，"age"，20}，
    {"name":"new_name3"，"num":"0-VBDS"，"age":19}，
    {"name":"new_name4"，"num":"0-2sdfWSW"，"age":19}
]
collect.insert_many(data_list)
for i in collect.find():
    print(i)
```

![](https://cdn.hurra.ltd/img/20201015093600.png)

![](https://cdn.hurra.ltd/img/20201015093938.png)


