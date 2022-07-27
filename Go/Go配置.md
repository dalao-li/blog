<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-10 22:42:49
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-27 21:57:23
-->

## Go配置


### 安装


#### Ubuntu

```sh
wget https://dl.google.com/go/go1.17.3.linux-amd64.tar.gz

sudo tar -xzf go1.17.3.linux-amd64.tar.gz -C /usr/local

export PATH=$PATH:/usr/local/go/bin
```

#### Arch

```
sudo pacman -S go
```


### 配置

#### 启用 Go Modules 功能

```sh
go env -w GO111MODULE=on
```


#### 配置 GOPROXY 环境变量

七牛 CDN

```sh
go env -w  GOPROXY=https://goproxy.cn,direct
```



### 清理缓存


```sh
go clean --modcache
```