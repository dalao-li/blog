<!--
 * @Description: 
 * @Version: 1
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-26 10:30:04
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-12 22:16:49
-->

## 守护进程

主进程会等待所有的子进程执行结束再结束，实际开发过程中则希望主进程结束时结束所有子进程

此时需要主进程创建守护进程

- 守护进程会在主进程代码执行结束后就终止
  
- 守护进程内无法再开启子进程，否则抛出异常

```sh
AssertionError: daemonic processes are not allowed to have children
```
- 进程之间是互相独立的，主进程代码运行结束，守护进程随即终止

```py
import time
import os
import multiprocessing


def work():
    for i in range(10):
        print("Work in....")
        time.sleep(0.2)

if __name__ == '__main__':
    # 创建子进程
    work_process = multiprocessing.Process(target=work)
    # 设置守护进程，主进程结束后子进程直接销毁
    work_process.daemon = True
    work_process.start()
    time.sleep(1)
    print("主进程结束!")
```

![](https://cdn.hurra.ltd/img/20201019195202.png)

可见，主进程结束时子进程也立即结束

