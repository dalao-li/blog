'''
Description: 
Version: 1.0
Author: daLao
Email: dalao@xxx.com
Date: 2022-09-11 23:44:18
LastEditors: daLao
LastEditTime: 2022-10-06 23:08:33
'''

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
    for i in range(n):
        with lock:
            change_it(i)


if __name__ == '__main__':

    t1 = Thread(target=run_thread, args=(5, ))
    t2 = Thread(target=run_thread, args=(8, ))

    thread = [t1, t2]

    for i in thread:
        i.start()

    for i in thread:
        i.join()

    print(g_balance)