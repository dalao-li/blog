<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-20 20:16:43
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-11 22:56:55
-->

$Docker$搭建$Gitlab$占用内存较大，若在虚拟机内操作建议虚拟机内存大于$4G$

## 搭建

```sh
#!/bin/sh

docker pull gitlab/gitlab-ce

# gitlab数据目录
GITLAB_HOME=/srv/gitlab

# 主机IP
IP=.......

# 建立服务器配置，日志，数据目录
for i in config logs data;do 
    mkdir -p $GITLAB_HOME/$i
done

docker run -itd \
    --hostname ${IP} \
    -p 443:443 -p 80:80 -p 10080:22 \
    --name gitlab \
    -v ${GITLAB_HOME}/config:/etc/gitlab \
    -v ${GITLAB_HOME}/logs:/var/log/gitlab \
    -v ${GITLAB_HOME}/data:/var/opt/gitlab \
    gitlab/gitlab-ce:latest
```

修改$gitlab$配置文件/srv/gitlab/config/gitlab.rb

```sh
# 改SSH端口为10080，以便不和宿主机22端口冲突
gitlab_rails['gitlab_shell_ssh_port'] = 10080

# 配置外部访问地址 
external_url 'http://192.168.162.106'
```

进入$Gitlab$容器，重启$Gitlab$服务

```sh
# 重新应用gitlab的配置
docker exec -it gitlab gitlab-ctl reconfigure
```

耐心等待一段时间，成功之后运行状态会显示$healthy$字样，这时就可以访问$gitlab$私服


```sh
# 重启gitlab服务
docker exec -it gitlab gitlab-ctl restart

# 查看gitlab运行状态
docker exec -it gitlab gitlab-ctl status
```
![](https://cdn.hurra.ltd/img/20210319153023.png)

![](https://cdn.hurra.ltd/img/20210319173035.png)

初始用户名为root

![](https://cdn.hurra.ltd/img/20210319173322.png)

![](https://cdn.hurra.ltd/img/20210319173621.png)

![](https://cdn.hurra.ltd/img/20210319173747.png)

![](https://cdn.hurra.ltd/img/20210319174441.png)

![](https://cdn.hurra.ltd/img/20210319174746.png)

![](https://cdn.hurra.ltd/img/20210319175142.png)

