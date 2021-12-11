<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 15:33:17
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-06 15:33:17
-->

## QQ Wechat

```sh
#!/bin/bash

docker run -itd \
   --name qq \
   --device /dev/snd \
   --ipc="host"\
   -v ${HOME}/QQ/TencentFiles:/TencentFiles \
   -v /tmp/.X11-unix:/tmp/.X11-unix \
   -e XMODIFIERS=@im=fcitx \
   -e QT_IM_MODULE=fcitx \
   -e GTK_IM_MODULE=fcitx \
   -e DISPLAY=unix$DISPLAY \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e VIDEO_GID=$(getent group video | cut -d: -f3) \
   -e GID=$(id -g) \
   -e UID=$(id -u) \
   bestwu/qq:office


docker run -itd \
   --name wechat \
   --device /dev/snd \
   --ipc="host"\
   -v /tmp/.X11-unix:/tmp/.X11-unix \
   -v ${HOME}/WeChatFiles:/WeChatFiles \
   -e XMODIFIERS=@im=fcitx \
   -e QT_IM_MODULE=fcitx \
   -e GTK_IM_MODULE=fcitx \
   -e DISPLAY=unix$DISPLAY \
   -e AUDIO_GID=$(getent group audio | cut -d: -f3) \
   -e VIDEO_GID=$(getent group video | cut -d: -f3) \
   -e GID=$(id -g) \
   -e UID=$(id -u) \
   bestwu/wechat
```
