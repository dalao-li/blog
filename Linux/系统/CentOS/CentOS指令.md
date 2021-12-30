<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-16 12:46:09
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-29 21:22:15
-->

## 更新源

```sh
sudo rm -rf /etc/yum.repos.d/*

sudo curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo

sudo yum clean all && yum makecache &&  yum -y update
```

## 配置Python

```sh
sudo yum install -y gcc zlib* libffi-devel wget

sudo wget 'https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz'

sudo tar -xvf Python-3.8.0.tar.xz -C /usr/bin

# 检测依赖;定位Python安装位置
cd  /usr/bin/Python-3.8.0/

./configure --prefix=/usr/bin/python3

# 编译安装
sudo make && make install 

# 修改环境变量
sudo sed -i "s#bin#bin:/usr/bin/python3/bin#g" ~/.bash_profile

# 执行以下命令使对配置的修改生效
sudo source ~/.bash_profile
```

## 安装Docker

```sh
sudo yum remove -y docker docker-common docker-selinux docker-engine

sudo yum install -y yum-utils device-mapper-persistent-data lvm2

sudo curl -o /etc/yum.repos.d/docker-ce.repo https://repo.huaweicloud.com/docker-ce/linux/centos/docker-ce.repo

sudo sed -i 's#download.docker.com#repo.huaweicloud.com/docker-ce#' /etc/yum.repos.d/docker-ce.repo

sudo yum makecache fast && yum install -y docker-ce

sudo systemctl start docker && systemctl enable docker

if $USER != "root";then
  # 添加docker用户组
  sudo groupadd docker
  # 将登陆用户加入到docker用户组中
  sudo gpasswd -a $USER docker
  # 更新用户组
  sudo newgrp docker
fi

sudo cat > /etc/docker/daemon.json <<EOF
{
  "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn"]
}
EOF

sudo systemctl restart docker

# 安装docker-compose
sudo curl -o /etc/yum.repos.d/epel.repo http://mirrors.aliyun.com/repo/epel-7.repo

sudo yum update -y && yum install epel-release -y
```