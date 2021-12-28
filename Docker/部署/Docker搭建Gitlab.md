<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-20 20:16:43
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-28 22:56:35
-->

## 搭建

Docker搭建Gitlab占用内存较大，若在虚拟机内操作建议虚拟机内存大于4G

```sh
#!/bin/sh

docker pull gitlab/gitlab-ce

# gitlab数据目录
gitlab_dir=/srv/gitlab

# 主机IP
ip=.......

# 建立服务器配置，日志，数据目录
for i in config logs data;do 
    mkdir -p ${gitlab_dir}/${i}
done

docker run -itd \
    --hostname ${ip} \
    -p 443:443 -p 80:80 -p 10080:22 \
    --name gitlab \
    -v ${gitlab_dir}/config:/etc/gitlab \
    -v ${gitlab_dir}/logs:/var/log/gitlab \
    -v ${gitlab_dir}/data:/var/opt/gitlab \
    gitlab/gitlab-ce:latest
```

修改gitlab配置文件/srv/gitlab/config/gitlab.rb

```sh
# 改SSH端口为10080，以便不和宿主机22端口冲突
gitlab_rails['gitlab_shell_ssh_port'] = 10080

# 配置外部访问地址 
external_url 'http://192.168.162.106'
```

进入Gitlab容器，重启Gitlab服务

```sh
# 重新应用gitlab的配置
docker exec -it gitlab gitlab-ctl reconfigure
```

耐心等待一段时间，成功之后运行状态会显示healthy字样，这时就可以访问gitlab私服


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

