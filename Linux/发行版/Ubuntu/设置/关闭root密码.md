<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-14 02:16:05
 * @LastEditors: DaLao
 * @LastEditTime: 2021-08-14 02:16:13
-->

## 关闭root密码

```sh
sudo vim /etc/sudoers
```

![](https://cdn.hurra.ltd/img/2021-07-17_00-08.png)

```sh
dalao ALL=(ALL:ALL) ALL

dalao ALL=(ALL) NOPASSWD:ALL
```