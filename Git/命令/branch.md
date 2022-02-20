<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:20:22
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-20 17:37:48
-->

## branch


### 查看

- 所有分支

```sh
git branch -a
```

- 当前使用分支

```sh
git branch
```

![](https://cdn.hurra.ltd/img/20220112081438.png)


### 建立

```
git branch 分支名
```

![](https://cdn.hurra.ltd/img/20220112081747.png)


### 切换

- 切换到分支

```sh
git checkout 分支名
```

- 创建新分支并切换到它

```sh
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
