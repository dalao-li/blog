<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-13 12:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-01 21:54:15
-->

## remote


### 仓库

- 查看远程仓库

```sh
git remote -v
```


### 删除

- 删除远程仓库

```sh
git remote rm [远程分支名]
```

```sh
git remote set-url --del origin [远程 URL]
```


### 添加

```sh
git remote add [远程用户名] [远程 URL]
```

- 添加多地址

```sh
git remote set-url --add origin [远程 URL]
```

或配置.git/config

![](https://cdn.hurra.ltd/img/20211214220953.png)

此时`git push origin master` 就可一次性`push`到多个库