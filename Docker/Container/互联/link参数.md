<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-09 00:06:17
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-15 23:17:17
-->

## --link 互联

```sh
docker pull busybox

# 建立名为 box_1 的容器
docker run -itd --name box_1 busybox /bin/sh

# 建立名为 box_2 的容器，link 到 box_1 容器
docker run -itd --name box_2 --link box_1 busybox /bin/sh

# 获取容器的 IP 地址
docker inspect box_1 | grep IPAddress
```

![](https://cdn.hurra.ltd/img/20200726113742.png)

使用 box_1 容器 ping box_2 容器

![](https://cdn.hurra.ltd/img/20200726114146.png)

![](https://cdn.hurra.ltd/img/20200726114219.png)

## 跨容器访问

建立一个 ubuntu 容器，使用--link 命令连接建立的 mysql 容器，实现从 ubuntu 容器中访问 mysql 服务

```sh
# 建立 MySQL 容器
docker run -itd --name mysql_server -e MYSQL_ROOT_PASSWORD=123 mysql:5.7

# 建立 ubuntu 容器，并与之前创建的 MySQL 容器作链接
docker run -itd --name ubuntu_demo --link mysql_server:db ubuntu
```

![](https://cdn.hurra.ltd/img/20200726152144.png)

```sh
# 进入 ubuntu 容器，安装 mysql-client
docker exec -it ubuntu_demo bash

apt-get update

apt-get install -y mysql-client
```

![](https://cdn.hurra.ltd/img/20200726152910.png)

```sh
# 登录 mysql 服务

# h 主机地址，db 使用--link 命令时为 mysql_server 设置的别名
# p 创建 mysql 容器时设置的密码
mysql -h db -u root -p123
```

![](https://cdn.hurra.ltd/img/20200726152540.png)