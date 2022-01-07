<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-06-13 20:32:36
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-08 06:21:00
-->

## 换源

- 添加国内源

/etc/pacman.d/mirrorlist

```sh
## aliyun
Server = http://mirrors.aliyun.com/archlinux/$repo/os/$arch
```

- 中文社区仓库

/etc/pacman.conf

```sh
[archlinuxcn]

SigLevel = Optional TrustAll
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```

- 更新

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

- 配置yay的aur源

```sh
yay --aururl "https://aur.tuna.tsinghua.edu.cn" --save
```

## 安装deb

```sh

yay -S debtap

sudo debtap -u

# 转换deb
sudo debtap xxxxxx.deb

sudo pacman -U xxxxxxz.zst
```

## 中文输入法

- 安装软件

```sh
sudo pacman -S --noconfirm fcitx5 fcitx5-qt fcitx5-gtk fcitx5-qt4 fcitx5-chinese-addons fcitx5-configtool fcitx5-material-color fcitx5-pinyin-moegirl fcitx5-pinyin-zhwiki
```

sudo vim /etc/profile

```sh
export XIM="fcitx"

export XIM_PROGRAM="fcitx"
 
export XMODIFIERS="@im=fcitx"
 
export GTK_IM_MODULE="fcitx"

export QT_IM_MODULE="fcitx"
```

sudo vim ~/.xinitrc

```sh
export LC_CTYPE=zh_CN.UTF-8
```

重启

##  默认文件管理器

[参考](https://blog.csdn.net/qq_32337527/article/details/81778732)

- 查看当前文件管理器

```sh
xdg-mime query default inode/directory   
```

- 恢复默认文件管理器

```sh
xdg-mime default org.gnome.Nautilus.desktop inode/directory
```

## 软件

- 安装

`yay -S`

```sh
yay -S microsoft-edge-stable

yay -S visual-studio-code-bin

yay -S flameshot
```

```
yay -R
``