<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-09 10:48:54
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-13 02:20:18
-->


![](https://cdn.hurra.ltd/img/20210308111903.png)

## Linux安装

```sh
# 安装jdk1.8
yum -y install java-1.8.0-openjdk* 

# 安装Jenkins
sudo wget https://mirrors.tuna.tsinghua.edu.cn/jenkins/war/2.284/jenkins.war

# 运行
java -jar -Dhudson.security.csrf.GlobalCrumbIssuerConfiguration.DISABLE_CSRF_PROTECTION=true  jenkins.war --httpPort=8080
```

![](https://cdn.hurra.ltd/img/20210317144540.png)

![](https://cdn.hurra.ltd/img/20210309093313.png)

![](https://cdn.hurra.ltd/img/20210309093347.png)

![](https://cdn.hurra.ltd/img/20210309094244.png)


## Windows安装

```sh
# 用管理员身份启动cmd，进入jenkins安装根目录
C:\Windows\System32\config\systemprofile\AppData\Local\Jenkins
```

```sh
# 启动命令
net start jenkins

# 关闭命令
net stop jenkins
```

## Docker部署
```sh
docker run -u root -itd \
  -p 8080:8080 -p 50000:50000 \
  -v /var/jenkins_home:/var/jenkins_home \
  -v /var/run/docker.sock:/var/run/docker.sock \
  jenkinsci/blueocean
```

![](https://cdn.hurra.ltd/img/20210308113221.png)

![](https://cdn.hurra.ltd/img/20210308113523.png)

## 示例

使用Jenkins实现对Python程序的持续集成持续部署

建立仓库

![](https://cdn.hurra.ltd/img/20210309105037.png)

新建Item

![](https://cdn.hurra.ltd/img/20210309105123.png)

![](https://cdn.hurra.ltd/img/20210309105307.png)

填写git仓库地址

![](https://cdn.hurra.ltd/img/20210309105406.png)

填写构建时执行的脚本

![](https://cdn.hurra.ltd/img/20210309105442.png)

选择立即构建，然后可以看到工作空间里的文件夹

![](https://cdn.hurra.ltd/img/20210309105553.png)

查看控制台日志发现构建成功

![](https://cdn.hurra.ltd/img/20210309105711.png)

本地修改代码，push

![](https://cdn.hurra.ltd/img/20210309111504.png)

再次构建项目

![](https://cdn.hurra.ltd/img/20210309111613.png)