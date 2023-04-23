<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2023-04-23 10:14:12
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 10:15:32
-->

# remote

## 查看远程仓库

```sh
git remote -v
```

## 删除远程仓库

- 名称

```sh
git remote rm [远程分支名]
```

- URL

```sh
git remote set-url --del origin [远程 URL]
```

## 添加仓库地址

```sh
git remote add [远程用户名] [远程 URL]
```

### 添加多仓库地址

```sh
git remote set-url --add origin [远程 URL]
```

或配置.git/config

![](https://cdn.hurra.ltd/img/20211214220953.png)

此时`git push origin master` 就可一次性`push`到多个库