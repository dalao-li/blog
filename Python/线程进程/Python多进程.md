<!--
 * @Description: 
 * @Version: 1
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-12 22:15:48
-->


## 普通情况

```py
import time

def cook():
    for i in range(3):
        print("做饭...")
        time.sleep(0.5)

def wash():
    for i in range(3):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    cook()
    wash()
```

![](https://cdn.hurra.ltd/img/20201019171128.png)

两个任务先后完成，共花费 3 秒钟，可使用多线程的方式让两个任务同步执行

## 多进程执行任务

- 导入进程包
 
- 使用进程类创建进程对象
 
- 使用进程对象启动进程执行指定任务
  
```py
import time

from multiprocessing import Process

def cook():
    for i in range(3):
        print("做饭...")
        time.sleep(0.5)

def wash():
    for i in range(3):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    # 使用进程类创建进程对象
    cook_process = Process(target=cook)
    wash_process = Process(target=wash)

    # 使用进程对象启动进程执行指定任务
    cook_process.start()
    wash_process.start()
```

![](https://cdn.hurra.ltd/img/20201019173207.png)

## 进程执行带参任务

- args 传参

args 以元组的形式给线程传递参数

```py
import time
import multiprocessing

def cook(num):
    for i in range(num):
        print("做饭...")
        time.sleep(0.5)

def wash(num):
    for i in range(num):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    # 使用进程类创建进程对象
    cook_process = multiprocessing.Process(target=cook， args=(4，))
    wash_process = multiprocessing.Process(target=wash， args=(4，))

    # 使用进程对象启动进程执行指定任务
    cook_process.start()
    wash_process.start()
```

![](https://cdn.hurra.ltd/img/20201019175806.png)

- kwargs 传参

args 以字典的形式给线程传递参数

```py
import time

from multiprocessing import Process

def cook(num):
    for i in range(num):
        print("做饭...")
        time.sleep(0.5)

def wash(num):
    for i in range(num):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    # 使用进程类创建进程对象
    cook_process = Process(target=cook， kwargs={"num": 2})
    wash_process = Process(target=wash， kwargs={"num": 2})

    # 使用进程对象启动进程执行指定任务
    cook_process.start()
    wash_process.start()
```

![](https://cdn.hurra.ltd/img/20201019180329.png)

## 获取进程编号

- 获取当前进程编号

```py
import os

pid = os.getpid()
```

![](https://cdn.hurra.ltd/img/20201019181524.png)

- 获取当前父进程的编号

```py
import time
import os
from multiprocessing import Proess

def cook():
    for i in range(2):
        print("做饭进程的pid: "， os.getpid())
        print("做饭进程的父进程pid: "，os.getppid())
        print("做饭...")
        time.sleep(0.5)

def wash():
    for i in range(2):
        print("洗衣服进程的pid: "， os.getpid())
        print("洗衣服进程的父进程pid: "， os.getppid())
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    print("主进程的pid: "，os.getpid())
    cook_process = Process(target=cook)
    wash_process = Process(target=wash)
    cook_process.start()
    wash_process.start()
```

![](https://cdn.hurra.ltd/img/20201019183002.png)


