<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2023-03-13 00:50:11
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-03-13 00:56:16
-->

# LLVM 环境搭建

> llvm版本 15.7

[LLVM概述——介绍与安装](https://zhuanlan.zhihu.com/p/102028114)

## Windows


## Linux


### Ubuntu

- 下载源码

```sh
sudo wget https://github.com/llvm/llvm-project/archive/refs/tags/llvmorg-15.0.7.tar.gz
```

- 解压源码

```sh 
sudo tar xvf llvm-project-llvmorg-15.0.7
```

- 建立安装目录

```SH
sudo mkdir -p /usr/local/llvm
```

- 生成makefile

```sh
sudo cmake -S . -B build -G "Unix Makefiles" -DLLVM_ENABLE_PROJECTS="clang" -DLLVM_TARGETS_TO_BUILD=X86 -DCMAKE_BUILD_TYPE="Release" -DLLVM_INCLUDE_TESTS=OFF -DCMAKE_INSTALL_PREFIX="/usr/local/llvm"
```

- 编译

```sh
sudo cmake --build build -j ${nproc}
```

- 安装

```sh
sudo cmake --install build
```