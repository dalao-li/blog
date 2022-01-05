<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 23:46:06
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-06 00:48:20
-->

## Redis

- GUI软件
```sh
sudo snap install redis-desktop-manager
```

## Docker部署

- 允许远程访问

新建redis.conf文件

```sh
# Turn off protection mode 
protected-mode no  

# password
requirepass 123456   
```

- 拉取容器

```sh
# 使用刚才创建的redis.conf
docker run -itd \
    -p 6379:6379 \
    -v $PWD/redis.conf:/etc/redis/redis.conf \
    --name redis-test \
    redis 
```

```sh
docker run -itd -p 6379:6379 -v $PWD/redis.conf:/etc/redis/redis.conf --name redis-server redis 
```

- 连接

```sh
docker exec -it redis-test redis-cli
```