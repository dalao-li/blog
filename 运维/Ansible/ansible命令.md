<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-08 10:40:15
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-06 03:49:08
-->

## 限定主机变更

- $limit$参数限定

```sh
ansible 分组 -m command -a "指令" --limit "主机IP"

# 只对web组中192.168.1.2主机操作
# ansible web -m command -a "systemctl status sshd" --limit "192.168.100.20"
```

- $IP$限定

```sh
ansible 主机IP -m command -a "指令"

# 只对192.168.100.0网段主机操作
```

- 网段限定

```sh
ansible 192.168.100.* -m command -a "systemctl status httpd"
```

## 查看所有主机

```sh
ansible all --list-hosts
```

## Ping

```sh
ansible 主机名/all -m ping
```

## copy模块

```sh
# 把主控端/root/目录的init.sh拷贝到到被控节点/tem/目录下
ansible all -m copy -a 'src=/root/init.hs dest=/tem/'
```

## file模块

```sh
# 更改被控节点上init.sh的权限为755，属主和属组为root
ansible all -m file -a "dest=/tem/init.sh mode=755 owner=root group=root"
```

## cron模块

```sh
# 在指定节点上定义一个计划任务，每隔3分钟到主控端更新一次时间
ansible all -m cron -a 'name="custom job" minute=*/3 hour=* day=* month=* weekday=* job="/usr/sbin/ntpdate 172.16.254.139"'
```

## group模块

```sh
# 在所有节点上创建一个组名为nolinux，gid为2014的组
ansible all -m group -a 'gid=2014 name=nolinux'
```

## user模块

```sh
# 在指定节点上创建一个用户名为nolinux，组为nolinux的用户
ansible all -m user -a 'name=nolinux groups=nolinux state=present'
```

## yum模块

在指定节点上安装 lrzsz 服务

```sh
ansible all -m yum -a "state=present name=httpd"
```

## service模块

```sh
# 启动指定节点上的 puppet 服务，并让其开机自启动
ansible all -m service -a 'name=puppet state=restarted enabled=yes'
```

## script模块

```sh
# 在指定节点上执行控制节点上的a.sh脚本
ansible all -m script -a '/root/a.sh'
```

## command模块

```sh
# 在指定节点上运行hostname命令
ansible all -m command -a 'hostname'
```

## raw模块

```sh
# 在all节点上运行hostname命令
ansible all -m raw-a 'hostname|tee'
```

## get_url模块

```sh
# 将http://10.1.1.116/favicon.ico文件下载到指定节点的/root/目录下
ansible all -m get_url -a 'url=http://10.1.1.116/favicon.ico dest=/root/'
```