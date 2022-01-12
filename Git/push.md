<!--
 * @Description: 
 * @Version: 
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-25 23:07:05
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 08:27:50
-->

## push

`push` 将本地的分支版本上传到远程并合并

```sh
git push 远程主机名 本地分支名:远程分支名
```

- 上传本地分支到远程分支

```sh
# 建立本地到上游(远端)仓的链接，这样代码才能提交上去
git branch --set-upstream-to=origin/分支

git push origin 分支
```

## Registry

- 查看远程仓库

```sh
git remote -v
```

- 删除远程仓库

```sh
git remote rm [origin name]
```

## 远程地址

- 删除远程地址

```sh
git remote set-url --del origin [origin url]
```

- 添加远程地址

```sh
git remote add [origin name] [origin url]
```

- 添加多个远程地址

在使用git时,可将库同时push到多个托管远端

1）方法1，命令行
  
```sh
# 添加首个远程地址
git remote add origin 

# 添加第二个地址
git remote set-url --add origin [origin url]
```

2）方法2，配置.git/config

![](https://cdn.hurra.ltd/img/20211214220953.png) 

此时`git push origin master` 就可一次性`push`到多个库


