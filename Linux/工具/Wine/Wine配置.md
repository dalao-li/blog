<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-01-02 02:39:19
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 09:38:57
-->

# Wine

## 配置

### 安装

```sh
sudo apt-get install -y wine64
```

### 配置页面

```sh
winecfg
```

### 显示

启动前额外输入

```sh
xhost +
```

## 部署

### 容器

- 容器设置

```sh
docker run -itd                                     \
   --name pvs                                       \
   --device /dev/snd                                \
   --ipc="host"                                     \
   -v /tmp/.X11-unix:/tmp/.X11-unix                 \
   -e XMODIFIERS=@im=fcitx                          \
   -e QT_IM_MODULE=fcitx                            \
   -e GTK_IM_MODULE=fcitx                           \
   -e DISPLAY=unix$DISPLAY                          \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e VIDEO_GID=$(getent group video | cut -d: -f3) \
   -e GID=$(id -g)                                  \
   -e UID=$(id -u)                                  \
   ubuntu:18.04
```

- Wine配置

```sh
sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

apt update && apt upgrade -y

apt install -y wine64

dpkg --add-architecture i386 && apt update && apt install wine32

apt install -y language-pack-zh-hans
```
