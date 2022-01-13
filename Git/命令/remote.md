<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-13 12:57:16
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 12:58:32
-->

### remote

### 删除远程地址



`git remote set-url --del origin [远程 URL]`

### 添加远程地址


`git remote add [远程用户名] [远程 URL]`

### 添加多个远程地址

在使用git时,可将库同时push到多个托管远端

- 方法1，添加第二个地址
  
`git remote set-url --add origin [远程 URL]`

- 方法2，配置.git/config

![](https://cdn.hurra.ltd/img/20211214220953.png) 

此时`git push origin master` 就可一次性`push`到多个库