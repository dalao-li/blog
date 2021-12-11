<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-09 17:54:44
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-05 22:57:06
-->

## 原理

![](https://cdn.hurra.ltd/img/20210312095204.png)

利用密钥生成器制作公钥和私钥，将公钥添加到$Server$上，在$Client$利用私钥即可完成认证登录.

此时若没有私钥，任何人都无法通过暴力破解密码来SSH登录.


## 免密登录

```sh
# 方法一，通过ssh-conpy-id命令将id_rsa.pub发送到远程用户的authorized_key中
ssh-copy-id -i ~/.ssh/id_rsa.pub 远程用户@远程主机IP

# 方法二，手动将id_ras.pub文件内容复制到远程用户的authorized_keys中
```
免密以root用户登录Server

![](https://cdn.hurra.ltd/img/20210310091446.png)

查看Server上的authorized_keys

![](https://cdn.hurra.ltd/img/20210310091640.png)

可看到Client的公钥已被拷贝到Server的authorized_keys中，尝试SSH登录远程主机，此时便可免密登录

![](https://cdn.hurra.ltd/img/20210310091854.png)





