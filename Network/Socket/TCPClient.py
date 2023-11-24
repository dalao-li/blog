'''
Description: 
Version: 1.0
Author: 
Email: 
Date: 2023-11-02 21:20:07
LastEditors: Please set LastEditors
LastEditTime: 2023-11-02 21:54:52
'''

import socket
import sys
import os

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

address = ('127.0.0.1', 5005)

try:
    server.connect(address)
except Exception:
    print('[!] Connect fail')
    sys.exit()

while True:
    send = input('[Send] ')
    server.sendall(send.encode())
    data = server.recv(1024)
    print('         [Recv]', data.decode())