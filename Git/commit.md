<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:02:13
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 08:13:04
-->

## 查看

```sh
git status
```

![](https://cdn.hurra.ltd/img/20220112080241.png)


## 添加到暂存区

```sh
git add .
```

`.` 指所有文件，也可具体指定文件，此处添加main.cpp文件

- 撤回暂存区文件

```sh
# 默认所有文件，可指定文件
git reset HEAD 
```

![](https://cdn.hurra.ltd/img/20220112080614.png)

## 提交

- 将暂存区里的改动给提交到本地的版本库

```sh
# 使用编辑器添加注释
git commit

# 直接添加注释
git commit -m "提交的注释信息"
```

![](https://cdn.hurra.ltd/img/20220112081127.png)

- 修改提交

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

![](https://cdn.hurra.ltd/img/20220112081301.png)