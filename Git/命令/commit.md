<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-16 20:23:16
-->

## 提交

### init

- 新建代码仓库(当前目录)

```sh
git init
```

- 新建代码仓库(指定目录)
  
```sh
git init 项目名
```

![](https://cdn.hurra.ltd/img/20220112075837.png)

### status

- 查看文件状态

```sh
git status
```

![](https://cdn.hurra.ltd/img/20220112080241.png)

### add

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

### log

提交记录

```sh
git log
```

![](https://cdn.hurra.ltd/img/20220112081301.png)

### commit

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


## commit参数 

### --amend

- 修改最近一次 commit

```sh
git commit --amend
```

若修改已经push到远程分支，则push时需加`--force-with-lease`参数

```sh
git push --force-with-lease
```

### rebase

- 修改倒数第三条commit

```sh
git rebase -i HEAD~3
```


### --mixed 

不删除工作空间改动代码，撤销commit，并且撤销git add . 操作,默认参数,git reset --mixed HEAD^ 和 git reset HEAD^ 效果是一样的
 

### --soft  

不删除工作空间改动代码，撤销commit，不撤销git add . 


### --hard

删除工作空间改动代码，撤销commit，撤销git add . ,完成操作后就恢复到了上一次的commit状态


