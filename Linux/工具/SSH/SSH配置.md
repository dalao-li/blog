<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-14 13:31:07
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-01 22:05:46
-->

## 1 SSH


### 1.1 命令

- 连接

```sh
ssh 用户名@IP地址 (-p 端口号)
```

连接192.168.1.1的dalao用户，端口号默认为20

```sh 
ssh dalao@192.168.1.1
```

- 清除主机密钥

```sh
ssh-keygen -R [远程主机IP]
``` 


### 1.2 免密

- 手动复制

将本地`id_rsa.pub` 复制到远程主机`.ssh/authorized_keys`里


- 命令复制

```sh
ssh-copy-id -i ~/.ssh/id_rsa.pub [远程用户]@[远程主机IP]
```

![](https://cdn.hurra.ltd/img/20211229213337.png)


### 1.3 .ssh目录

在根目录(/root/或者/home/用户名)下生成 .ssh目录

```sh
ssh-keygen -t rsa
```

![](https://cdn.hurra.ltd/img/20210312104415.png)

| 文件            | 作用                     |
| --------------- | ------------------------ |
| authorized_keys | 存储其他主机的公钥       |
| id_rsa          | 本机私钥文件             |
| id_rsa.pub      | 本机公钥文件             |
| know_hosts      | 存储已认证主机的host key |


### 1.4 配置文件

```sh
/etc/ssh/sshd_condfig
```


```sh
# 允许密钥登录
RSAAuthentication yes

# 允许公钥验证 
PubkeyAuthentication yes

# 禁止密码登录
PasswordAuthentication no
```


### 1.5 监控

/etc/ssh/目录下新建sshrc文件

```sh
#!/bin/bash

# 获取登录者的用户名
user=${USER}

# 获取登录者的IP地址
ip=${SSH_CLIENT%% *}

# 获取登录的时间
time=${date +%F%t%k:%M}

# 服务器的IP地址
server=${ifconfig wlp2s0 | sed -n '2p' | awk '{print $2}'}

echo ${user} ${ip} ${time} ${server}
```


### 1.6 Web工具

[Github 地址](https://github.com/huashengdun/webssh)


```sh
pip3 install webssh
```

- 直接运行wssh，使用默认8888端口

```sh
wssh
```

- 绑定IP地址和端口启动

```sh
wssh --address='IP地址' --port=端口
```