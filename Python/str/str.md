<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-01 20:37:22
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 00:38:36
-->


## 字符串


### 切片


| 语法          | 范围         |
| ------------- | ------------ |
| $[start:end]$ | [start,end)  |
| $[start:]$    | [start,末尾] |
| $[:end]$      | [开头,end)   |


```py
s = "HELLO WORLD!"

# ELLO
s[1:6]

# LO WORLD!
s[3:]

# HELLO
s[:5]
```



### 查找


#### 子串查找

```py
find(s, start, end)
```

在字符串[start,end]范围里查找子串s,若存在返回首个索引,否则返回-1

```py
s = "abcdefg"

x = s.find("cd", 0, -1)

# 2
print(x)
```


#### 次数查找

```py
conut(s, start, end)
```

返回字符串[start,end]范围内s出现的次数



### 过滤


#### 子符过滤

```py
strip(str)
```

过滤字符串开头与结尾中位于str中的字符

```py
a = "a12312a"

# 12312
print(a.strip('a'))

# 2312
print(a.strip("a1"))

# 3
print(a.strip("12a"))
```


### 格式化

```py
name = "Dalao"

age = 21
```

- %

```py
s = "My name is %s , I am %d years old"%(name,age)
```

- format

```py
s = "My name is {0} , I am {1} years old".format(name,age)
```

- dict

```py
d = {'name':"Dalao" , 'age':21}

s = "My name is %(name)s , I am %(age)d years old"%data
```