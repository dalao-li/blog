<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-24 23:33:20
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 20:05:12
-->


## reset


```sh
git reset --[soft/hard] [commit id]
```

修改倒数第三条commit

```sh
git reset -i HEAD~3
```



### --mixed(默认)


`不删除`工作空间改动代码,撤销`commit`,并撤销`git add .`

```sh
git reset --mixed HEAD^ 或

git reset HEAD^
```



### --soft


`不删除`工作空间改动代码,撤销`commit`,不撤销`git add .` 

```sh
git reset --soft HEAD^
```



### --hard


`删除`工作空间改动代码,撤销`commit`,撤销`git add .`

完成操作后就恢复到了上一次的commit状态

```sh
git reset --hard HEAD^
```