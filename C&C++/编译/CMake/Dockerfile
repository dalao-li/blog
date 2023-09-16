# 构建最新版本的cmake开发环境

from ubuntu:18.04

workdir /code

run sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list && \
    sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list && \
    sed -i 's#archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

run apt update && apt upgrade -y && apt install g++ wget --reinstall software-properties-common -y

run wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | apt-key add -

run apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'  && apt update && apt install -y cmake