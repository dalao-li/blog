<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-02-21 18:34:05
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-15 10:48:49
-->


# sed


## 文本编辑

```sh
sed -参数 '起始范围, 结束范围 操作' 路径
```

### 参数

| 参数 | 含义                                |
| ---- | ----------------------------------- |
| `-n` | 忽略执行过程的输出只输出结果        |
| `-i` | 改动将覆盖原文件, 可用`-i.bak` 备份 |


### 范围

| 范围          | 含义                          |
| ------------- | ----------------------------- |
| 5             | 选择第5行, 若为空则选择所有行 |
| 2, 5 或 2, +3 | 选择2到5行, 共4行             |
| 1~2           | 选择奇数行                    |
| 2~2           | 选择偶数行                    |
| 2, $          | 从第2行到文件结尾             |


### 操作

| 操作 | 含义                             |
| ---- | -------------------------------- |
| `p`  | 打印匹配内容                     |
| `d`  | 删除匹配内容, 此时要去掉`-n`参数 |
| `w`  | 将匹配内容写入其他地方           |
| `g`  | 全部替换                         |

若字符串中带有路径符号 `/`, 可以用 `#` 分隔



## 打印


- 打印file.txt 1-5行
  
```sh
sed -n '1, 5 p' file.txt
```


## 添加


### 第一行前添加

```sh
sed -i '1i内容' 路径
```


### 最后一行行前添加

```sh
sed -i '$i内容' 路径
```


#### 最后一行行后添加

```sh
sed -i '$a内容' 路径
```



## 替换


- Ubuntu换源, 修改/etc/apt/sources.list

```sh
sed -i 's#security.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list

sed -i 's#cn.archive.ubuntu.com#mirrors.aliyun.com#g' /etc/apt/sources.list
```
