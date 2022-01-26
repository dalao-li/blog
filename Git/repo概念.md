## git

版本管理库，在$git$库中没有中心服务器的概念，真正的分布式

## repo

$repo$就是多个$git$库的管理工具。如果是多个$git$库同时管理，可以使用$repo$，当然使用$gerrit$，就必须用$repo$

## gerrit

$gerrit$是一个建立在$git$版本控制基础之上，基于$Web$的代码审查工具提

使用三者管理代码流程
1. repo init xxx初始化

2. repo sync xxx同步要改动的项目

3. 在该项目下面repo start xxx新建一个本地分支

4. 做好改动以后git commit本地提交改动

5. repo upload xxx将改动上传，等别人通过gerrit review

6. review如果有需要改动的地方，那本地改好后，git commit --amend来保存新的修改

7. repo upload 将新的改动上传

重复5-7步，直到$review$通过，然后$merge$改动，完毕


## init

```sh
repo init -u [URL] [OPTIONS]
```
初始化

## sync

```sh
repi sync [项目列表]
```

下载远程代码，并将本地代码更新到最新，这个过程称为“同步”.如果不使用任何参数，那么会对所有$repo$管理的进行同步操作


参数
|参数|含义|
|--|--|
|-$j$|开启多线程同步操作，加快sync命令执行速度|
|-$c$|只同步指定的远程分支|
