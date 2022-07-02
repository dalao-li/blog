<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 01:10:53
-->


## 工具


- git

版本管理库,在git库中没有中心服务器的概念,真正的分布式

- repo

repo就是多个git库的管理工具。如果是多个git库同时管理,可以使用repo,当然使用gerrit,就必须用repo

- gerrit

gerrit是一个建立在git版本控制基础之上,基于Web的代码审查工具



### 管理流程

1. 初始化

```sh
repo init xxx
```

2. 同步要改动的项目

```sh
repo sync xxx
```

3. 新建本地分支

```sh
repo start 分支名
```

4. 做好改动以后git commit本地提交改动

5. 改动上传,等别人通过review

```sh
repo upload xxx
```

6. review如果有需要改动的地方,那本地改好后,`git commit --amend`来保存新的修改

7. repo upload 将新的改动上传

重复5-7步,直到review通过,然后merge改动,完毕



## Repo指令


### init

```sh
repo init -u [URL] [OPTIONS]
```
初始化



### sync

```sh
repi sync [项目列表]
```

下载远程代码,并将本地代码更新到最新,这个过程称为“同步”.如果不使用任何参数,那么会对所有$repo$管理的进行同步操作


参数

| 参数 | 含义                            |
| ---- | ------------------------------- |
| `-j` | 开启多线程同步操作,加快执行速度 |
| `-c` | 只同步指定的远程分支            |
