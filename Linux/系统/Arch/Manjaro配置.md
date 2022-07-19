<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-06-13 20:32:36
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-01 22:39:26
-->


## 配置


### 换源


- 添加国内源

```sh
sudo gedit /etc/pacman.d/mirrorlist
```

添加到所有源的开头

```sh
Server = http://mirrors.aliyun.com/archlinux/$repo/os/$arch
```

- 设置中文社区仓库

```sh
sudo gedit /etc/pacman.conf
```

```sh
[archlinuxcn]

SigLevel = Optional TrustAll
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
```


### 更新

```sh
sudo pacman -Syyu
```

- 清除无用的包

```sh
sudo pacman -R $(pacman -Qdtq)
```

- 更新失败解决

```sh
rm /var/lib/pacman/db.lck
```

- 依赖错误解决, 使用 `-dd`跳过所有检测

```sh
sudo pacman -Syudd
```


###  文件管理器

- 查看当前文件管理器

```sh
xdg-mime query default inode/directory   
```

![](https://cdn.hurra.ltd/img/20220109184225.png)

- 设置默认文件管理器

安装Vscode后, 文件管理器会被修改为Vscode, 可用以下命令重新设置

```sh
xdg-mime default org.gnome.Nautilus.desktop inode/directory
```


### Vscode终端乱码

vscode 设置中添加

```sh
"terminal.integrated.fontFamily": "NotoSansMono Nerd Font"
```


### gedit

```sh
sudo pacman -Syyu libvoikko hspell nuspell hunspell aspell
```


## 软件


### VM

```sh
# 查看版本
sudo uname -r 

# 选择对应版本
sudo pacman -S virtualbox

yay -S virtualbox-ext-oracle
```

```sh
sudo modprobe vboxdrv
```

### yay

```sh
sudo pacman -S yay
```

- 配置aur源

```sh
yay --aururl "https://aur.tuna.tsinghua.edu.cn" --save
```

- 安装


```sh
yay -S --noconfirm visual-studio-code-bin flameshot grub-customizer vlc
```

- 卸载

```
yay -Rns
```


### 安装deb

```sh
yay -S debtap

sudo debtap -u

# 转换deb
sudo debtap xxxxxx.deb

sudo pacman -U xxxxxxz.zst
```


### 中文输入法

- 安装fcitx

```sh
sudo pacman -S --noconfirm fcitx5 fcitx5-qt fcitx5-gtk fcitx5-qt4 fcitx5-chinese-addons fcitx5-configtool fcitx5-material-color fcitx5-pinyin-moegirl fcitx5-pinyin-zhwiki
```

- 配置

```sh
sudo vim /etc/profile
```

```sh
export XIM="fcitx"
export XIM_PROGRAM="fcitx"
export XMODIFIERS="@im=fcitx"
export GTK_IM_MODULE="fcitx"
export QT_IM_MODULE="fcitx"
```

```sh
sudo vim ~/.xinitrc
```

```sh
export LC_CTYPE=zh_CN.UTF-8
```

重启


### Anaconda

```sh
echo "export PATH=$HOME/anaconda3/bin:$PATH">>~/.bashrc

source ~/.bashrc
```


### 向日葵

```sh
yay -Sy sunloginclient

systemctl start runsunloginclient.service
```