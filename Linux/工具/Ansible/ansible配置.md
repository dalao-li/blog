<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-08 09:36:50
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-06 13:19:51
-->


## 概念

$Ansible$是一个配置管理和应用部署工具.

$Ansible$可以去对服务器上($1-N$台)的一些系统应用进行配置管理，如更改部分参数，安装软件应用等，本质是在多设备按情况(判断循环)指定每台设备要执行的命令

## 安装

```sh
# 新增 epel-release 第三方套件来源，安装Ansible
yum install -y epel-release ansible

# 配置文件/etc/ansible/ansible.cfg
```

## 测试

建立两个容器server1，server2，并用ansible对其进行控制

```sh
docker run -itd --name server1 -P chusiang/ansible-managed-node:ubuntu-14.04
```

修改/etc/ansible/ansible.cfg文件

```ini
[defaults]

# 档案路径
hostfile = hosts

# 被控端用户名
remote_user = docker

# 不询问是否加入密钥
host_key_checking = False
```

修改/etc/ansible/hosts

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

```sh
# 控制所有受控主机输出
ansible all -m command -a 'echo Hello World!'
```

![](https://cdn.hurra.ltd/img/20210308100822.png)

## 批量SSH免密

通过$Ansible$批量给多台远程主机设置SSH免密

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
ansible all -m authorized_key -a "user=远程用户名 key='{{ lookup('file'，'本地id_rsa.pub路径') }}'" -k
```

输入宿主机的SSH密码

![](https://cdn.hurra.ltd/img/20210310115926.png)

尝试控制所有远程主机

![](https://cdn.hurra.ltd/img/20210310100850.png)