<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-08 09:36:50
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-17 09:31:56
-->


## Ansible


### 概念


Ansible是一个配置管理和应用部署工具，可以对服务器上($1-N$台)的系统应用进行配置管理，如更改部分参数，安装软件应用等

Ansible本质是在多设备按情况(判断循环)指定每台设备要执行的命令

### 安装

```sh
# 新增 epel-release 第三方套件来源，安装Ansible
yum install -y epel-release ansible

# 配置文件/etc/ansible/ansible.cfg
```



### 容器控制


建立两个容器server1，server2，并用ansible对其进行控制

```sh
docker run -itd --name server1 -P chusiang/ansible-managed-node:ubuntu-14.04
```

- 修改/etc/ansible/ansible.cfg文件

```ini
[defaults]

# 档案路径
hostfile = hosts

# 被控端用户名
remote_user = docker

# 不询问是否加入密钥
host_key_checking = False
```


- 修改/etc/ansible/hosts

```sh
# [分组，组名]
[local]

server1 ansible_ssh_host=172.17.0.2 ansible_ssh_port=22 ansible_ssh_pass=docker

server2 ansible_ssh_host=172.17.0.3 ansible_ssh_port=22 ansible_ssh_pass=docker
```

| 参数             | 值        |
| ---------------- | --------- |
| ansible_ssh_host | Server IP |
| ansible_ssh_port | SSH port  |
| ansible_ssh_pass | SSH密码   |

控制所有受控主机输出

```sh
ansible all -m command -a 'echo Hello World!'
```

![](https://cdn.hurra.ltd/img/20210308100822.png)


- 批量SSH免密

通过Ansible批量给多台远程主机设置SSH免密

| 主机     | IP             | 远程登录用户 |
| -------- | -------------- | ------------ |
| Client   | 192.168.43.231 |              |
| Server_1 | 172.17.0.2     | docker       |
| Server_2 | 172.17.0.3     | docker       |
| Server_3 | 172.17.0.4     | docker       |

 
宿主机修改/etc/ansible/host

```ini
[test]
172.17.0.2

172.17.0.3

172.17.0.4

[test]

ansible_ssh_user="远程主机用户名"

ansible_ssh_pass="远程主机密码"
```

![](https://cdn.hurra.ltd/img/20210310120137.png)

宿主机修改/etc/ansible/ansible.cfg

```ini
[defaults]

hostfile = hosts

# 远程主机用户名
remote_user = docker

host_key_checking = True
```

![](https://cdn.hurra.ltd/img/20210310120159.png)

将宿主机的`id_ras.pub`文件拷贝到远程主机的`authorized_key`中，注意此处远程登录的用户名为docker，本地为root用户

```sh
ansible all -m authorized_key -a "user=docker key='{{ lookup('file'，'.ssh/id_ras.pub') }}'" -k
```

输入宿主机的SSH密码

![](https://cdn.hurra.ltd/img/20210310115926.png)

尝试控制所有远程主机

![](https://cdn.hurra.ltd/img/20210310100850.png)



## 命令


### 限定主机变更


- limit参数限定

```sh
ansible 分组 -m command -a "指令" --limit "主机IP"
```


- IP限定

```sh
ansible 主机IP -m command -a "指令"
```


- 网段限定

```sh
ansible xxx.xxx.xxx.* -m command -a "systemctl status httpd"
```

只对web组中192.168.1.2主机操作

```sh
ansible web -m command -a "systemctl status sshd" --limit "192.168.1.2"

ansible web "192.168.1.2" -m command -a "systemctl status sshd"
```


### 查看所有主机

```sh
ansible all --list-hosts
```


### Ping

```sh
ansible 主机名/all -m ping
```


### copy模块

```sh
# 把主控端/root/目录的init.sh拷贝到到被控节点/tem/目录下
ansible all -m copy -a 'src=/root/init.hs dest=/tem/'
```


### file模块

```sh
# 更改被控节点上init.sh的权限为755，属主和属组为root
ansible all -m file -a "dest=/tem/init.sh mode=755 owner=root group=root"
```


### cron模块

```sh
# 在指定节点上定义一个计划任务，每隔3分钟到主控端更新一次时间
ansible all -m cron -a 'name="custom job" minute=*/3 hour=* day=* month=* weekday=* job="/usr/sbin/ntpdate 172.16.254.139"'
```


### group模块

```sh
# 在所有节点上创建一个组名为nolinux，gid为2014的组
ansible all -m group -a 'gid=2014 name=nolinux'
```


### user模块

```sh
# 在指定节点上创建一个用户名为nolinux，组为nolinux的用户
ansible all -m user -a 'name=nolinux groups=nolinux state=present'
```


### yum模块

在指定节点上安装 lrzsz 服务

```sh
ansible all -m yum -a "state=present name=httpd"
```


### service模块

```sh
# 启动指定节点上的 puppet 服务，并让其开机自启动
ansible all -m service -a 'name=puppet state=restarted enabled=yes'
```


### script模块

```sh
# 在指定节点上执行控制节点上的a.sh脚本
ansible all -m script -a '/root/a.sh'
```


### command模块

```sh
# 在指定节点上运行hostname命令
ansible all -m command -a 'hostname'
```


### raw模块

```sh
# 在all节点上运行hostname命令
ansible all -m raw-a 'hostname|tee'
```


### get_url模块

```sh
# 将http://10.1.1.116/favicon.ico文件下载到指定节点的/root/目录下
ansible all -m get_url -a 'url=http://10.1.1.116/favicon.ico dest=/root/'
```