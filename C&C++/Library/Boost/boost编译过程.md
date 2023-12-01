<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao_li
 * @Email: dalao_li@163.com
 * @Date: 2023-09-16 17:10:52
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-09-17 12:08:50
-->

# boost编译过程

## 下载boost源码

[boost开源镜像站](https://mirrors.aliyun.com/blfs/conglomeration/boost/)

下载指定版本源码, 此处以boost_1_80_0.tar.bz2为例

### 解压

```sh
sudo tar -jxvf boost_1_80_0.tar.bz2
```

## 编译安装

```sh
cd boost_1_80_0
```

使用自带脚本, 生成b2引擎

```sh
sudo ./bootstrap.sh
```

使用b2引擎编译

```sh
sudo ./b2 --buildtype=complete install
```

## 测试

```c++
// test.cpp
#include <iostream>
#include <boost/version.hpp>

int main() {
    std::cout << "Boost 版本" << BOOST_VERSION << std::endl;
    return 0;
}
```

编译验证

```sh
g++ test.cpp -o test

# Boost 版本108000
./test
```

## 参考

- [使用Docker搭建C++ Boost开发环境](https://bryantchang.github.io/2019/02/25/docker-boost/)
