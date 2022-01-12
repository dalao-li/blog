<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-15 21:12:13
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 08:24:05
-->

## pull

`git pull` 是将远程主机的最新内容拉下来后直接合并，可能会产生冲突，需手动解决.

```sh
git pull 远程主机名 远程分支名:本地分支名
```

若远程分支是与当前分支合并，则冒号后部分可省略

```
git pull origin master
```

`git pull`的过程可分解为

- 从远程主机的master分支拉取最新内容
 
`git fetch origin master`

- 将拉取下来的最新内容合并到当前所在的分支中

`git merge FETCH_HEAD`