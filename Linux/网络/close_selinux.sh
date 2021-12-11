#!/bin/bash

###
 # @Description:关闭selinux 
 # @Version: 1.0
 # @Author: DaLao
 # @Email: dalao_li@163.com
 # @Date: 2021-04-01 09:07:00
 # @LastEditors: DaLao
 # @LastEditTime: 2021-04-10 02:35:11
### 


sudo sed -i -e  's/^SELINUX=.*/SELINUX=disabled/g' /etc/selinux/config

setenforce 0
