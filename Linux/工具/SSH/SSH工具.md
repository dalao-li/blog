<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-06 19:15:52
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-09 20:54:15
-->

## 监控

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

## Web工具

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