<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-23 19:10:50
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-10 22:25:11
-->

## 防火墙
 
```sh
# 查看状态
systemctl status firewalld.service

# 关闭
systemctl stop firewalld.service

# 永久关闭
systemctl disable firewalld.service
```