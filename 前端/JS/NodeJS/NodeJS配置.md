<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-12-08 00:03:57
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-05 02:03:01
-->

# NodeJS


## 安装

- Ubuntu

```sh
sudo wget https://nodejs.org/dist/v16.13.1/node-v16.13.1-linux-x64.tar.xz

sudo tar -xJf node-v16.13.1-linux-x64.tar.xz -C /opt

sudo ln -s /opt/node-v16.13.1-linux-x64/bin/npm /usr/local/bin/npm

sudo ln -s /opt/node-v16.13.1-linux-x64/bin/node /usr/local/bin/node
```

- Arch

```sh
sudo pacman -S nodejs npm
```


## 换源

```sh
npm config set registry http://mirrors.cloud.tencent.com/npm/
```

- 验证

```sh
# 如果返回http://mirrors.cloud.tencent.com/npm/, 说明镜像配置成功
npm config get registry
```


## 卸载

- Ubuntu

```sh
sudo rm -rf /usr/local/lib/node_modules

sudo rm -rf ~/.npm

sudo apt-get remove nodejs npm
```

- Arch

```sh
sudo pacman -R nodejs npm
```