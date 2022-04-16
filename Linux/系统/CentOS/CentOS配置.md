<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-16 12:46:09
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-16 11:23:29
-->

## CentOS系统



### 更新源

```sh
sudo rm -rf /etc/yum.repos.d/*

sudo curl -o /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo

sudo yum clean all && yum makecache &&  yum -y update
```



### 配置Python

```sh
sudo yum install -y gcc zlib* libffi-devel wget

sudo wget 'https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz'

sudo tar -xvf Python-3.8.0.tar.xz -C /usr/bin

# 检测依赖;定位Python安装位置
cd /usr/bin/Python-3.8.0/

./configure --prefix=/usr/bin/python3

# 编译安装
sudo make && make install

# 修改环境变量
sudo sed -i "s#bin#bin:/usr/bin/python3/bin#g" ~/.bash_profile

# 执行以下命令使对配置的修改生效
sudo source ~/.bash_profile
```



### 安装Docker

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



### 防火墙
 
```sh
# 查看状态
systemctl status firewalld.service

# 关闭
systemctl stop firewalld.service

# 永久关闭
systemctl disable firewalld.service
```



### 网卡

- 文件位置

```sh
/etc/sysconfig/network-scripts
```

```ini
# 网卡类型，一般是Ethernet，还有其他的如bond，bridge
TYPE="Ethernet"
PROXY_METHOD="none"
BROWSER_ONLY="no"

# 获取IP地址的方式
# static/none 静态手工配置; dhcp 动态获取
BOOTPROTO="static"

# 设置默认路由,若为yes则可通过IPADDR和PREFIX两个参数来设置网关
DEFROUTE="yes"
IPV4_FAILURE_FATAL="no"
IPV6INIT="yes"
IPV6_AUTOCONF="yes"
IPV6_DEFROUTE="yes"
IPV6_FAILURE_FATAL="no"
IPV6_ADDR_GEN_MODE="stable-privacy"

# eth表示真实物理网卡，ens表示虚拟网络网卡
NAME="eth0"

# 通用唯一识别码，若vmware克隆的虚拟机无法启动网卡可去除此项
UUID="f1a9eae1-1ec0-4ef5-823a-7d9e9b804194"

# 系统逻辑设备名
DEVICE="eth0"

# 选择开机启动时是否激活网卡设备
ONBOOT="yes"

# 设置网卡对应的IP地址，网络服务启动后会自动将该地址配置到网卡上
IPADDR=192.168.137.2

# IP对应的网关(默认路由)，若主机是多网卡设备，该参数只能在一个网卡的配置文件里面出现
GATEWAY=192.168.137.1

# 主DNS，优先于/etc/resolv.conf中设置的DNS服务器的地址
DNS1=192.168.137.1

# 子网掩码
NETMASK=255.255.255.0
```