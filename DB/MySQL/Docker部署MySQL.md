<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-20 13:40:16
-->

## Docker部署MySQL

```sh
docker run -itd \
    --name=mysql \
    # 映射端口
    -p 3306:3306 \
    # 挂载目录
    -v $PWD/mysql:/var/lib/mysql \
    # 建立普通用户dalao
    -e MYSQL_USER=dalao \
    # 设置dalao用户密码
    -e MYSQL_PASSWORD=456 \
    # 设置root用户密码
    -e MYSQL_ROOT_PASSWORD=123 \
    mysql:5.7
```

```sh
docker run -itd --name=mysql -p 3306:3306 -v $PWD/mysql:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=123  mysql:5.7
```


### 远程连接

- 登录

```sh
mysql -u 用户名 -p
```

- 允许远程登录

```sh
grant all privileges on *.* to '用户名'@'%' identified by '密码';

flush privileges;
```

![](https://cdn.hurra.ltd/img/20211227135258.png)

目录映射到宿主机下

![](https://cdn.hurra.ltd/img/20211227135502.png)


### 常见问题

- 中文乱码

```sh
echo "character-set-server=utf8" >> /etc/mysql/mysql.conf.d/mysqld.cnf

service mysql restart
```

- 降低占用内存

```sh
cat >> /etc/mysql/mysql.conf.d/mysqld.cnf <<EOF
performance_schema_max_table_instances=400

table_definition_cache=400

table_open_cache=256
EOF

service mysql restart
```




