<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-25 22:30:43
-->

## commit

### 含义

将暂存区里的改动给提交到本地的版本库

- `git commit`

使用编辑器添加注释

- `git commit -m "注释"`

直接添加注释 

![](https://cdn.hurra.ltd/img/20220112081127.png)


### --amend

修改最近一次 commit 

```sh
git commit --amend
```

若修改已经push到远程分支，则push时需加`--force-with-lease`参数

```sh
git push --force-with-lease
```

### rebase

- 修改倒数第三条commit 

`git rebase -i HEAD~3`


