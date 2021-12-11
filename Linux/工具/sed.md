<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-12 13:55:49
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-10 00:11:38
-->

## 匹配

```sh
sed -参数 '起始范围，结束范围  操作' 文件

# 例，打印file.txt 1-5行
sed -n '1，5 p' file.txt
```

| 参数         | 含义                                            |
| ------------ | ----------------------------------------------- |
| n            | 忽略执行过程的输出只输出结果                    |
| i  (`危险!`) | 所有改动将覆盖原文件，可用`-i.bak` 对原文件备份 |


| 范围           | 含义                                         |
| -------------- | -------------------------------------------- |
| 5              | 选择第5行，若为空则是选择所有行              |
| 2，5 或 2，+3  | 选择2到5行，共4行                            |
| 1~2            | 选择奇数行                                   |
| 2~2            | 选择偶数行                                   |
| 2，$           | 从第2行到文件结尾                            |
| /sys/，+3      | 选择出现sys字样的行，以及后面的三行          |
| /\^sys/，/mem/ | 选择以sys开头的行，和出现mem字样行之间的数据 |

| 操作 | 含义                                   |
| ---- | -------------------------------------- |
| p    | 对匹配内容进行打印                     |
| d    | 对匹配内容进行删除，此时要去掉`-n`参数 |
| w    | 将匹配内容写入其他地方                 |
| g    | 全部替换                               |

> 若字符串中带有路径符号 `/` 则可以用 `#` 做分隔符

```sh
# 例，Ubuntu换源
# . 匹配任意单个字符
# * 匹配紧挨在前面的字符任意次(0，1，多次)
sed -i 's#.*ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

# 例，文件替换，test.cfg原内容
...
deb.debian.org

security.debian.org
...

# 执行替换 
sed 's#.*debian.org#mirrors.aliyun.com#g' test.cfg

# test.cfg新内容
...
mirrors.aliyun.com

mirrors.aliyun.com
...
```