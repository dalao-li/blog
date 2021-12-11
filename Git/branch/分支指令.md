<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:20:22
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-07 02:17:21
-->

## 查看

```sh
# 所有分支
git branch -a

# 当前使用分支
git branch
```

![](https://cdn.hurra.ltd/img/20200718111415.png)

## 建立

```sh
git branch 分支名
```

![](https://cdn.hurra.ltd/img/20200718111645.png)

## 切换

```sh
# 切换到分支
git checkout 分支名

# 创建新分支并切换到它
git checkout -b 分支名
```

![](https://cdn.hurra.ltd/img/20200718112028.png)

## 删除

```sh
git branch -d 分支名
```

![](https://cdn.hurra.ltd/img/20200718112414.png)

## 合并

```sh
# 合并某分支到当前分支
git merge 某分支
```