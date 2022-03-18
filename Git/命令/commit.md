<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-18 22:08:58
-->


![](https://cdn.hurra.ltd/img/git.svg)

## init

- 新建代码仓库(当前目录)

```sh
git init
```

- 新建代码仓库(指定目录)
  
```sh
git init 项目名
```

![](https://cdn.hurra.ltd/img/20220112075837.png)


- 查看文件状态

```sh
git status
```


## add

- 添加所有文件到暂存区

```sh
git add .
```

- 撤回暂存区文件

```sh
# 默认所有文件，也可指定文件
git reset HEAD
```

![](https://cdn.hurra.ltd/img/20220112080614.png)


## commit

![](https://cdn.hurra.ltd/img/2022-3-18-2158.svg)

将暂存区里的改动给提交到本地的版本库

- 使用编辑器添加注释

```sh
git commit
```

- 直接添加注释

```sh
git commit -m "注释"`
```

![](https://cdn.hurra.ltd/img/20220112081127.png)


- 修改最近一次 `commit`

```sh
git commit --amend
```

若修改已经`push`到远程分支，则push时需加`--force-with-lease`参数

```sh
git push --force-with-lease
```


