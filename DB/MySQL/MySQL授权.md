<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 20:25:59
-->

## 授权

```sql
CREATE user '用户名'@'host' identified BY '密码';
```
| host值    | 含义                 |
| --------- | -------------------- |
| localhost | 本地登录用户         |
| ip        | 运行某个 ip 地址登录 |
| %         | 为允许外网 ip 登录   |

- 创建用户 

```sql
CREATE user 'dalao'@'%' identified BY '123456'
```

- 查看用户

```sql
SELECT host,user,authentication_string FROM mysql.user;
```

![](https://cdn.hurra.ltd/img/20200516001828.png)

登录MySQL

```sql
mysql -u 用户名 -p
```

![](https://cdn.hurra.ltd/img/20200516001919.png)

授权操作只有root用户才有权限操作

```sql
GRANT ALL PRIVILEGES ON *.* TO '用户名'@'%' identified by '密码';
```


| 参数           | 含义                                                         |
| -------------- | ------------------------------------------------------------ |
| ALL PRIVILEGES | 所有权限，包括`SELECT`，`UPDATE`，`CREATE`，`DELETE`，`DROP` |
| ON             | 指定权限针对哪些库和表                                       |
| 前一个 `*`     | 指定数据库名                                                 |
| 后一个 `*`     | 指定表名                                                     |
| identified by  | 指定用户登录密码，可省略                                     |
| TO             | 表示将权限赋予某个用户                                       |
| @              | 限制地址，可以是 IP、域名与%(表示任何IP)                     |

![](https://cdn.hurra.ltd/img/20200516003253.png)

授予dalao用户对所有数据库所有表的所有操作权限

- 查看所有用户权限

```sql
SHOW GRANT;
```

- 查看指定用户权限

```sql
SHOW GRANT FOR '用户名'@'%';
```

![](https://cdn.hurra.ltd/img/20200516003557.png)

- 新建用户 user_test，仅授予 SELECT 权限

```sql
CREATE USER 'user_test'@'%' identified BY '999';

GRANT SELECT ON *.* TO 'user_test'@'%';
```

![](https://cdn.hurra.ltd/img/20200516004045.png)

- 建立数据库

```sql
# 使用 user_test 登录，尝试创建数据库 test_db，可以发现被拒绝了
CREATE DATABASE test_db;
```

![](https://cdn.hurra.ltd/img/20200516004259.png)

使用 user_test 用户，尝试查询

![](https://cdn.hurra.ltd/img/20200516004447.png)


```sql
# 新建用户 test_4，授予 SELECT，CREATE 权限
CREATE USER 'test_4'@'%' identified BY '999';

GRANT SELECT，CREATE ON *.* TO 'test_4'@'%';
```

![](https://cdn.hurra.ltd/img/20200516084018.png)

```sql
# 使用 test_4 登录，尝试创建数据库 test_db
CREATE DATABASE test_db;
```

![](https://cdn.hurra.ltd/img/20200516084301.png)