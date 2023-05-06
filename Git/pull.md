<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-12-15 21:12:13
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 10:14:21
-->

# Git 获取

## pull

`git pull` 将远程主机的最新内容拉下来后直接合并, 可能会产生冲突, 需手动解决

```sh
git pull [远程主机名] [远程分支名]:[本地分支名]
```

若远程分支是与当前分支合并, 则冒号后部分可省略

```sh
git pull origin master
```

### fetch

`git fetch` 将远程的最新内容拉到本地, 用户在检查了以后决定是否合并到本地分支中

```sh
git fetch 远程主机名 远程分支名
```

取回origin主机的master分支

```sh
git fetch origin master
```

取回更新后, 会返回一个`FETCH_HEAD`, 指的是某个`branch`在服务器上的最新状态.

- 查看更新的文件名, 作者和时间, 代码

```sh
git log -p FETCH_HEAD
```

可以通过这些信息来判断是否产生冲突, 以确定是否将更新merge到当前分支

### 原理

`git pull`的过程可分解为

从远程主机的分支拉取最新内容

```sh
git fetch origin 远程分支名
```

将拉取下来的最新内容合并到当前所在的分支中

```sh
git merge FETCH_HEAD
```