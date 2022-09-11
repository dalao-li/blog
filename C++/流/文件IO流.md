<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-08-22 23:06:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 21:53:59
-->

## fstream


### ifstream

输入文件流

### ofstream

输出文件流，用于创建文件并向文件写入信息


#### 打开


- 打开方式

| 定义        | 含义                         |
| ----------- | ---------------------------- |
| ios::in     | 为输入(读)而打开文件         |
| ios::out    | 为输出(写)而打开文件         |
| ios::ate    | 初始位置：文件尾             |
| ios::app    | 所有输出附加在文件末尾       |
| ios::trunc  | 如果文件已存在则先删除该文件 |
| ios::binary | 以二进制方式                 |

```c
const std::string path = "main.txt";

// 显式调用
ofstream out;

// 以追加方式为输出打开
out.open(path,  ios::out|ios::app);

// 隐式调用
ofstream out(path, ios::out|ios::app);
```


#### 写入


- 普通文件

```c
<<
```

```c
const std::string path = "main.txt";


ofstream out(path, ios::out|ios::app);

out << "Hello ";

out << "World\n";
```

- 二进制文件

```c
write()
```

```c
uint32_t value = 0xFF00FF00;

const std::string path = "image.rgb";


ofstream out(path, ios::out|ios::app);

// 将value的值写入4byte二进制文件中
out.write((char *)&value, 4);
```


#### 关闭

```
close()
```

