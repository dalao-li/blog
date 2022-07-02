<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-12 04:30:33
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-03 19:54:15
-->


## exec

容器执行命令

```sh
docker exec [参数] 镜像ID 命令
```

| 参数 | 含义                        |
| ---- | --------------------------- |
| `-i` | 即使没有附加也保持STDIN打开 |
| `-t` | 分配一个伪终端              |
| `-d` | 分离模式,在后台运行         |



### 单指令

```sh
docker exec [参数] 镜像ID 命令
```

busybox容器创建目录

```sh
docker run -itd --name=box busybox 

docker exec -it box mkdir test
```
![](https://cdn.hurra.ltd/img/20220112043735.png)



### 多指令

```sh
docker exec 容器ID [shell解释器] -c '命令1 && 命令2'
```

ubuntu安装mysql-clinet

```sh
docker run -itd --name=ubuntu_test ubuntu:18.04

docker exec -it ubuntu_test bash -c 'apt-get update && apt-get install -y mysql-client'
```
