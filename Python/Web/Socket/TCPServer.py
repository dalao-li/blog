'''
Description: 
Version: 1.0
Author: 
Email: 
Date: 2023-11-02 21:19:14
LastEditors: Please set LastEditors
LastEditTime: 2023-11-02 22:38:18
'''
import socket

address = ('127.0.0.1', 5005)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setblocking(False)

server.bind(address)
server.listen(5)

client_list = []
while True:
    try:
        connection, client_address = server.accept()
        client_list.append((connection, client_address))
        print('[+] User Connect:', client_address)
    except BlockingIOError:
        pass
    
    for client_socket, client_address in client_list:
        try:
            data = client_socket.recv(1024)
            if data:
                print(f"[Recv] {client_address}, {data.decode('utf-8')}")
                client_socket.send(data)
            else:
                client_socket.close()
                print(f"downline: {client_address}")
                client_list.remove((client_socket, client_address))
        except (BlockingIOError, ConnectionResetError):
            pass