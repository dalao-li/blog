 <!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-16 23:24:23
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 09:48:02
-->

# xargs

`xargs` 将前面命令的标准输出作为后个命令的参数

管道符 `|` 是将前个命令的标准输出作为后个命令的标准输入

`xargs`可单独使用, 也可与管道符、重定位符等与其他命令配合使用, 默认动作是echo, 默认分隔符为空白字符(空格, TAB, 换行符)

真正执行的命令在xargs后面, 接受xargs传参

```sh
xargs 命令
```

- 二次显示

```sh
echo "hello world" | xargs echo
```

- 根据进程ID杀手进程

```sh
ps -aux | grep vlc | grep -v grep | awk '{print $2}' | sudo xargs kill -9
```
