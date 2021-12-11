<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-26 11:01:43
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 20:31:02
-->

## 多线程

多任务可以由多进程完成，也可以由一个进程内的多线程完成

进程是由若干线程组成的，一个进程至少有一个线程

线程是操作系统直接支持的执行单元，Python的线程是真正的Posix Thread，而不是模拟出来的线程

Python的标准库提供threading，_thread是低级模块

启动一个线程是把一个函数传入并创建Thread实例，然后调用start()开始执行

```py
import time

from threading import Thread， current_thread

# 新线程执行的代码:
def loop():
    print('thread %s is running...' % current_thread().name)
    n = 0
    while n < 5:
        n = n + 1
        print('thread %s >> %s' % (current_thread().name， n))
        time.sleep(1)
    print('thread %s ended.' % current_thread().name)

print('thread %s is running...' % current_thread().name)
t = Thread(target=loop， name='LoopThread')
t.start()
t.join()
print('thread %s ended.' % current_thread().name)

```

![](https://cdn.hurra.ltd/img/20210126110727.png)

任何进程默认就会启动一个主线程，主线程又可以启动新的线程

Python的threading模块current_thread()函数，它永远返回当前线程的实例  

主线程实例的名字叫MainThread，子线程的名字在创建时指定，此处用LoopThread命名子线程

名字仅仅在打印时显示，没有其他意义，如果不起名字Python就自动给线程命名为Thread-1，Thread-2......

## 线程锁

多线程和多进程最大的不同在于，

- 多进程中，同一个变量各自有一份拷贝存在于每个进程中，互不影响
  
- 多线程中，所有变量都由所有线程共享，任何一个变量都可以被任何一个线程修改
    
因此，线程之间共享数据最大的危险在于多个线程同时改一个变量，造成内容混乱

```py
import time， threading

# 假定这是你的银行存款:
balance = 0

def change_it(n):
    # 先存后取，结果应该为0:
    global balance
    balance = balance + n
    balance = balance - n

def run_thread(n):
     # 先要获取锁:
    lock.acquire()
    for i in range(2000000):
        with lock:
            change_it(n)
        try:
            # 放心地改:
            change_it(n)
        finally:
            # 改完了一定要释放锁:
            lock.release()

t1 = threading.Thread(target=run_thread， args=(5，))
t2 = threading.Thread(target=run_thread， args=(8，))

t1.start()
t2.start()
t1.join()
t2.join()
print(balance)
```

两个线程同时一存一取，就可能导致余额不对，必须确保一个线程在修改balance的时候，别的线程一定不能改.

给change_it()上锁，当某个线程开始执行change_it()时，该线程因为获得了锁，因此其他线程不能同时执行change_it()，只能等待，直到锁被释放后，获得该锁以后才能改.由于锁只有一个，无论多少线程，同一时刻最多只有一个线程持有该锁，所以不会造成修改的冲突.

创建一个锁就是通过`threading.Lock()`来实现.

当多个线程同时执行lock.acquire()时，只有一个线程能成功地获取锁，然后继续执行代码，其他线程就继续等待直到获得锁为止.

获得锁的线程用完后一定要释放锁，否则那些苦苦等待锁的线程将永远等待下去，成为死线程.所以我们用try...finally来确保锁一定会被释放.

锁的好处就是确保了某段关键代码只能由一个线程从头到尾完整地执行

坏处首先是阻止了多线程并发执行，包含锁的某段代码实际上只能以单线程模式执行，效率就大大地下降了

其次，由于可以存在多个锁，不同的线程持有不同的锁，并试图获取对方持有的锁时，可能会造成死锁，导致多个线程全部挂起，既不能执行，也无法结束，只能靠操作系统强制终止