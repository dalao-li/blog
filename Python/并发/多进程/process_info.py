'''
Description: 
Version: 1.0
Author: DaLao
Email:  
Date: 2022-09-11 23:10:16
LastEditors: DaLao
LastEditTime: 2022-09-11 23:10:28
'''

import time
import os
from multiprocessing import Process

def cook():
    print("做饭进程""的pid: ", os.getpid())
    time.sleep(0.5)
    print("做饭进程的父进程pid: ", os.getppid())

def wash():
    print("洗衣服进程的pid: ", os.getpid())
    time.sleep(0.5)
    print("洗衣服进程的父进程pid: ", os.getppid())
        

if __name__ == '__main__':
    print("主进程的pid: ", os.getpid())

    cook_process = Process(target=cook)
    wash_process = Process(target=wash)

    cook_process.start()
    wash_process.start()