<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-20 20:16:43
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-29 03:53:29
-->

## grep

```sh
grep -[参数]
```

| 参数 | 说明                                   |
| ---- | -------------------------------------- |
| c    | 只输出匹配行的计数                     |
| i    | 匹配内容不区分大小写                   |
| h    | 查询多文件时不显示文件名               |
| l    | 查询多文件时只输出包含匹配字符的文件名 |
| n    | 显示匹配行及行号                       |
| s    | 不显示不存在或无匹配文本的错误信息     |
| v    | 显示不包含匹配文本的所有行             |

## 单查询

```sh
grep 模式 文件路径
```

- 查询3月10日16点30时间段内的ssh登录情况

```sh 
grep -n 'Mar 10 16:3' /var/log/secure
```
![](https://cdn.hurra.ltd/img/20210310173920.png)

## 与查询

```sh
grep '模式1' 文件路径 | grep '模式2'
```

- 查询3月10日16点30时间段内的ssh登录成功的情况

```sh
grep 'Mar 10 16:3' /var/log/secure | grep Accepted
```

![](https://cdn.hurra.ltd/img/20210310175209.png)

## 或查询

```sh
grep '模式1|模式2' filepath 或

grep -E '模式1|模式2' filepath
```

## 非查询

```sh
# 去除包含grep的进程行，避免影响最终数据的正确性
grep -v 模式 文件路径
```

- 查询VLC进程信息
  
```sh
ps -aux | grep vlc | grep -v grep
```

## 正则

- 查看以pattern开头的行
  
```sh
grep ^pattern filepath
```

- 查找以pattern结尾的行
  
```sh
grep pattern$ filepath
```

查找/root/test.txt文件中含有human的句子
  
```sh
grep human /root/test.txt
```
![](https://cdn.hurra.ltd/img/20210310151418.png)

```sh
# 例，查找/root/test.txt文件中以The开头的句子
grep ^The /root/test.txt
```
![](https://cdn.hurra.ltd/img/20210310151535.png)