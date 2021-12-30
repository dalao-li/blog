 <!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-16 23:24:23
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-29 03:50:20
-->

## xargs

`xargs`前命令的标准输出作为后命令的参数，管道符 `|` 是将前个命令的标准输出作为后个命令的标准输入

`xargs`可单独使用，也可与管道符、重定位符等与其他命令配合使用，默认动作是echo，默认分隔符为空白字符(空格，TAB，换行符)

- 真正执行的命令在xargs后面，接受xargs传参
```sh 
xargs 命令
```

```sh
echo "hello world" | xargs echo

ps -aux | grep vlc | grep -v grep | awk '{print $2}' | sudo xargs kill -9
```