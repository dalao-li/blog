<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-10 22:42:49
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-27 20:09:03
-->

## 安装

```sh
# 下载安装
wget https://dl.google.com/go/go1.17.3.linux-amd64.tar.gz

sudo tar -xzf go1.17.3.linux-amd64.tar.gz -C /usr/local

export PATH=$PATH:/usr/local/go/bin

# 启用 Go Modules 功能
go env -w GO111MODULE=on

# 配置 GOPROXY 环境变量，七牛 CDN
go env -w  GOPROXY=https://goproxy.cn,direct
```

## 清理缓存

```sh
go clean --modcache
```