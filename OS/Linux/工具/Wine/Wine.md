<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-02 02:39:19
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-01 22:35:38
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

### Docker搭建

启动前额外输入

```sh
xhost +
```

## PVS

```sh
xhost +
```

## Docker

```sh
docker run -itd \
   --name pvs \
   --device /dev/snd \
   --ipc="host"\
   -v /tmp/.X11-unix:/tmp/.X11-unix \
   -e XMODIFIERS=@im=fcitx \
   -e QT_IM_MODULE=fcitx \
   -e GTK_IM_MODULE=fcitx \
   -e DISPLAY=unix$DISPLAY \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e VIDEO_GID=$(getent group video | cut -d: -f3) \
   -e GID=$(id -g) \
   -e UID=$(id -u) \
   ubuntu:18.04
```

```sh
sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

apt-get update && apt-get upgrade -y

apt-get install -y wine64

dpkg --add-architecture i386 && apt-get update && apt-get install wine32

apt-get install -y language-pack-zh-hans
```