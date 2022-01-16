<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-12 04:30:33
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-16 12:56:36
-->


## exec

让容器执行命令

```
docker exec [参数] 镜像ID 命令
```

### -itd

- `-i` 即使没有附加也保持STDIN 打开

- `-t` 分配一个伪终端
  
- `-d` 分离模式: 在后台运行


### 命令

- 执行单条指令

busybox容器创建目录

```sh
docker run -itd --name=box busybox 

docker exec -it box mkdir test
```
![](https://cdn.hurra.ltd/img/20220112043735.png)

- 执行多条指令

`docker exec 容器ID  sh -c '命令1 && 命令2'`

ubuntu安装mysql-clinet

```sh
docker run -itd --name=ubuntu_test ubuntu:18.04

docker exec -it ubuntu_test bash -c 'apt-get update && apt-get install -y mysql-client'
```