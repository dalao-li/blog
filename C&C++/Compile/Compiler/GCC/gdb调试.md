<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-03-12 22:41:18
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-11-23 21:29:15
-->

# gdb

- 编译

```c
gcc -g main.c -o main
```

- 调试

```c
gdb [program]
```

## 指令

### run

运行程序, 遇到断点后, 程序会在断点处停止运行, 等待用户输入下一步的命令

### continue

继续执行, 到下一个断点处(或运行结束)

### next

单步跟踪程序, 遇到函数调用时, 直接调用, 不进入函数

### step

单步调试, 遇到有函数调用, 进入函数运行

### until

运行程序直到退出循环体

- until+行号

运行至某行, 不仅仅用来跳出循环

### finish

运行程序, 直到当前函数完成返回, 并打印函数返回时的堆栈地址和返回值及参数值等信息

### call 函数(参数)

调用程序中可见的函数, 并传递参数, 如: call gdb_test(55)

### quit

退出gdb

## 设置断点

### break

在第n行处设置断点

### break func

在函数func()的入口处设置断点

### delete n

删除第n个断点

### disable n

暂停第n个断点

### enable n

开启第n个断点

### clear n

清除第n行的断点

### info breakpoints

显示当前程序的断点设置情况

### delete breakpoints

清除所有断点

## 查看源代码

### list

列出程序的源代码, 默认每次显示10行

- list 行号

将显示当前文件以"行号"为中心的前后10行代码, 如: list 12

- list 函数名

将显示函数的源代码

- list : 不带参数

将接着上一次 list 命令输出下边内容

## 打印表达式

### print

print 表达式

`表达式`可以是任何当前正在被测试程序的有效表达式, 如当前正在调试C语言的程序, 那么"表达式"可以是任何C语言的有效表达式, 包括数字, 变量甚至是函数调用

- print 数字a

将显示数字a值

- print ++a

a 值加1显示

- print name

显示字符串 name 的值

- print gdb_test(22)

将以整数22作为参数调用 gdb_test() 函数

- print gdb_test(a)

将以变量 a 作为参数调用 gdb_test() 函数

#### display

在单步运行时将非常有用, 使用display命令设置一个表达式后, 它将在每次单步进行指令后, 紧接着输出被设置的表达式及值. 如:  display a

#### watch

设置监视点, 一旦被监视的`表达式`值改变, gdb将强行终止正在被调试的程序. 如:  watch a

#### whatis

查询变量或函数

#### info function

查询函数

### 查询运行信息

where/bt : 当前运行的堆栈列表

bt backtrace 显示当前调用堆栈

up/down 改变堆栈显示的深度

set args 参数:指定运行时的参数

show args: 查看设置好的参数

info program:  来查看程序的是否在运行, 进程号, 被暂停的原因

### 分割窗口

#### layout

用于分割窗口, 可以一边查看代码, 一边测试

layout src: 显示源代码窗口

layout asm: 显示反汇编窗口

layout regs: 显示源代码/反汇编和CPU寄存器窗口

layout split: 显示源代码和反汇编窗口

Ctrl + L: 刷新窗口
