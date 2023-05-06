<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-05-05 13:54:03
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-05-05 13:56:21
-->

# reset

## --mixed(默认)

`不删除`工作空间改动代码, 撤销`commit`, 并撤销`git add .`

```sh
git reset --mixed HEAD^ 或

git reset HEAD^
```

- 修改倒数第三条commit

```sh
git reset -i HEAD~3
```

## --soft

`不删除`工作空间改动代码, 撤销`commit`, 不撤销`git add .`

```sh
git reset --soft HEAD^
```

## --hard

`删除`工作空间改动代码, 撤销`commit`, 撤销`git add .`

完成操作后就恢复到了上一次的commit状态

```sh
git reset --hard HEAD^
```
