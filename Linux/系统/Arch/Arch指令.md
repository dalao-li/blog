<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-06-13 20:32:36
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-28 18:11:58
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

## 安装yaourt

文件末尾添加
```sh
sudo bash -c "cat >> /etc/pacman.conf" <<EOF
[archlinuxcn]
Server=https://mirrors.ustc.edu.cn/archlinuxcn/$arch
EOF
```

更新

```sh
sudo pacman -Sy

sudo pacman -S yaourt
```

安装archlinuxcn-keyring 包以导入 GPG key

```sh
sudo pacman -S archlinuxcn-keyring
```

## 安装deb

```sh
yaourt -S debtap

sudo debtap -u

# 转换deb
sudo debtap xxxxxx.deb

sudo pacman -U xxxxxxz.zst
```