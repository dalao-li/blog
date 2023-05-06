<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-05-05 13:57:47
 * @LastEditors: 
 * @LastEditTime: 2023-05-05 13:58:16
-->

# push

`push` 将本地的分支版本上传到远程并合并

```sh
git push [远程主机名] [本地分支名]:[远程分支名]
```

## 上传本地分支到远程分支

建立本地到上游(远端)仓的链接

```sh
git branch --set-upstream-to=origin/[分支]

git push origin [分支]
```