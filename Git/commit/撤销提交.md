<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 18:16:56
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-07 16:49:48
-->

修改 new.txt 文件内容，并 commit

![](https://cdn.hurra.ltd/img/20200717232121.png)

![](https://cdn.hurra.ltd/img/20200717232223.png)

## 硬回退

回到上一次提交，不管改动的代码，删除工作空间改动代码，撤销commit，撤销git add .

```sh
git reset --hard HEAD^
```

![](https://cdn.hurra.ltd/img/20200717233342.png)

![](https://cdn.hurra.ltd/img/20200717233417.png)

## 软回退

回到上一次提交，改动的代码不变，不删除工作空间改动代码，撤销commit，不撤销git add . 

```sh
git reset --soft HEAD^
```

![](https://cdn.hurra.ltd/img/20200717233725.png)

可发现commit已经撤回

![](https://cdn.hurra.ltd/img/20200717233745.png)

并且改动的代码未变

![](https://cdn.hurra.ltd/img/20200717233820.png)

## 回退到某次提交

```sh
git reset --[soft/hard] [commit id]
```