## 部署

- 创建容器,--auth需要密码才能访问容器服务
  
```sh
docker run -itd --name mongo -p 27017:27017 mongo --auth 

docker exec -it mongo mongo admin
```

- 创建一个名为 admin,密码为 123456 的用户

```sh
db.createUser({ user:'admin',pwd:'123456',roles:[{ role:'userAdminAnyDatabase',db:'admin'},"readWriteAnyDatabase"]})
```

- 连接

```sh
db.auth('admin', '123456')
```

![](https://cdn.hurra.ltd/img/20201014175200.png)


## 创建DB

```sh
use 数据库名
```

创建 test 数据库

![](https://cdn.hurra.ltd/img/20201014142358.png)

这里暂不会显示新建的数据库,因为其中还未插入数据


## 创建集合

```sh
db.createCollection("集合名")
```

创建 stu 集合

![](https://cdn.hurra.ltd/img/20201014171656.png)


## 增加

- 单条插入

```sh
db.collect_name.insert(JSON数据)
```

向 stu 集合中插入数据

![](https://cdn.hurra.ltd/img/20201014174718.png)

- 多条插入

```sh
db.collect_name.insert(JSON数据1,JSON数据2,JSON数据3.....)
```

![](https://cdn.hurra.ltd/img/20201014175739.png)

## 查询

- 全部查询

显示集合内所有文档

```sh
db.[collect_name].find()
```

例，显示 stu 集合内所有数据

![](https://cdn.hurra.ltd/img/20201014174834.png)

格式化显示集合内所有文档

```sh
db.[collect_name].find().pretty()
```

![](https://cdn.hurra.ltd/img/20201014180104.png)

- 条件查询

```sh
db.[collec_name].find({key:value}).pretty()
```

例，查询 stu 集合中 name 为 LILI 的文档

![](https://cdn.hurra.ltd/img/20201014190333.png)

例，查询年龄大于等于 19 的文档

![](https://cdn.hurra.ltd/img/20201014191820.png)

条件查询语言表

| 操作       | 格式                 |
| ---------- | -------------------- |
| 等于       | {key:value}          |
| 小于       | {key:{`$lt`:value}}  |
| 小于或等于 | {key:{`$lte`:value}} |
| 大于       | {key:{`$gt`:value}}  |
| 大于或等于 | {key:{`$gte`:value}} |
| 不等于     | {key:{`$ne`:value}}  |

## 改

- 修改文档

```sh
db.[collect_name].update({key1:value},{$set:{key2:new_value}})
```

例，将 name 为 LILI 的文档中 age 值改为 22

![](https://cdn.hurra.ltd/img/20201014195214.png)


## 删

```sh
db.[collect_name].remove({key:value})
```

删除 name=LILI 的文档

![](https://cdn.hurra.ltd/img/20201014204226.png)


