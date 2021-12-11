 <!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-16 23:24:23
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-10 23:06:22
-->

## 概念

`xargs`前命令的标准输出作为后命令的参数，管道符 `|` 是将前个命令的标准输出作为后个命令的标准输入

`xargs`可单独使用，也可与管道符、重定位符等与其他命令配合使用，默认动作是echo，默认分隔符为空白字符(空格，TAB，换行符)

```sh 
# 真正执行的命令在xargs后面，接受xargs传参
xargs 命令

# echo "hello world" | xargs echo

# ps -aux | grep vlc | grep -v grep | awk '{print $2}' | sudo xargs kill -9
```
![](https://cdn.hurra.ltd/img/20210330125053.png)