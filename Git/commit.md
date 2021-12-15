<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-09 00:00:26
-->

## 查看

```sh
git status
```

![](https://cdn.hurra.ltd/img/20200717225623.png)

![](https://cdn.hurra.ltd/img/20200717225752.png)


![](https://cdn.hurra.ltd/img/20200717225908.png)


## 添加到暂存区

```sh
git add .
```

`.` 指所有文件，add后也可具体指定文件

![](https://cdn.hurra.ltd/img/20200717230210.png)

```sh
# 撤回暂存区所有文件
git reset HEAD

# 撤回暂存区指定的文件
git reset HEAD 文件名
```

![](https://cdn.hurra.ltd/img/20200717231751.png)

## 提交

```sh
# 将暂存区里的改动给提交到本地的版本库
git commit -m "提交的注释信息"
```

![](https://cdn.hurra.ltd/img/20200717230921.png)

```sh
# 修改最近一次 commit
git commit --amend

# 修改倒数第三条commit
git rebase -i HEAD~3
```

## 提交记录

```sh
git log
```

![](https://cdn.hurra.ltd/img/20200717232555.png)