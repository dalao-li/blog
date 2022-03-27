<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-12 01:44:11
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 11:18:35
-->


## run

```sh
docker run [参数] 镜像ID (命令)
```


### -itd

| 参数 | 含义                         |
| ---- | ---------------------------- |
| `-i` | 以交互模式运行容器           |
| `-t` | 为容器重新分配一个伪输入终端 |
| `-d` | 后台运行并返回容器ID         |


### -p

`-p 主机端口:容器端口` 指定端口映射

将本机7890端口映射到容器80端口

```sh
docker run -itd -p 7890:80 nginx
```

- `--expose=[]` 开放一个或一组端口


### -e

`-e 变量=值` 给容器设置环境变量

设置MySQL容器中root用户密码为123

```sh
docker run -itd -e MYSQL_ROOT_PASSWORD=123 mysql:5.6
```

给busybox容器设置环境变量STR_VEN=abcdefg

```
docker run -itd --name=box -e STR_VEN=abcdefg busybox
```
![](https://cdn.hurra.ltd/img/20220112045036.png)

- `--env-file=[]` 从指定文件读入环境变量


### --mount

`--mount` 挂载本地目录到容器中

若本地目录(必须是绝对路径)不存在会报错

```sh
--mount type=bind,source=[本地路径],target=[容器路径](权限)
```

将本地/src/app挂载到容器/root/app

```sh
docker run -itd --mount type=bind,source=/src/app,target=/root/app nginx:alpine
```

挂载主机目录的默认权限是`读写`，可增加 `readonly` 指定为只读

```sh
--mount type=bind,source=/src/app,target=/root/app,readonly
```

- `-v` 挂载本地目录到容器中，若本地目录不存在，会自动创建文件夹


### --net

`--net="bridge"` 指定容器网络连接类型

支持 bridge，host，none，container四种类型


### --link 

`--link=[]` 链接到另一个容器

从 Ubuntu 容器中访问 MySQL容器中的mysql服务

```sh
docker run -itd \
    --name mysql_server 
    -e MYSQL_ROOT_PASSWORD=123 \
    mysql:5.7
```

```sh
docker run -itd \
    --name ubuntu_test
    # 链接 MySQL 容器，db为别名
    --link mysql_server:db \
    ubuntu:18.04 \

docker exec -it ubuntu_test bash -c 'apt-get update && apt-get install -y mysql-client'

mysql -h db -u root -p123
```


### 问题

- 执行命令后容器停止

```sh
docke run -itd --name=box busybox mkdir test
```

此处本意为run时创建test目录，实际发现执行命令后即容器停止运行

原因为基于Docker原理，当run时执行的命令结束时，容器也会停止

运行下面命令是run执行sh解释权，容器会在后台一直运行

```
docker run -itd --name=box busybox sh
```

