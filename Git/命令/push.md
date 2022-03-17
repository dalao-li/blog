<!--
 * @Description: 
 * @Version: 
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-25 23:07:05
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-17 21:42:38
-->

## push

`push` 将本地的分支版本上传到远程并合并

```sh
git push 远程主机名 本地分支名:远程分支名
```

- 上传本地分支到远程分支

```sh
# 建立本地到上游(远端)仓的链接，这样代码才能提交
git branch --set-upstream-to=origin/分支

git push origin 分支
```


### Registry

- 查看远程仓库

```sh
git remote -v
```

- 删除远程仓库

```sh
git remote rm [远程分支名]
```




