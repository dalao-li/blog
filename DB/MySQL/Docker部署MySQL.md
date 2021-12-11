<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-10 23:07:59
-->

## 映射目录

```sh
docker run -itd \
    --name=mysql \
    -p 3306:3306 \
    -v $PWD/mysql:/var/lib/mysql \
    -e MYSQL_ROOT_PASSWORD=123  mysql:5.7

# docker run -itd --name=mysql -p 3306:3306 -v $PWD/mysql:/var/lib/mysql -e MYSQL_ROOT_PASSWORD= 123  mysql:5.7
```

![](https://cdn.hurra.ltd/img/20200515202929.png)


## 远程连接

```sh
# 进入容器登录
mysql -u root -p

# 允许远程登录
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' IDENTIFIED BY '刚设置的MYSQL密码';

flush privileges;
```

![](https://cdn.hurra.ltd/img/20200515202734.png)

新建一个数据库 Test

![](https://cdn.hurra.ltd/img/20200515234119.png)

如果设置了目录映射的话就能在宿主机中看见

![](https://cdn.hurra.ltd/img/20200515234144.png)

## 常见问题

- 中文乱码

```sh
# 容器内执行
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

# 重启容器或者重启 MySQL 服务
```




