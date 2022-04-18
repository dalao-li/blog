<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 14:02:02
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 19:59:01
-->

## Hyper-v


### 嵌套虚拟化


请确保虚拟机为关闭状态
  
```sh
Get-VM
```
![](https://cdn.hurra.ltd/img/20210207140309.png)

此处虚拟机名为CentOS 7

```sh
Get-VMProcessor -VMName 虚拟机名 | fl
```
![](https://cdn.hurra.ltd/img/20210207140508.png)

显示嵌套虚拟化选项值为False

```
Set-VMProcessor -ExposeVirtualizationExtensions $true -VMName 虚拟机名
```

正常情况没有输出

![](https://cdn.hurra.ltd/img/20210207140853.png)



### Vmware于Hyper共存


在Vmware中创建虚拟机的时候，Vmware提示

```sh
VMware Workstation和Hyper-V不兼容.

请先从系统中移除Hyper-V角色，然后再运行VMware Workstation
```

两者都是基于 $CPU$ 等底层硬件的 $Hypervisor$ 机制来实现的，而他们必须独占管理 $Hypervisor$，因此不能在一台电脑中同时运行


- 关闭Hyper-v

```sh
bcdedit /set hypervisorlaunchtype off
```


- 开启Hyper-v

```sh
bcdedit /set hypervisorlaunchtype auto
```
