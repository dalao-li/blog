<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-15 21:10:23
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 12:55:49
-->

## fetch

`git fetch` 是将远程的最新内容拉到本地，用户在检查了以后决定是否合并到本地分支中

### 取回指定分支

`git fetch 远程主机名 远程分支名`

取回origin主机的master分支  

```sh
git fetch origin master 
```
取回更新后，会返回一个`FETCH_HEAD` ，指的是某个`branch`在服务器上的最新状态.

### 查看更新信息

查看更新的文件名，作者和时间，代码

`git log -p FETCH_HEAD`

可以通过这些信息来判断是否产生冲突，以确定是否将更新merge到当前分支

