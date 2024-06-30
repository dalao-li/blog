<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-07-15 11:40:19
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-09-16 16:18:19
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-22 18:19:06
-->

> [Trash-Cli：Linux 上的命令行回收站工具](https://zhuanlan.zhihu.com/p/44948578)

# Ubuntu系统配置

## 设置回收站

- 安装

```sh
sudo apt-get install trash-cli
```

- 指令

.bashrc 或 .zshrc 添加指令

```sh
alias rm='trash-put'
alias rl='trash-list'
```

生效

```sh
source .bashrc 或

source .zshrc
```

- 回收站路径

```sh
~/.local/share/Trash/files
```

## 关闭root密码

```sh
sudo vim /etc/sudoers
```

![9](https://cdn.hurra.ltd/img/2021-07-17_00-08.png)

```sh
dalao ALL=(ALL:ALL) ALL

dalao ALL=(ALL) NOPASSWD:ALL
```

## 更新源

同步sources.list 和sources.list.d 中列出软件源索引

```sh
apt-get update
```

对系统执行更新
  
```sh
apt-get upgrade
```

## 转换目录语言

```sh
export LANG=en_US

xdg-user-dirs-gtk-update

export LANG=zh_CN
```

## 程序包缓存文件已损坏

```sh
sudo rm -rf /var/lib/apt/lists/*  
```

## 转换rpm到deb

```sh
sudo apt-get install -y rpm alien

sudo alien -d [package].rpm &

sudo dpkg -i [package].deb
```

## 消除双图标

```sh
xprop | grep WM_CLASS
```

此时鼠标会变成一个十字的准星, 此时点击已经打开的应用界面

```sh
WM_CLASS(STRING) = "信息1", "信息2"
```

然后在该应用的.desktop文件末尾添加

```sh
StartupWMClass=信息2
```

## 卸载软件

```sh
# 查找安装包名
dpkg -l *软件相关字段*

sudo apt-get --purge remove 包名
```

## VM

- 激活码

```sh
JU090-6039P-08409-8J0QH-2YR7F
```

- 安装vm所需驱动

```sh
sudo apt-get install build-essential linux-headers-$(uname -r)
```

- 卸载VM

```sh
sudo vmware-installer -u vmware-workstation
```

## 快捷指令

```sh
# alias 新指令='原本指令'

sudo bash -c "cat > ~/.bashrc" <<EOF
alias update='sudo apt-get update && sudo apt-get upgrade -y'
alias clean="sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'"
EOF

source ~/.bashrc
```

### QQ Wechat

```sh
#!/bin/bash

xhost +

docker run -itd                                     \
   --name qq                                        \
   --device /dev/snd                                \
   --ipc="host"                                     \
   -v ${HOME}/QQ/TencentFiles:/TencentFiles         \
   -v /tmp/.X11-unix:/tmp/.X11-unix                 \
   -e XMODIFIERS=@im=fcitx                          \
   -e QT_IM_MODULE=fcitx                            \
   -e GTK_IM_MODULE=fcitx                           \
   -e DISPLAY=unix$DISPLAY                          \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e VIDEO_GID=$(getent group video | cut -d: -f3) \
   -e GID=$(id -g)                                  \
   -e UID=$(id -u)                                  \
   bestwu/qq:office


docker run -itd                                     \
   --name wechat                                    \
   --device /dev/snd                                \
   --ipc="host"                                     \
   -v /tmp/.X11-unix:/tmp/.X11-unix                 \
   -v ${HOME}/WeChatFiles:/WeChatFiles              \
   -e XMODIFIERS=@im=fcitx                          \
   -e QT_IM_MODULE=fcitx                            \
   -e GTK_IM_MODULE=fcitx                           \
   -e DISPLAY=unix$DISPLAY                          \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e VIDEO_GID=$(getent group video | cut -d: -f3) \
   -e GID=$(id -g)                                  \
   -e UID=$(id -u)                                  \
   bestwu/wechat
```

## 分辨率设置

[解决 Ubuntu 22.04 Fractional Scaling 画面伸缩后应用程序模糊](https://blog.csdn.net/wu_weijie/article/details/126401259)

## 重启

$Ubuntu$出现什么状况, 千万不要强制重启

- 同时按住 <kbd>Ctrl</kbd> + <kbd>Alt</kbd> 不要放

- 按一下 <kbd>SysRq</kbd> 键(有的是<kbd>PrtSc</kbd>)

- 依次按下<kbd>R</kbd> 键, <kbd>E</kbd> 键, <kbd>I</kbd> 键, <kbd>U</kbd> 键, <kbd>S</kbd> 键, <kbd>B</kbd> 键

这些步骤做完后, 系统就会安全重启
