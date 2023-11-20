<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-11-18 21:05:22
-->

# Docker部署MySQL

## 指令

```sh
docker run -itd                  \
    --name=mysql                 \
    -p 3306:3306                 \
    -v $PWD/mysql:/var/lib/mysql \
    # 建立普通用户
    -e MYSQL_USER=dalao          \
    # 设置用户密码
    -e MYSQL_PASSWORD=456        \
    # 设置root用户密码
    -e MYSQL_ROOT_PASSWORD=123   \
    mysql:5.7
```

## 远程连接

### 登录

```sql
mysql -u 用户名 -p
```

### 允许远程登录

```sql
grant all privileges on *.* to '用户名'@'%' identified by '密码';

flush privileges;
```

![](https://cdn.hurra.ltd/img/20211227135258.png)

目录映射到宿主机下

![](https://cdn.hurra.ltd/img/20211227135502.png)

## 常见问题

### 中文乱码

```sh
echo "character-set-server=utf8" >> /etc/mysql/mysql.conf.d/mysqld.cnf

service mysql restart
```

### 降低占用内存

```sh
cat >> /etc/mysql/mysql.conf.d/mysqld.cnf <<EOF
performance_schema_max_table_instances=400

table_definition_cache=400

table_open_cache=256
EOF
```

```sh
service mysql restart
```