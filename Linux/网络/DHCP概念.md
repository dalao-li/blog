<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-24 17:08:04
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-27 22:53:30
-->


## DHCP


### 协议


动态主机配置协议($Dynamic$ $Host$ $Configuration$ $Protocol$)是使用$UDP$协议工作的局域网网络协议

- 为内部网络或网络服务供应商自动分配IP地址

- 为用户或者内部网络管理员作为对所有计算机作中央管理的手段

- 为内部网络用户接受$IP$租约



### DHCP服务器


专门承载和运行DHCP服务，帮助管理IP的专用服务器

配置DHCP服务器的优点:

- 大部分路由器可以转发DHCP配置请求，因此，互联网的每个子网并不都需要DHCP服务器


- 客户机不需手工配置TCP/IP


- 使用$DHCP$服务器能大大减少配置花费的开销和重新配置网络上计算机的时间，服务器可以在指派地址租约时配置所有的附加配置值


- 提供安全可信的配置，DHCP避免了在每台计算机上手工输入数值引起的配置错误，还能防止网络上计算机配置地址的冲突


- 客户机在子网间移动时，旧的IP地址自动释放以便再次使用.在再次启动客户机时，$DHCP$服务器会自动为客户机重新配置$TCP/IP$


- 管理员可以集中为整个互联网指定通用和特定子网的TCP/IP参数，并且可以定义使用保留地址的客户机的参数.


利用DHCP服务器，我们可以灵活的利用手工分配、自动分配及动态分配3种分配方式，为DHCP客户机分配TCP/IP地址，从而做到更为方便的管理和维护DHCP客户机，同时也可以有效解决IP不够用的问题



### 配置DHCP主机


新建VMnet10网卡

![](https://cdn.hurra.ltd/img/20210325105620.png)

![](https://cdn.hurra.ltd/img/20210325105957.png)

![](https://cdn.hurra.ltd/img/20210325110230.png)

安装DHCP服务

```sh
yum install -y dhcp
```


复制模板文件

```sh
cp /usr/share/doc/dhcp-4.2.5/dhcpd.conf.example  /etc/dhcp/dhcpd.conf 
```


编辑/etc/dhcp/dhcpd.conf,增加

```sh
subnet 192.168.100.0 netmask 255.255.255.0{

  # 分配IP的范围
  range 192.168.100.100 192.168.100.110;
  
  option domain-name-servers 8.8.8.8;

  # 广播地址注意需与ifconfig查询的结果一致
  option broadcast-address 192.168.100.255;
}
```

- 启动DHCP服务

```sh
systemctl start dhcpd
```

![](https://cdn.hurra.ltd/img/20210325112141.png)

可以看到已经在监听相应的IP段

配置虚拟网络编辑器，关闭VMnet10的"使用本地DHCP服务器的选项"

![](https://cdn.hurra.ltd/img/20210325112452.png)

重新开启一台主机，选择VMnet10网卡

![](https://cdn.hurra.ltd/img/20210325112725.png)

开机查看IP地址

![](https://cdn.hurra.ltd/img/20210325113017.png)