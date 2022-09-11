'''
Description: 
Version: 1.0
Author: DaLao
Email: dalao@xxx.com
Date: 2022-09-11 23:08:44
LastEditors: DaLao
LastEditTime: 2022-09-11 23:08:52
'''

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