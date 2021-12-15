## fetch

`git fetch` 是将远程的最新内容拉到本地，用户在检查了以后决定是否合并到本地分支中

- 取回指定分支

```sh
git fetch 远程主机名 远程分支名

# 例，取回origin主机的master分支  git fetch origin master 
```
取回更新后，会返回一个`FETCH_HEAD` ，指的是某个`branch`在服务器上的最新状态.

```sh
# 查看更新信息，如更新的文件名，作者和时间，代码
git log -p FETCH_HEAD
```

可以通过这些信息来判断是否产生冲突，以确定是否将更新merge到当前分支.

## pull

`git pull` 是将远程主机的最新内容拉下来后直接合并，可能会产生冲突，需手动解决.

```sh
git pull 远程主机名 远程分支名:本地分支名

# 若远程分支是与当前分支合并，则冒号后部分可省略
# git pull origin master
```

`git pull`的过程可分解

```sh
# 从远程主机的master分支拉取最新内容 
git fetch origin master

# //将拉取下来的最新内容合并到当前所在的分支中
git merge FETCH_HEAD 
```

`git fetch` 是将远程的最新内容拉到本地，用户在检查了以后决定是否合并到本地分支中

- 取回指定分支

```sh
git fetch 远程主机名 远程分支名

# 例，取回origin主机的master分支  git fetch origin master 
```
取回更新后，会返回一个`FETCH_HEAD` ，指的是某个`branch`在服务器上的最新状态.

```sh
# 查看更新信息，如更新的文件名，作者和时间，代码
git log -p FETCH_HEAD
```

可以通过这些信息来判断是否产生冲突，以确定是否将更新merge到当前分支.

## pull

`git pull` 是将远程主机的最新内容拉下来后直接合并，可能会产生冲突，需手动解决.

```sh
git pull 远程主机名 远程分支名:本地分支名

# 若远程分支是与当前分支合并，则冒号后部分可省略
# git pull origin master
```

`git pull`的过程可分解

```sh
# 从远程主机的master分支拉取最新内容 
git fetch origin master

# //将拉取下来的最新内容合并到当前所在的分支中
git merge FETCH_HEAD 
```
