<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-07-03 15:31:25
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 09:41:36
-->

# samba

## 安装

```sh
sudo apt-get install samba -y
```

## 配置

### 设置目录

- 创建共享目录

```sh
sudo mkdir $HOME/share
```

- 设置目录权限

```sh
sudo chmod +x $HOME/share
```

### 修改配置

- 修改smb.conf

```sh
sudo vim /etc/samba/smb.conf
```

末尾添加

```sh
[share]

# 设置共享目录
path = ${HOME}/share

# 设置访问用户
valid users = samba

# 设置读写权限
writable = yes
```

### 设置用户

- 创建smba用户 samba

```sh
sudo useradd samba
```

- 设置samba 用户共享密码

```sh
sudo smbpasswd -a samba
```

- 重启samba服务

```sh
sudo service smbd restart
```

## 测试

### Linux访问

```sh
smd://192.168.0.1/
```

### Windows访问

```sh
\\192.168.0.1\
```

## 映射

### Windows

![](https://cdn.hurra.ltd/img/20220703154339.png)

## Shell脚本

```sh
set_samba() {
    SHARE_DIR="share"

    sudo apt install samba -y

    sudo mkdir ${HOME}/${SHARE_DIR}

    sudo chmod +x $HOME/${SHARE_DIR}

    sudo bash -c cat >>/etc/samba/smb.conf <<EOF
[${SHARE_DIR}]

path = ${HOME}/${SHARE_DIR}
valid users = ${USER}
writable = yes
EOF

}
```
