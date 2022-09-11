<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-06-29 23:34:07
-->

## WSL2


### 启用 Linux 子系统


打开 控制面板 -> 程序 -> 启用或关闭 $Windows$ 功能.找到"适用于 $Linux$ 的 $Windows$ 子系统"和"虚拟机平台", 勾选这两项, 并重新启动计算机.



### 切换到 WSL2


使用管理员用户打开 $CMD$, 运行:

```sh
wsl --set-default-version 2
```



### 添加 Docker 源


```sh
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

sudo add-apt-repository "deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu $(lsb_release -cs) stable"

sudo apt update
```



### 安装 Docker


```sh
sudo apt install -y docker-ce
```



### 设置权限


使用 docker info 命令出现问题

![](https://cdn.hurra.ltd/img/20200721210505.png)

这是权限不足的原因, 可使用以下命令解决

```sh
# 添加docker用户组
sudo groupadd docker

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker

# 更新用户组
newgrp docker
```



### 启动 Docker daemon


```sh
sudo service docker start
```

![](https://cdn.hurra.ltd/img/20200721210744.png)



### 关闭 WSL


![](https://cdn.hurra.ltd/img/20200721211633.png)

该进程是 WSL 的进程.它比较占内存, 不使用 WSL2 的时候可关闭, 方法如下, 使用管理员打开 CMD, 运行:

```s
wsl --shutdown
```