<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 11:23:08
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 22:19:30
-->


## awk

`awk` 文本分析

将文件逐行读入，以空格为默认分隔符将每行切片，再对切开的部分进行各种分析处理

> `awk [参数] '{pattern action}' {文件名}`

| 参数    | 含义                                   |
| ------- | -------------------------------------- |
| pattern | awk 在数据中查找的内容                 |
| action  | 在找到匹配内容时执行的命令             |
| {}      | 用于根据特定的模式对一系列指令进行分组 |

-  查看登录的用户名
  
```sh
last -n 5 | awk '{print $1}'
```

![](https://cdn.hurra.ltd/img/20220109114810.png)


## grep

`grep` 文本查找

> `grep -[参数]`

| 参数 | 说明                                   |
| ---- | -------------------------------------- |
| `c`  | 只输出匹配行的计数                     |
| `i`  | 匹配内容不区分大小写                   |
| `h`  | 查询多文件时不显示文件名               |
| `l`  | 查询多文件时只输出包含匹配字符的文件名 |
| `n`  | 显示匹配行及行号                       |
| `s`  | 不显示不存在或无匹配文本的错误信息     |
| `v`  | 显示不包含匹配文本的所有行             |


- 单查询

> `grep 模式 匹配项`

查询3月10日16点30时间段内的ssh登录情况

```sh 
grep -n 'Mar 10 16:3' /var/log/secure
```
![](https://cdn.hurra.ltd/img/20210310173920.png)


-  与查询

> `grep '模式1' 匹配项 | grep '模式2'`

查询3月10日16点30时间段内的ssh登录成功的情况

```sh
grep 'Mar 10 16:3' /var/log/secure | grep Accepted
```

![](https://cdn.hurra.ltd/img/20210310175209.png)


- 或查询

> `grep '模式1|模式2' 匹配项` 或 `grep -E '模式1|模式2' 匹配项`

- 非查询

> `grep -v 模式1 匹配项`

去除包含模式1的进程行，避免影响最终数据的正确性

查询VLC进程信息时排除grep本身影响
  
```sh
ps -aux | grep vlc | grep -v grep
```
![](https://cdn.hurra.ltd/img/20220102211819.png)

![](https://cdn.hurra.ltd/img/20220102211849.png)


### 正则

- 查看以pattern开头的行
  
> `grep ^pattern 匹配项`

- 查找以pattern结尾的行
  
> `grep pattern$ 匹配项`

查找/root/test.txt文件中含有human的句子
  
```sh
grep human /root/test.txt
```
![](https://cdn.hurra.ltd/img/20210310151418.png)

查找/root/test.txt文件中以The开头的句子

```sh
grep ^The /root/test.txt
```
![](https://cdn.hurra.ltd/img/20210310151535.png)


## sed

`sed` 文本编辑

> `sed -参数 '起始范围，结束范围  操作' 文件`

打印file.txt 1-5行
  
```sh
sed -n '1，5 p' file.txt
```

| 参数         | 含义                                        |
| ------------ | ------------------------------------------- |
| n            | 忽略执行过程的输出只输出结果                |
| i  (`危险!`) | 改动将覆盖原文件，可用`-i.bak` 对原文件备份 |


| 范围          | 含义                          |
| ------------- | ----------------------------- |
| 5             | 选择第5行，若为空则选择所有行 |
| 2，5 或 2，+3 | 选择2到5行，共4行             |
| 1~2           | 选择奇数行                    |
| 2~2           | 选择偶数行                    |
| 2,$           | 从第2行到文件结尾             |

| 操作 | 含义                                   |
| ---- | -------------------------------------- |
| p    | 对匹配内容进行打印                     |
| d    | 对匹配内容进行删除，此时要去掉`-n`参数 |
| w    | 将匹配内容写入其他地方                 |
| g    | 全部替换                               |

若字符串中带有路径符号 `/` ，可以用 `#` 分隔


### 替换

- 第一行前添加字符串

> `sed -i '1i添加的内容' 文件路径`

- 最后一行`行前`添加字符串

> `sed -i '$i添加的内容' 文件路径`

- 最后一行`行后`添加字符串

> `sed -i '$a添加的内容' 文件路径`

Ubuntu换源，修改/etc/apt/sources.list

```sh
sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
```