<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-06 16:15:16
-->

# MySQL 授权

## 创建

```sql
create user '用户名'@'host' identified by '密码';
```

| host取值  | 含义             |
| --------- | ---------------- |
| localhost | 本地登录用户     |
| ip        | 允许某个 ip 登录 |
| %         | 允许所有 ip 登录 |

- 创建用户dalao, 密码123456

```sql
create user 'dalao'@'%' identified by '123456'
```

- 查看信息

```sql
select host, user, authentication_string from mysql.user;
```

![](https://cdn.hurra.ltd/img/20200516001828.png)

![](https://cdn.hurra.ltd/img/20200516001919.png)

## 查看

- 查看所有用户权限

```sql
show grants;
```

- 查看指定用户权限

```sql
show grants for'用户名'@'%';
```

## 授权

- 授权仅root用户有权操作

```sql
grant all privileges on *.* to '用户名'@'%' identified by '密码';
```

| 参数           | 含义                                                         |
| -------------- | ------------------------------------------------------------ |
| all privileges | 所有权限, 包括`SELECT`, `UPDATE`, `CREATE`, `DELETE`, `DROP` |
| ON             | 指定权限针对哪些库和表                                       |
| 前一个 `*`     | 指定数据库, `*`表示全部                                      |
| 后一个 `*`     | 指定表, `*`表示全部                                          |
| identified by  | 指定用户登录密码, 可省略                                     |
| TO             | 表示将权限赋予某个用户                                       |
| @              | 限制地址, 可以是 IP、域名与%(表示任何IP)                     |

- 授予dalao用户对所有数据库所有表的所有操作权限

![](https://cdn.hurra.ltd/img/20200516003253.png)

![](https://cdn.hurra.ltd/img/20200516003557.png)

- 新建用户 user_test, 仅授予 SELECT 权限

```sql
create user 'user_test'@'%' identified by '999';

grant select on *.* to 'user_test'@'%';
```

![](https://cdn.hurra.ltd/img/20200516004045.png)

使用 user_test 登录, 尝试创建数据库 test_db, 可以发现被拒绝了

```sql
create database test_db;
```

![](https://cdn.hurra.ltd/img/20200516004259.png)

使用 user_test 用户, 尝试查询

![](https://cdn.hurra.ltd/img/20200516004447.png)

- 新建用户 test_4, 授予 select create权限

```sql
create user 'test_4'@'%' identified by '999';

grant select, create on *.* to 'test_4'@'%';
```

![](https://cdn.hurra.ltd/img/20200516084018.png)

使用 test_4 登录, 尝试创建数据库 test_db

```sql
create database test_db;
```

![](https://cdn.hurra.ltd/img/20200516084301.png)