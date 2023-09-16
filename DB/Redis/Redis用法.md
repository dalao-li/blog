<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-24 15:25:28
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-19 14:04:13
-->

# Readis

## 命令

### 建立键

```sh
SET key redis
```

### 删除键

```sh
DEL key
```

### 检查key存在

```sh
EXISTS key
```

### key设置过期时间

```sh
EXPIRE key seconds
```

### 返回key剩余生存时间

```sh
TTL key
```

## 安全操作

### 设置密码

```sh
CONFIG set requirepass "密码"
```

### 查看密码

```sh
CONFIG get requirepass
```

## Docker部署

### 允许远程访问

- 新建redis.conf

```sh
# Turn off protection mode 
protected-mode no  

# password
requirepass 123456
```

- 拉取容器

```sh
docker run -itd                              \
    -p 6379:6379                             \
    -v $PWD/redis.conf:/etc/redis/redis.conf \
    --name redis-test                        \
    redis
```

```sh
docker run -itd -p 6379:6379 -v $PWD/redis.conf:/etc/redis/redis.conf --name redis-server redis 
```

### 连接

```sh
docker exec -it redis-test redis-cli
```

## GUI软件

```sh
sudo snap install redis-desktop-manager
```
