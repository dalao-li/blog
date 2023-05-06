<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-05-05 13:59:09
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