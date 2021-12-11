<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-06 19:15:52
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-06 19:53:07
-->

/etc/ssh/目录下新建sshrc文件

```sh
#!/bin/bash

#获取登录者的用户名
user=${USER}

#获取登录者的IP地址
ip=${SSH_CLIENT%% *}

#获取登录的时间
time=${date +%F%t%k:%M}

#服务器的IP地址
server=${ifconfig wlp2s0 | sed -n '2p' | awk '{print $2}'}

echo ${user} ${ip} ${time} ${server}
```
