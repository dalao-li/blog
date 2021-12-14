<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-11 21:39:25
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-13 20:27:54
-->

## 连接

```sh
ssh 用户名@IP地址 (-p 端口号)
# 例,ssh dalao@192.168.1.1 (端口号默认为20)
```

## 清除主机密钥

```sh
ssh-keygen -R 远程主机IP
``` 

## 免密

- 方法1，手动复制

把本地主机的id_rsa.pub 复制到远程主机的.ssh/authorized_keys里

- 方法2，命令复制

```sh
# 本地执行
ssh-copy-id -i ~/.ssh/id_rsa.pub 远程用户@远程主机IP
```