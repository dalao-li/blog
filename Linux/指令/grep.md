<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-20 20:16:43
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-11 06:30:27
-->

## grep

```sh
grep -[参数]
```

| 参数 | 说明                                   |
| ---- | -------------------------------------- |
| `c`  | 只输出匹配行的计数                     |
| `i`  | 匹配内容不区分大小写                   |
| `h`  | 查询多文件时不显示文件名               |
| `l`  | 查询多文件时只输出包含匹配字符的文件名 |
| `n`  | 显示匹配行及行号                       |
| `s`  | 不显示不存在或无匹配文本的错误信息     |
| `v`  | 显示不包含匹配文本的所有行             |


## 单查询

```sh
grep 模式 匹配项
```

查询3月10日16点30时间段内的ssh登录情况

```sh 
grep -n 'Mar 10 16:3' /var/log/secure
```
![](https://cdn.hurra.ltd/img/20210310173920.png)


## 与查询

```sh
grep '模式1' 匹配项 | grep '模式2'
```

查询3月10日16点30时间段内的ssh登录成功的情况

```sh
grep 'Mar 10 16:3' /var/log/secure | grep Accepted
```

![](https://cdn.hurra.ltd/img/20210310175209.png)


## 或查询

```sh
grep '模式1|模式2' 匹配项 或

grep -E '模式1|模式2' 匹配项
```


## 非查询

- 去除包含模式1的进程行，避免影响最终数据的正确性

```sh
grep -v 模式1 匹配项
```

查询VLC进程信息时排除grep本身影响
  
```sh
ps -aux | grep vlc | grep -v grep
```
![](https://cdn.hurra.ltd/img/20220102211819.png)

![](https://cdn.hurra.ltd/img/20220102211849.png)


## 正则

- 查看以pattern开头的行
  
```sh
grep ^pattern 匹配项
```

- 查找以pattern结尾的行
  
```sh
grep pattern$ 匹配项
```

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