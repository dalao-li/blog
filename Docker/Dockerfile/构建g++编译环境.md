<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2023-02-07 00:12:47
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-09-23 13:23:00
-->

# 搭建g++编译环境

## Dockerfile

```dockerfile
from alpine as builder

label dalao <dalao_li@163.com>

workdir /

run sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories && \
    apk add g++
```


## 构建

```sh
docker build -t gpp:v1 .
```

![](https://cdn.hurra.ltd/img/20230207002040.png)