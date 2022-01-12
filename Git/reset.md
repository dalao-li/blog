<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:16:56
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 08:30:23
-->


## 硬回退

回到上一次提交，不管改动的代码，删除工作空间改动代码，撤销commit，撤销git add .

```sh
git reset --hard HEAD^
```


## 软回退

回到上一次提交，改动的代码不变，不删除工作空间改动代码，撤销commit，不撤销git add . 

```sh
git reset --soft HEAD^
```


## 回退到某次提交

```sh
git reset --[soft/hard] [commit id]
```