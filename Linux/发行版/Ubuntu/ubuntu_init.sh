#!/bin/bash

###
 # @Description: 
 # @Version: 1.0
 # @Author: DaLao
 # @Email:  
 # @Date: 2021-07-10 13:27:20
 # @LastEditors: Please set LastEditors
 # @LastEditTime: 2024-06-10 16:52:35
### 

# 设置flameshot快捷键
# flameshot gui


DISK_PATH="/media/${USER}/disk_my/"

update_source(){
    sudo sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
    sudo sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
    sudo sed -i 's#archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
    sudo apt update && sudo apt upgrade -y
}


# 系统初始化配置 
init_system(){
    sudo apt install -y vlc flameshot vim wget grub-customizer gnome-shell python3-pip xclip

    git config --global core.editor "code -w"
    # 防止中文乱码
    git config --global core.quotepath false
}


# 安装docker
install_docker(){
    sudo apt install docker.io

    # 添加docker用户组, 将登陆用户加入到docker用户组中
    sudo usermod -aG docker $USER

    sudo newgrp docker

    # 修改Docker源
    sudo bash -c "cat > /etc/docker/daemon.json" <<EOF
{
    "registry-mirrors":["https://997nddro.mirror.aliyuncs.com"]
}
EOF
    sudo service docker restart
}


install_node(){
    sudo wget https://nodejs.org/dist/v16.13.1/node-v16.13.1-linux-x64.tar.xz

    sudo tar -xJf node-v16.13.1-linux-x64.tar.xz -C /opt

    sudo ln -s /opt/node-v16.13.1-linux-x64/bin/npm /usr/local/bin/npm

    sudo ln -s /opt/node-v16.13.1-linux-x64/bin/node /usr/local/bin/node

    sudo npm config set registry https://registry.npm.taobao.org

    source ~/.bashrc
}


# 安装代理
set_proxy(){
    url="https://cdn.woccloud.org/s/RR5AuofL98Pchv39?clash=2&extend=1"
    
    path=".config/clash/config.yaml"
    
    sudo mkdir -p "${HOME}/.config/clash"

    sudo wget ${url} -O "${HOME}/${path}"
 
    sudo docker run -itd                                                           \
        -p 7890:7890 -p 7891:7891  -p 9090:9090                                    \
        --mount type=bind,source="${HOME}/${path}",target="/root/${path}",readonly \
        --restart=unless-stopped                                                   \
        --name=clash                                                               \
        dreamacro/clash:v1.8.0
    # https://clash.razord.top/
}


install_appimage(){
    name=("navicat" "picgo")
    # 防止出现双图标
    wm=("AppRun" "picgo")
    
    for i in {0..1};do
        sudo cp -r "${DISK_PATH}/Ubuntu/AppImage/${name[i]}" /usr/local/bin

        path="/usr/local/bin/${name[i]}/${name[i]}"

        sudo bash -c "cat > /usr/share/applications/${name[i]}.desktop" <<EOF
[Desktop Entry]

Type=Application
Name=${name[i]}
Exec=${path}.AppImage
Icon=${path}.png
StratupWMClass=${wm[i]}
EOF
    done
}


# 在放置jetbrains包的目录下执行, 安装jetbrains
set_jetbrains_ide(){
    name=${3}
    
    sudo tar -xvf ${DISK_PATH}/Ubuntu/Jetbrains/${1} -C /usr/local/bin
    
    sudo mv /usr/local/bin/${2} /usr/local/bin/${name}

    path="/usr/local/bin/${name}/bin/${name}"

    sudo bash -c "cat > /usr/share/applications/${name}.desktop" <<EOF
[Desktop Entry]

Type=Application
Name=${name}
Exec=sh ${path}.sh
Icon=${path}.png
StartupWMClass=jetbrains-${name}
EOF
    # 修改.sh文件, 以使得能够正常输入中文
    sudo bash -c "cat >> ${path}.sh" <<EOF
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
EOF

}


# 安装jetbrains
install_jetbrains_ide(){
    tar=("pycharm-professional-2021.1.tar.gz" "CLion-2021.1.tar.gz" "goland-2021.1.tar.gz")
    
    file=("pycharm-2021.1" "clion-2021.1" "GoLand-2021.1")
    
    name=("pycharm" "clion" "goland")

    for i in {0..3};do 
        set_jetbrains_ide ${tar[i]} ${file[i]} ${name[i]} &
    done
    wait
}


install_anaconda(){
    sudo sh ${DISK_PATH}/Ubuntu/App/Anaconda3-2020.11-Linux-x86_64.sh

    # 设置环境变量
    echo "export PATH=~/anaconda3/bin:\$PATH">>~/.bashrc

    source ~/.bashrc

    # 默认退出conda
    conda config --set auto_activate_base false

    # pip 换源
    pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U
    
    pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
}


# 安装虚拟机
install_vm(){
    sudo apt install -y build-essential linux-headers-$(uname -r)

    sudo sh ${DISK_PATH}/Ubuntu/App/VMware-Workstation-Full-16.1.1-17801498.x86_64.bundle
}


install_deb(){
    deb=("microsoft-edge-stable_96.0.1054.62-1_amd64" "XMind-2020-for-Linux-amd-64bit-10.3.1-202101132117.deb" )

    for j in {0..1};do 
        sudo dpkg -i ${DISK_PATH}/Ubuntu/App/${deb[j]}
    done
}