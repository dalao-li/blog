#!/bin/bash

###
 # @Description: 
 # @Version: 1.0
 # @Author: DaLao
 # @Email:  
 # @Date: 2022-01-17 02:05:53
 # @LastEditors: daLao
 # @LastEditTime: 2023-04-21 23:32:32
### 

init(){
    sudo sed -i '1iServer = http://mirrors.aliyun.com/archlinux/$repo/os/$arch' /etc/pacman.d/mirrorlist

    sudo bash -c cat >> /etc/pacman.conf << EOF
[archlinuxcn]

SigLevel = Optional TrustAll
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinuxcn/$arch
EOF

    sudo pacman -Syudd

    git config --global user.name "dalao"
    git config --global user.email " "
    git config --global core.editor "code -w"
    # 防止中文乱码
    git config --global core.quotepath false
}


set_pinyin(){
    sudo pacman -S --noconfirm fcitx5 fcitx5-qt fcitx5-gtk fcitx5-qt4 fcitx5-chinese-addons fcitx5-configtool fcitx5-material-color fcitx5-pinyin-moegirl fcitx5-pinyin-zhwiki

    sudo bash -c cat >> /etc/profile << EOF
export XIM="fcitx"
export XIM_PROGRAM="fcitx"
export XMODIFIERS="@im=fcitx"
export GTK_IM_MODULE="fcitx"
export QT_IM_MODULE="fcitx"
EOF

    sudo echo "export LC_CTYPE=zh_CN.UTF-8" >> ~/.xinitrc
}


set_yay(){
    sudo pacman -S yay

    yay --aururl "https://aur.tuna.tsinghua.edu.cn" --save

    yay -S --noconfirm visual-studio-code-bin flameshot grub-customizer vlc
}


set_docker(){
    yay -S --noconfirm docker

    sudo groupadd docker

    sudo usermod -aG docker ${USER}

    sudo newgrp docker

    sudo bash -c "cat > /etc/docker/daemon.json" <<EOF
{
    "registry-mirrors":["https://997nddro.mirror.aliyuncs.com"]
}
EOF
    sudo systemctl start docker
}


set_node(){
    sudo yay -S nodejs npm

    npm config set registry http://mirrors.cloud.tencent.com/npm/
}


set_proxy(){
    url="https://service-33p4qzr4-1256078775.gz.apigw.tencentcs.com/link/905nAdJlOb1QYJZU?clash=1"
    
    path=".config/clash/config.yaml"
    
    sudo mkdir -p "${HOME}/.config/clash"

    sudo wget ${url} -O "${HOME}/${path}"
 
    sudo docker run -itd \
        -p 7890:7890 -p 7891:7891 -p 9090:9090 \
        --mount type=bind, source="${HOME}/${path}", target="/root/${path}", readonly \
        --restart=unless-stopped \
        --name=clash_test \
        dreamacro/clash:v1.8.0 
    # https://clash.razord.top/ 
    # https://www.woccloud.io/
}


set_python(){
    pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U

    pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple

    echo "export PATH=${HOME}/anaconda3/bin:${PATH}">>~/.bashrc

    source ~/.bashrc
}






