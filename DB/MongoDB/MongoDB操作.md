## MongoDB


### 部署

- 创建容器
  
```sh
docker run -itd --name mongo -p 27017:27017 mongo --auth 

docker exec -it mongo mongo admin
```

![](https://cdn.hurra.ltd/img/20220112183733.png)

- 创建用户

创建一个名为 admin，密码为 123456 的用户

```sh
db.createUser({ user:'admin',pwd:'123456',roles:[{ role:'userAdminAnyDatabase',db:'admin'},"readWriteAnyDatabase"]})
```

![](https://cdn.hurra.ltd/img/20220112183857.png)

- 连接

```sh
db.auth('admin','123456')
```

![](https://cdn.hurra.ltd/img/20220112184110.png)


## 命令

### 数据库

```sh
use 数据库
```

创建 test 数据库，这里暂不会显示，因为其中还未插入数据

![](https://cdn.hurra.ltd/img/20220112184225.png)


### 集合

- 创建集合

```sh
db.createCollection("集合")
```

创建 stu 集合

![](https://cdn.hurra.ltd/img/20220112184407.png)


### 增加

- 插入数据

```sh
db.[集合].insert(JSON数据1,JSON数据2...)
```

向stu集合插入两条数据

```
db.stu.insert([{name:"Ling",age:20},{name:"Wang",age:22}])
```

![](https://cdn.hurra.ltd/img/20220112184807.png)


### 查询

- 全部查询

```sh
db.[集合].find()
```

- 格式化显示集合内所有文档

```sh
db.[集合].find().pretty()
```

![](https://cdn.hurra.ltd/img/20220112185029.png)

- 条件查询

```sh
db.[集合].find({key:value}).pretty()
```

查询 stu 集合中 name 为 Ling 的文档

```sh
db.stu.find({name:"Ling"}).pretty()
```

查询年龄大于等于 21 的文档

```sh
db.stu.find({age:{$gte:21}}).pretty()
```

条件查询表

| 操作       | 格式                 |
| ---------- | -------------------- |
| 等于       | {key:value}          |
| 小于       | {key:{`$lt`:value}}  |
| 小于或等于 | {key:{`$lte`:value}} |
| 大于       | {key:{`$gt`:value}}  |
| 大于或等于 | {key:{`$gte`:value}} |
| 不等于     | {key:{`$ne`:value}}  |


### 修改

```sh
db.[集合].update({key1:value},{$set:{key2:new_value}})
```

将 name 为 Ling 的文档中 age 值改为 30


```sh
db.stu.update({name:"Ling"},{$set:{age:30}})
```
![](https://cdn.hurra.ltd/img/20220112185815.png)


### 删除

```sh
db.[集合].remove({key:value})
```

删除 name=Ling 的文档

```sh
db.stu.remove({name:"Ling"})
```

## Python交互


### 连接

```sh
pymongo.MongoClient("mongodb://用户名:密码@IP:端口/")
```

```py
import pymongo

client = pymongo.MongoClient("mongodb://admin:123456@192.168.1.36:27017/")

dbs = client.list_database_names()

# ['admin', 'config', 'local', 'test']
print(dbs)
```


### 获取集合

```py
# 获取test数据库中所有集合
collects = client['test'].list_collection_names()

# ['stu']
print(collects)
```


### 获取文档

```py
# 获取test数据库的stu集合
collect = client['test']['stu']

# 遍历集合输出文档
for i in collect.find():
    print(i)

# {'_id': ObjectId('61deb1b9e67fb54f984ccf8f'), 'name': 'Ling', 'age': 30.0}
# {'_id': ObjectId('61deb1b9e67fb54f984ccf90'), 'name': 'Wang', 'age': 22.0}
```

- 按条件获取

```sh
集合.find(key:value)
```

```py
collect = client['test']['stu']

# 获取 name 为 Ling 的人员信息
data = collect.find({"name":"Ling"})[0]

# {'_id': ObjectId('61deb1b9e67fb54f984ccf8f'), 'name': 'Ling', 'age': 30.0}
print(data)
```


### 插入文档

- 单条插入

```py
insert_one(JSON数据)
```

- 多条插入

```py
insert_many(JSON数据1,JSON数据2...)
```

```py
...
collect = client['test']['stu']

collect.insert_one({"name":"new_name","age":19})

collect.insert_many([
    {"name":"new_name2","age"，20},
    {"name":"new_name3","age":19},
    {"name":"new_name4","age":19}
])

for i in collect.find():
    print(i)

# {'_id': ObjectId('61deb1b9e67fb54f984ccf8f'), 'name': 'Ling', 'age': 30.0}
# {'_id': ObjectId('61deb1b9e67fb54f984ccf90'), 'name': 'Wang', 'age': 22.0}
# {'_id': ObjectId('61deb97e09f80dafa132ce8c'), 'name': 'new_name', 'age': 19}
# {'_id': ObjectId('61deb97e09f80dafa132ce8d'), 'name': 'new_name2', 'age': 20}
# {'_id': ObjectId('61deb97e09f80dafa132ce8e'), 'name': 'new_name3', 'age': 19}
# {'_id': ObjectId('61deb97e09f80dafa132ce8f'), 'name': 'new_name4', 'age': 19}
```




