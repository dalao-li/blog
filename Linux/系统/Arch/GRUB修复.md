<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-17 04:03:30
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-17 04:04:32
-->


## 双系统修复

```sh
sudo gedit /etc/default/grub
```

修改内容如下

```sh
GRUB_TIMEOUT_STYLE="false"
```

- 更新

```sh
sudo grub-mkconfig -o /boot/grub/grub.cfg  
```