<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:20:22
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 08:19:01
-->

## 初始化

```sh
git init
```

![](https://cdn.hurra.ltd/img/20220112075837.png)

## 查看

```sh
# 所有分支
git branch -a

# 当前使用分支
git branch
```

![](https://cdn.hurra.ltd/img/20220112081438.png)

## 建立

```sh
git branch 分支名
```

![](https://cdn.hurra.ltd/img/20220112081747.png)


## 切换

```sh
# 切换到分支
git checkout 分支名

# 创建新分支并切换到它
git checkout -b 分支名
```

![](https://cdn.hurra.ltd/img/20220112081849.png)


## 删除

```sh
git branch -d 分支名
```


## 合并

- 合并A分支到当前分支

```sh
git merge A分支
```