<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 14:02:02
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 01:58:07
-->

## Hyper-v

> 请确保虚拟机为关闭状态
  
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