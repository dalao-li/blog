<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2023-02-07 00:12:47
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-02-07 00:22:38
-->

## 选择镜像

```c
alpine:latest
```

### 示例

#### 源文件

- c++

Main.cpp

```c++
#include <iostream>

int main(void) {
    std::cout << "Hello World!" << std::endl;

    return 0;
}
```

- Dockerfile

```dockerfile
FROM alpine AS builder

LABEL li <dalao_li@163.com>

WORKDIR /code/

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories

RUN apk add g++

COPY . .

RUN g++ -static Main.cpp -o Main
```


#### 编译

```
docker build -t gpp:v1 .
```

![](https://cdn.hurra.ltd/img/20230207002040.png)



#### 运行

![](https://cdn.hurra.ltd/img/20230207002122.png)

从容器中拷贝出可执行文件Main并执行

![](https://cdn.hurra.ltd/img/20230207002230.png)

