<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-08 00:03:57
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-26 00:37:22
-->

## 安装

```sh
sudo wget https://nodejs.org/dist/v16.13.1/node-v16.13.1-linux-x64.tar.xz

sudo tar -xJf node-v16.13.1-linux-x64.tar.xz -C /opt

sudo ln -s /opt/node-v16.13.1-linux-x64/bin/npm /usr/local/bin/npm

sudo ln -s /opt/node-v16.13.1-linux-x64/bin/node /usr/local/bin/node
```

## 换源

```sh
sudo npm config set registry https://registry.npm.taobao.org

source ~/.bashrc
```

## 卸载

```sh
sudo rm -rf /usr/local/lib/node_modules

sudo rm -rf ~/.npm

sudo apt-get remove nodejs npm
```