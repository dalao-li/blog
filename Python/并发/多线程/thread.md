<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-26 11:01:43
 * @LastEditors: daLao
 * @LastEditTime: 2022-10-06 23:09:09
-->

## 多线程


进程是由若干线程组成的, 一个进程至少有一个线程

线程是操作系统直接支持的执行单元

Python的线程是真正的Posix Thread, 而不是模拟出来的线程


```py
import time

from threading import Thread
from threading import current_thread as ct

# 新线程执行的代码
def loop():
    print('线程 %s 运行中...' % ct.name)

    for i in range(5):
        print('线程 %s >> %s' % (ct.name, n))
        time.sleep(0.5)

    print('线程 %s 结束' % ct.name)

print('线程 %s 运行中...' % ct.name)


# 子线程命名LoopThread
# 不起名字Python就自动给线程命名为Thread-1, Thread-2...
# 名字没有其他意义, 仅仅在打印时显示,
t = Thread(target=loop, name='LoopThread')

# 开始执行
t.start()

t.join()

print('线程 %s 结束.' % ct.name)
```

![](https://cdn.hurra.ltd/img/20211217234005.png)

任何进程默认就会启动一个主线程, 主线程又可以启动新的线程

threading模块current_thread()函数, 永远返回当前线程的实例

主线程实例的名叫MainThread



### 互斥锁


多进程中, 同一个变量各有一份拷贝存在于每个进程中, 互不影响

多线程中, 所有变量都由所有线程共享, 任何变量都可以被任何一个线程修改

因此, 线程之间共享数据最大的危险在于多个线程同时改一个变量, 造成内容混乱

- 使用

```py
import threading

lock = threading.Lock()

# 获取锁
lock.acquire()

# 释放锁
lock.release()
```

- 上下文管理

```py
import threading

lock = threading.Lock()

with lock:
    pass
```

`with` 语句会在执行前自动获取锁, 执行结束后自动释放


例, 银行存款时, 多线程操作时, 每一次存钱与取钱前都需要加锁, 避免余额错误

```py
from threading import Thread, Lock

# 银行存款
g_balance = 0

lock = Lock()

def change_it(n):
    # 先存后取, 结果应该为0
    global g_balance

    g_balance += n
    g_balance -= n

def run_thread(n):
    global lock

    for i in range(1000):
        with lock:
            change_it(i)


if __name__ == '__main__':
    lock = Lock()

    t1 = Thread(target=run_thread, args=(5, ))
    t2 = Thread(target=run_thread, args=(8, ))

    thread = [t1, t2]

    for i in thread:
        i.start()
    for i in thread:
        i.join()

    print(g_balance)
```
