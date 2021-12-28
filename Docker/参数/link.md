<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-09 00:06:17
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-29 00:03:47
-->

## --link 互联

```sh
docker pull busybox
```

建立box_1

```sh
docker run -itd --name box_1 busybox /bin/sh
```

建立box_2，link 到 box_1

```sh
docker run -itd --name box_2 --link box_1 busybox /bin/sh
```

获取容器的 IP 地址

```sh
docker inspect box_1 | grep IPAddress
```

![](https://cdn.hurra.ltd/img/20211228230743.png)

使用 box_1 容器 ping box_2 容器

![](https://cdn.hurra.ltd/img/20211228230845.png)


## 跨容器访问

建立ubuntu 容器，使用`--link` 连接建立的 mysql 容器，实现从 ubuntu 容器中访问 mysql 服务

建立 MySQL 容器

```sh
docker run -itd --name mysql_server -e MYSQL_ROOT_PASSWORD=123 mysql:5.7
```

建立 ubuntu 容器，链接 MySQL 容器

```sh
docker run -itd --name ubuntu --link mysql_server:db ubuntu
```

ubuntu 容器，安装 mysql-client

```sh
docker exec -it ubuntu apt-get update

docker exec -it ubuntu apt-get install -y mysql-client
```

登录 mysql 服务

```sh
# -h 主机地址
# db 为 mysql_server 设置的别名
# -p 创建 mysql 容器时设置的密码
mysql -h db -u root -p123
```

![](https://cdn.hurra.ltd/img/20211228235758.png)