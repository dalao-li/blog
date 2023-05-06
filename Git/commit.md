<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-05-05 13:59:21
 * @LastEditors: 
 * @LastEditTime: 2023-05-05 13:59:31
-->

# commit

![](https://cdn.hurra.ltd/img/2022-3-18-2158.svg)

将暂存区里的改动给提交到本地的版本库

## 添加注释

- 使用编辑器添加注释

```sh
git commit
```

- 直接添加注释

```sh
git commit -m "注释"`
```

![](https://cdn.hurra.ltd/img/20220112081127.png)

## 修改

- 修改最近一次 `commit`

```sh
git commit --amend
```

若修改已经`push`到远程分支, 则push时需加`--force-with-lease`参数

```sh
git push --force-with-lease
```