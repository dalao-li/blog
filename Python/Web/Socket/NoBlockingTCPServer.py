'''
Description: 
Version: 1.0
Author: 
Email: 
Date: 2023-11-03 21:58:33
LastEditors: Please set LastEditors
LastEditTime: 2023-11-03 22:00:11
'''
import socket
import select

sock = socket.socket()
sock.bind(('127.0.0.1', 9999))
sock.setblocking(False)
sock.listen()


inputs = [sock, ]

while True:
    r_list, w_list, e_list = select.select(inputs, [], [], 1)
    for event in r_list:
        if event == sock:
            print("新的客户端连接")
            new_sock, addr = event.accept()
            inputs.append(new_sock)
        else:
            data = event.recv(1024)
            if data:
                print("接收到客户端信息")
                print(data)
                event.send(b'\x31')
            else:
                print("客户端断开连接")
                inputs.remove(event)