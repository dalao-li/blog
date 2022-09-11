<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-09-02 20:37:12
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 21:54:17
-->

## stream


C++中把数据之间的传输操作称为流


- 输出流, 流数据从内存传送到某个载体或设备中

- 输入流, 数据从某个载体或设备传送到内存缓冲区变量中


### 标准I/O流


内存与标准输入输出设备之间信息的传递

```c
iostream
```

- istream 从流读取数据

- ostream 向流写入数据

- iostream 读写流


### 文件I/O流

内存与外部文件之间信息的传递

```c
fstream
```

- ifstream 从文件读取数据

- ofstream 向文件写入数据

- fstream 读写文件



### 字符串I/O流

内存变量与表示字符串流的字符数组之间信息的传递

```c
sstream
```

- istringstream 从string读取数据

- ostringstream 向string写入数据

- stringstream 读写string