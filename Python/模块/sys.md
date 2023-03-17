<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-10-24 18:18:03
 * @LastEditors: daLao
 * @LastEditTime: 2022-10-24 18:18:22
-->

## sys模块

"sys"即"system", "系统"之意该模块提供了一些接口, 用于访问 Python 解释器自身使用和维护的变量, 同时模块中还提供了一部分函数, 可以与解释器进行比较深度的交互


### sys.argv

"argv"即"argument value"的简写, 是一个列表对象, 其中存储的是在命令行调用 Python 脚本时提供的"命令行参数"

这个列表中的第一个参数是被调用的脚本名称, 也就是说, 调用 Python 解释器的"命令"(python)本身并没有被加入这个列表当中

这一点跟 C 程序的行为有所不同, C 程序读取命令行参数是从头开始

- 直接运行

在当前目录下新建一个 Python 文件Main.py

```py
import sys

print("The list of command line arguments:\n", sys.argv)
```

运行结果

```py
The list of command line arguments:
 ['c:\\Users\\dalao\\Documents\\code\\Main.py']
```

- 含参数运行

```py
python Main.py arg1 arg2 arg3
```

运行结果

```py
The list of command line arguments: 
 ['Main.py', 'arg1', 'arg2', 'arg3']
```


### sys.platform

得到关于运行平台更详细的信息

Windows上

```py
>>> import sys
>>> sys.platform
'win32'
```

Linux 上

```py
>>> sys.platform
'linux'
```


### sys.byteorder

byteorder"即"字节序", 指的是在计算机内部存储数据时, 数据的低位字节存储在存储空间中的高位还是低位

"小端存储"时, 数据的低位也存储在存储空间的低位地址中, 此时sys.byteorder的值为"little"

如果不注意, 在按地址顺序打印内容的时候, 可能会把小端存储的内容打错

当前大部分机器都是使用的小端存储

```py
>>> sys.byteorder
'little'
```

另一种存储顺序是"大端存储", 即数据的高位字节存储在存储空间的低位地址上, 此时sys.byteorder的值为"big"


### sys.executable

该属性是一个字符串, 在正常情况下, 其值是当前运行的 Python 解释器对应的可执行程序所在的绝对路径

```py
>>> import sys
>>> sys.executable
'C:\\Users\\dalao\\AppData\\Local\\Programs\\Python\\Python39\\python.exe'
```