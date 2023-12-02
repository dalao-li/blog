'''
Description: 
Version: 1.0
Author: 
Email: 
Date: 2023-11-03 21:59:10
LastEditors: Please set LastEditors
LastEditTime: 2023-11-03 22:02:23
'''
import socket
import select

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # 不经过WAIT_TIME, 直接关闭
sock.setblocking(False)                                     # 设置非阻塞编程

try:
    sock.connect(("127.0.0.1", 9999))
except Exception as e:
    print(e)

r_inputs, w_inputs, e_inputs = set(), set(), set()
r_inputs.add(sock)
w_inputs.add(sock)
e_inputs.add(sock)

while True:
    try:
        r_list, w_list, e_list = select.select(r_inputs, w_inputs, e_inputs, 1)
        # 产生了可读事件, 即服务端发送信息
        print("r")
        for event in r_list:
            try:
                data = event.recv(1024)
            except Exception as e:
                print(e)
            if data:
                print(data)
                print("收到信息")
            else:
                print("远程断开连接")
                r_inputs.clear()
        print("w")
        # 产生了可写的事件, 即连接完成
        if len(w_list) > 0:
            print(w_list)
            # 当连接完成之后, 清除掉完成连接的socket
            w_inputs.clear()
        print("e")
        # 产生了错误的事件, 即连接错误
        if len(e_list) > 0:
            print(e_list)
            # 当连接有错误发生时, 清除掉发生错误的socket
            e_inputs.clear()
    except OSError as e:
        print(e)