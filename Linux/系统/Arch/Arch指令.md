<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-06-13 20:32:36
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-30 02:11:04
-->

## 更新源

```sh
sudo bash -c "cat >> /etc/pacman.conf" <<EOF
[archlinuxcn]
Server=https://mirrors.ustc.edu.cn/archlinuxcn/$arch
EOF
```

安装archlinuxcn-keyring 包以导入 GPG key

```sh
sudo pacman -S archlinuxcn-keyring
```

同步更新

```sh
sudo pacman -Syyu
```

- 若更新失败

```sh
rm /var/lib/pacman/db.lck
```

## yay

```sh
sudo pacman -S yay
```

配置yay的aur源

```sh
yay --aururl "https://aur.tuna.tsinghua.edu.cn" --save
```

## 安装deb

```sh

yaourt -S debtap

sudo debtap -u

# 转换deb
sudo debtap xxxxxx.deb

sudo pacman -U xxxxxxz.zst
```