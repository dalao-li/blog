#! /bin/bash

###
 # @Description: 
 # @Version: 1.0
 # @Author: DaLao
 # @Email: dalao_li@163.com
 # @Date: 2022-07-09 23:24:40
 # @LastEditors: DaLao
 # @LastEditTime: 2022-07-09 23:24:51
### 

#Memory小于400M时 释放Cached的内存
mem=409600
freemem=$(cat /proc/meminfo | grep "MemFree" | awk '{print $2}')
if [ ${freemem} -le ${mem} ];then
    date >> /var/log/mem.log
    free -m >> /var/log/mem.log
    sync
    sync
    echo 3 > /proc/sys/vm/drop_caches
    free -m >> /var/log/mem.log
fi