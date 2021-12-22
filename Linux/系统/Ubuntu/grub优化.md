<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-17 00:11:16
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-20 23:02:15
-->

## 多硬盘启动

```sh
# 安装 grub-customizer
sudo apt-get install -y grub-customizer
```

![](https://cdn.hurra.ltd/img/20210817002414.png)

## 美化引导页面

下载主题包，编辑/etc/default/grub添加

```sh
GRUB_THEME="/主题包路径/theme.txt"

# echo GRUB_THEME="/主题包路径/theme.txt" >> /etc/default/grub
```

更新grub

```sh
sudo update-grub
```





