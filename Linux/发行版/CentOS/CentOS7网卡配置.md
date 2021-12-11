<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 23:27:49
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-16 12:56:27
-->

```sh
# 文件位置
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