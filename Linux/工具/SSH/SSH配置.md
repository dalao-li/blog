<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-14 13:31:07
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-29 21:33:45
-->

## 连接

```sh
ssh 用户名@IP地址 (-p 端口号)
```

```sh
# 端口号默认为20
ssh dalao@192.168.1.1
```

## 清除主机密钥

```sh
ssh-keygen -R [远程主机IP]
``` 

## 免密

- 方法1，手动复制

把本地主机`id_rsa.pub` 复制到远程主机.ssh/authorized_keys里

- 方法2，命令复制

```sh
ssh-copy-id -i ~/.ssh/id_rsa.pub 远程用户@远程主机IP
```

![](https://cdn.hurra.ltd/img/20211229213337.png)

## .ssh目录

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

known_hosts通过Client和Server的双向认证，以避免中间人(man-in-the-middle attack)攻击

Client向Server发起连接时，Server不仅要验证Client的合法性，Client也会通过known_hosts中的host key来验证Server的身份


## 配置文件

/etc/ssh/sshd_condfig

```sh
# 允许密钥登录
RSAAuthentication yes

# 允许公钥验证 
PubkeyAuthentication yes

# 禁止密码登录
PasswordAuthentication no
```