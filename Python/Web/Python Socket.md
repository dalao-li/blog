<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-01 20:37:22
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 01:01:50
-->

## Socket


### TCP


#### 服务端 server

```py
import socket

# 服务端地址和端口
server_address = ('127.0.0.1', 5005)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 绑定服务端地址和端口
s.bind(server_address)

# 监听
s.listen(5)

# 返回客户端地址和一个新的 socket 连接
conn, client_address = s.accept()
# print('[+] 用户连接:', client_address)

while True:
    # buffersize 等于 1024
    data = conn.recv(1024)
    # print('[回复]', data.decode())
    send = input('输入: ')
    conn.sendall(send.encode())


if __name__ == '__main__':
    conn.close()
    s.close()
```


#### 客户端 client

```py
import socket
import sys

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 服务端地址和端口
server_address = ('127.0.0.1', 5005)

# 尝试连接服务端
try:
    s.connect(server_address)
except Exception:
    print('[!] 服务未打开')
    sys.exit()

while True:
    send = input('输入: ')
    # 发送消息
    s.sendall(send.encode())
    data = s.recv(1024)
    print('[回复]', data.decode())


if __name__ == '__main__':
    s.close()
```


### UDP


#### 服务端 server

```py
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 服务端地址和端口
server_address = ('127.0.0.1', 31500)
# 绑定服务端地址和端口
s.bind(server_address)

while True:
    # 返回数据和接入连接的(客户端)地址
    data, client_address = s.recvfrom(1024)
    # print(client_address + '[Received]:' + data.decode())
    send = input('Input: ')
    # UDP 是无状态连接,所以每次连接都需要给出目的地址
    s.sendto(send.encode(), client_address)

if __name__ == '__main__':
    s.close()
```


#### 客户端 client

```py
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 服务端地址和端口
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



### 多线程 server 端


```py
import socket,threading

server_address = ('127.0.0.1', 31500)

class SocketServer:

    def __init__(self):
        # 建立一个tcp/ip scoket
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
         # 绑定端口号
        sock.bind(server_address)
        # 监听
        sock.listen(128)
        self.sock = sock

    def start_server(self):
        while True:
            print('开始等待多个客户端过来')
            conn,address = self.sock.accept()
            print('客户 %s 过来了',%address)
            t = threading.Thread(target=self.client_recv,args=(conn,address))
            t.start()

    def client_recv(self,client,addr):
        while True:
            # 获取到客户端的数据
            data = client.recv(1024)
            if not data or data.decode() == 'bye':
                # 如果没有发送过来数据就代表客户端close了,或者发过来bye代表连接要断开
                print('服务结束', addr)
                # 断开连接,为下一个服务
                client.close()
                break
            else:
                print('%s 发送 %s',  %(addr,data.decode()))
                msg = '统一回复,人不在'
                client.send(msg.encode())

if __name__ == '__main__':
    t = SocketServer()
    t.start_server()
```
