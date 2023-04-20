<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-20 15:38:49
-->

# Git 提交过程

![](https://cdn.hurra.ltd/img/git.svg)

![](https://cdn.hurra.ltd/img/2022-3-17-2310.svg)

## init

### 新建代码仓库

- 当前目录

```sh
git init
```

- 指定目录

```sh
git init 项目名
```

![](https://cdn.hurra.ltd/img/20220112075837.png)

### 查看文件状态

```sh
git status
```

## add

### 添加

- 添加所有文件到暂存区

```sh
git add .
```

### 撤回

- 撤回暂存区文件

```sh
# 默认所有文件, 也可指定文件
git reset HEAD
```

![](https://cdn.hurra.ltd/img/20220112080614.png)

## commit

![](https://cdn.hurra.ltd/img/2022-3-18-2158.svg)

将暂存区里的改动给提交到本地的版本库

### 添加注释

- 使用编辑器添加注释

```sh
git commit
```

- 直接添加注释

```sh
git commit -m "注释"`
```

![](https://cdn.hurra.ltd/img/20220112081127.png)

### 修改

- 修改最近一次 `commit`

```sh
git commit --amend
```

若修改已经`push`到远程分支, 则push时需加`--force-with-lease`参数

```sh
git push --force-with-lease
```

## push

`push` 将本地的分支版本上传到远程并合并

```sh
git push [远程主机名] [本地分支名]:[远程分支名]
```

### 上传本地分支到远程分支

建立本地到上游(远端)仓的链接

```sh
git branch --set-upstream-to=origin/[分支]

git push origin [分支]
```

## reset

```sh
git reset --[soft/hard] [commit id]
```

修改倒数第三条commit

```sh
git reset -i HEAD~3
```

### --mixed(默认)

`不删除`工作空间改动代码, 撤销`commit`, 并撤销`git add .`

```sh
git reset --mixed HEAD^ 或

git reset HEAD^
```

### --soft

`不删除`工作空间改动代码, 撤销`commit`, 不撤销`git add .` 

```sh
git reset --soft HEAD^
```

### --hard

`删除`工作空间改动代码, 撤销`commit`, 撤销`git add .`

完成操作后就恢复到了上一次的commit状态

```sh
git reset --hard HEAD^
```
