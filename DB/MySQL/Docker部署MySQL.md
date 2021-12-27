<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-27 13:55:08
-->

## 映射目录

```sh
docker run -itd \
    --name=mysql \
    -p 3306:3306 \
    -v $PWD/mysql:/var/lib/mysql \
    -e MYSQL_ROOT_PASSWORD=123  mysql:5.7

# docker run -itd --name=mysql -p 3306:3306 -v $PWD/mysql:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=123  mysql:5.7
```

## 远程连接

```sh
# 进入容器登录
mysql -u root -p

# 允许远程登录
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '密码';

flush privileges;
```

![](https://cdn.hurra.ltd/img/20211227135258.png)

目录映射

![](https://cdn.hurra.ltd/img/20211227135502.png)

## 常见问题

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
```




