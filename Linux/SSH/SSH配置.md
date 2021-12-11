<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-14 13:31:07
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 20:21:05
-->

## .ssh目录

```sh
# 在当前用户的根目录(/root/或者/home/用户名)下生成 .ssh目录
ssh-keygen -t rsa
```

![](https://cdn.hurra.ltd/img/20210312104415.png)

| 文件            | 作用                     |
| --------------- | ------------------------ |
| authorized_keys | 存储其他主机的公钥       |
| id_rsa          | 本机私钥文件             |
| id_rsa.pub      | 本机公钥文件             |
| know_hosts      | 存储已认证主机的host key |

ssh公钥生效需满足

- .ssh目录的权限必须是700

- .ssh/authorized_keys文件权限必须是600
```sh
# 首次登录时Client端会提示
Host key not found from the list of known hosts.
Are you sure you want to continue connecting (yes/no)?

# 若选择yes则Server的host key就被加入Client的known_hosts中，格式如下
# domain name+encryption algorithm+host key
example.hostname.com ssh-rsa AAAAB4NzaC1yc2EAAAABIwAAAQEA...
```

known_hosts通过Client和Server的双向认证，以避免中间人($man-in-the-middle$ $attack$)攻击

Client向Server发起连接时，Server不仅要验证Client的合法性，Client也会通过known_hosts中的host key来验证Server的身份

## SSH指令

```sh
# 连接
ssh 用户名@IP地址 (-p 端口号)
# 例,ssh dalao@192.168.1.1 (端口号默认为20)

# 清除主机密钥
ssh-keygen -R 远程主机IP
``` 

## 配置文件
```sh
# /etc/ssh/sshd_condfig

# 允许密钥登录
RSAAuthentication yes

# 允许公钥验证 
PubkeyAuthentication yes

# 禁止密码登录
PasswordAuthentication no
```