#!/bin/bash

###
 # @Description: 
 # @Version: 1.0
 # @Author: DaLao
 # @Email: dalao_li@163.com
 # @Date: 2021-07-10 13:27:20
 # @LastEditors: DaLao
 # @LastEditTime: 2021-12-27 02:11:52
### 

# 设置flameshot快捷键
# flameshot gui


DISK_PATH="/media/${USER}/disk_my/"

# 系统初始化配置 
init_system(){
    sudo sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
    sudo sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
    sudo apt-get update && sudo apt-get upgrade -y
    
    sudo apt-get install -y vlc flameshot vim git wget grub-customizer gnome-shell gnome-tweak-tool python3-pip xclip
    
    git config --global user.name "dalao"
    git config --global user.email "dalao_li@163.com"
    git config --global core.editor "code -w"
    # 防止中文乱码
    git config --global core.quotepath false
}

# 安装docker
install_docker(){
    sudo apt-get install -y curl

    # 添加秘钥
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - 

    sudo add-apt-repository "deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu $(lsb_release -cs) stable" 
    
    sudo apt-get update -y && sudo apt-get install docker-ce -y

    # 添加docker用户组，将登陆用户加入到docker用户组中
    sudo groupadd docker && sudo gpasswd -a ${USER} docker && sudo newgrp docker 

    su ${USER}
    # 修改源
    sudo bash -c "cat > /etc/docker/daemon.json" <<EOF
{
    "registry-mirrors":["https://997nddro.mirror.aliyuncs.com"]
}
EOF
    sudo service docker start

    set_proxy &
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
    url="https://service-33p4qzr4-1256078775.gz.apigw.tencentcs.com/link/M3rJNhAKrmF29zkx?clash=1"
    
    path=".config/clash/config.yaml"
    
    sudo mkdir -p "${HOME}/.config/clash"

    sudo wget ${url} -O "${HOME}/${path}"
 
    sudo docker run -itd \
        -p 7890:7890 -p 7891:7891 -p 9090:9090 \
        -v "${HOME}/${path}":"/root/${path}" \
        --restart=unless-stopped \
        --name=clash_test \
        dreamacro/clash 

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

# 在放置jetbrains包的目录下执行，安装jetbrains
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
    # 修改.sh文件，以使得能够正常输入中文
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
    sudo apt-get install -y build-essential linux-headers-$(uname -r)

    sudo sh ${DISK_PATH}/Ubuntu/App/VMware-Workstation-Full-16.1.1-17801498.x86_64.bundle
}

install_deb(){
    deb=("microsoft-edge-stable_96.0.1054.62-1_amd64" "XMind-2020-for-Linux-amd-64bit-10.3.1-202101132117.deb" )

    for j in {0..1};do 
        sudo dpkg -i ${DISK_PATH}/Ubuntu/App/${deb[j]}
    done
}

# init_system

# install_docker

# install_jetbrains_ide 

install_appimage  

#install_deb

#install_vm

#install_anaconda

