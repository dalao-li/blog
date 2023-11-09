<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-12-01 20:37:22
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-11-03 22:24:19
-->

# Socket

## TCP

### TCP 服务端 server

```py
import socket

server_address = ('127.0.0.1', 5005)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(server_address)

# 监听
s.listen(5)

# 返回客户端地址和一个新的 socket 连接
conn, client_address = s.accept()
# print('[+] 用户连接:', client_address)

while True:
    data = conn.recv(1024)
    # print('[回复]', data.decode())
    send = input('输入: ')
    conn.sendall(send.encode())


if __name__ == '__main__':
    conn.close()
    s.close()
```

### TCP 客户端 client

```py
import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('127.0.0.1', 5005)

try:
    s.connect(server_address)
except Exception:
    print('[!] 服务未打开')
    sys.exit()

while True:
    send = input('输入: ')
    s.sendall(send.encode())
    data = s.recv(1024)
    print('[回复]', data.decode())


if __name__ == '__main__':
    s.close()
```

## UDP

### 服务端 server

```py
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('127.0.0.1', 31500)
s.bind(server_address)

while True:
    # 返回数据和接入连接的(客户端)地址
    data, client_address = s.recvfrom(1024)
    # print(client_address + '[Received]:' + data.decode())
    send = input('Input: ')
    # UDP 是无状态连接, 所以每次连接都需要给出目的地址
    s.sendto(send.encode(), client_address)

if __name__ == '__main__':
    s.close()
```

### 客户端 client

```py
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('127.0.0.1', 31500)

while True:
    send = input('输入: ')
    s.sendto(send.encode(), server_address)
    # 返回数据和接入连接的(服务端)地址
    data, server_address = s.recvfrom(1024)
    print('[回复]', data.decode())


if __name__ == '__main__':
    s.close()
```

![](https://cdn.hurra.ltd/img/20210112224715.png)

![](https://cdn.hurra.ltd/img/20210112224731.png)

## 多线程 server 端

```py
import socket
import threading

server_address = ('127.0.0.1', 31500)

class SocketServer:
    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.bind(server_address)
        self.sock.listen(128)

    def start_server(self):
        while True:
            print('Wait')
            conn, address = self.sock.accept()
            print('Client %s come in', %address)
            t = threading.Thread(target=self.client_recv, args=(conn, address))
            t.start()

    def client_recv(self, client, addr):
        while True:
            data = client.recv(1024)
            if not data or data.decode() == 'bye':
                # 如果没有发送过来数据就代表客户端close, 或者发过来bye代表连接要断开
                print('Over', addr)
                client.close()
                break
            else:
                print('%s Send %s',  %(addr, data.decode()))
                msg = 'Test'
                client.send(msg.encode())

if __name__ == '__main__':
    t = SocketServer()
    t.start_server()
```
