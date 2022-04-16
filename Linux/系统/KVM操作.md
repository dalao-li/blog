<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-06 21:53:27
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-25 22:19:43
-->

## 虚拟化

虚拟化是指通过虚拟化技术将一台计算机虚拟为多台逻辑计算机，每个逻辑计算机可运行不同的操作系统，并且应用程序都可以在相互独立的空间内运行而互不影响，从而显著提高计算机的工作效率


### 概念

基于内核的虚拟机(Kernel-based Virtual Machine)是一种用于$Linux$内核中的虚拟化基础设施，可将$Linux$内核转化为一个虚拟机监视器，使主机计算机能够运行多个隔离的虚拟环境，即虚拟客户机或虚拟机($VM$)


### 创建虚拟机

- 检查宿主机处理器是否支持虚拟化

```sh
egrep -o 'vmx | svm' /proc/cpuinfo | wc -l
```
![](https://cdn.hurra.ltd/img/20210207193309.png)

如果显示数值是 0，则表示该 CPU 不支持虚拟化

- 关闭 iptables

```sh
service iptables stop

chkconfig iptables off
```

- 关闭nux

```sh
setenforce 0
```

- 编辑 /etc/nux/config，对应内容改为

```sh
NUX=disabled
```