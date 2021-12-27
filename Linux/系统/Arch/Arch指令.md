<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-06-13 20:32:36
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-28 00:06:02
-->

## 更新源

编辑 /etc/pacman.d/mirrorlist,添加
```sh
echo "Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch" >> /etc/pacman.d/mirrorlist
```

```sh
# 更新软件包缓存
sudo pacman -Syy
```

## 安装软件

```sh
sudo pacman -S 软件包名
```