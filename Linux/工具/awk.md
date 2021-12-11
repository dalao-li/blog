<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 11:23:08
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-10 23:05:48
-->

## 概念

| 命令 | 作用     |
| ---- | -------- |
| awk  | 文本分析 |
| grep | 文本查找 |
| sed  | 文本编辑 |

`awk`是把文件逐行读入，以空格为默认分隔符将每行切片，再对切开的部分进行各种分析处理

```sh
awk [参数] '{pattern action}' {文件名}
```
| 参数    | 含义                                   |
| ------- | -------------------------------------- |
| pattern | awk 在数据中查找的内容                 |
| action  | 在找到匹配内容时执行的命令             |
| {}      | 用于根据特定的模式对一系列指令进行分组 |

```sh
# 查看登录的用户名，则可使用
last -n 5 | awk '{print $1}'
```

![](https://cdn.hurra.ltd/img/20210310112806.png)

