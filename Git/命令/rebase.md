<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-17 22:29:38
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-18 00:10:46
-->


## rebase


```sh
git reset --[soft/hard] [commit id]
```

修改倒数第三条commit

```sh
git reset -i HEAD~3
```

- --mixed(默认参数)

不删除工作空间改动代码，撤销`commit`，并且撤销`git add .` 操作，`git reset --mixed HEAD^` 和 `git reset HEAD^` 效果是一样的


- --soft

不删除工作空间改动代码，撤销`commit`，不撤销`git add .` 

```sh
git reset --soft HEAD^
```

- --hard

删除工作空间改动代码，撤销`commit`，撤销`git add .`，完成操作后就恢复到了上一次的commit状态

```sh
git reset --hard HEAD^
```