<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao_li
 * @Email: dalao_li@163.com
 * @Date: 2023-04-26 23:22:59
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-26 23:44:52
-->

# Docker部署Wine

## Dockerfile

```sh
FROM ubuntu:18.04

ENV DEBIAN_FRONTEND=noninteractive

RUN set -eux &&                                                                  \
    sed -i 's#archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list &&  \
    sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list && \
    apt update && apt upgrade -y &&                                              \
    apt install -y locales tzdata xfonts-wqy &&                                  \
    dpkg-reconfigure --frontend noninteractive tzdata &&                         \
    locale-gen zh_CN.UTF-8 &&                                                    \
    update-locale LANG=zh_CN.UTF-8 LANGUAGE=zh_CN.UTF-8 LC_ALL=zh_CN.UTF-8 &&    \
    ln -fs /usr/share/zoneinfo/Asia/Shanghai /etc/localtime &&                   \
    dpkg-reconfigure --frontend noninteractive tzdata &&                         \
    find /var/lib/apt/lists -type f -delete &&                                   \
    find /var/cache -type f -delete

ENV LANG=zh_CN.UTF-8 LANGUAGE=zh_CN.UTF-8 LC_ALL=zh_CN.UTF-8
```

## wine启动软件

```sh
docker run -itd                                     \
   --name wine_test                                 \
   --device=/dev/fuse                               \
   --ipc="host"                                     \
   -v /tmp/.X11-unix:/tmp/.X11-unix                 \
   -e DISPLAY=unix$DISPLAY                          \
   -e XMODIFIERS=@im=fcitx                          \
   -e QT_IM_MODULE=fcitx                            \
   -e GTK_IM_MODULE=fcitx                           \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e GID=$(id -g)                                  \
   -e UID=$(id -u)                                  \
   --privileged                                     \
   --cap-add=MKNOD                                  \
   --cap-add=SYS_ADMIN                              \
   wine_dev:v1
```
