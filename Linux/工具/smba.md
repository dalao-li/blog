<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-07-03 15:31:25
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 16:02:03
-->

## samba


### 安装


```sh
sudo apt install samba -y
```

### 配置


#### 共享目录

- 创建共享目录

```sh
sudo mkdir $HOME/share
```

- 设置目录权限

```
sudo chmod +x $HOME/share
```


#### 修改配置

- 修改smb.conf,末尾添加

```sh
sudo vim /etc/samba/smb.conf
```

```sh
[share]

# 设置共享目录
path = ${HOME}/share

# 设置访问用户
valid users = ${USER}

# 设置读写权限
writable = yes
```


- shell脚本(可选)

```sh
set_samba() {
    SHARE="share"

    sudo apt install samba -y

    sudo mkdir ${HOME}/${SHARE}

    sudo chmod +x $HOME/${SHARE}

    sudo bash -c cat >>/etc/samba/smb.conf <<EOF
[${SHARE}]

# 设置共享目录
path = ${HOME}/${SHARE}

# 设置访问用户
valid users = ${USER}

# 设置读写权限
writable = yes
EOF
}
```


#### 设置用户

- 创建smba用户(可选)

```sh
sudo useradd [smba用户]
```

- 设置共享密码

```sh
sudo smbpasswd -a ${USER}
```

- 重启samba服务

```sh
sudo service smbd restart
```


#### 测试

- Linux访问

```sh
smd://192.168.0.1/
```

- Windows访问

```sh
\\192.168.0.1\
```


### 映射


- Windows

![](https://cdn.hurra.ltd/img/20220703154339.png)