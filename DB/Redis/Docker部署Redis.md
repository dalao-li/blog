<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 23:46:06
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-25 22:33:55
-->

```sh
# GUI管理软件
sudo snap install redis-desktop-manager
```

## 允许远程访问

新建redis.conf

```sh
# Turn off protection mode 
protected-mode no  

# password
requirepass 123456   
```

```sh
# 使用刚才创建的redis.conf
docker run -itd \
    -p 6379:6379 \
    -v $PWD/redis.conf:/etc/redis/redis.conf \
    --name redis-test \
    redis 
    
# docker run -itd -p 6379:6379 -v $PWD/redis.conf:/etc/redis/redis.conf --name redis-server redis 

# 连接
docker exec -it redis-test redis-cli
```