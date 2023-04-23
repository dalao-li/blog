<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-08-19 00:00:59
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 09:30:40
-->

# Flask部署

## Docker单例部署

- Dockerfile

```go
FROM python:3.7-slim-buster

LABEL version="v1" description="Docker deploy Flask" by="Dalao"

WORKDIR /app

COPY ..

EXPOSE 5000

RUN pip install -i https://pypi.tuna.tsinghua.edu.cn/simple/ Flask

CMD flask run --host=0.0.0.0 --port=5000
```

## supervisor部署

- flask.conf

```sh
[supervisord]
nodaemon=true

[program:flask]
directory=/usr/src/app
command=flask run --host=0.0.0.0 --port=5000
user=root
autostart=true
autorestart=true
```

- Dockerfile

```docker
FROM python:3.7-alpine

WORKDIR /usr/src/app

COPY flask.conf /etc/supervisord.conf

COPY . .

RUN pip install --no-cache-dir -i https://pypi.tuna.tsinghua.edu.cn/simple/  --trusted-host pypi.tuna.tsinghua.edu.cn -r requirements.txt

CMD supervisord -c /etc/supervisord.conf
```

## uwsgi部署

- config.ini

```ini
[uwsgi]
# 启动主进程, 来管理其他进程
master = true

# 地址和端口号
http = :5000

# app.py路径
wsgi-file =  app.py

# uwsgi指定的是application, 而flask中是app
callable = app

# 开启的进程数量
processes = 2

# 运行线程
threads = 8

# 设置用于uwsgi包解析的内部缓存区大小为64k.默认是4k
buffer-size = 32768
```

- Dockerfile

```docker
FROM python:3.7-slim-buster

LABEL version="v1" description="Docker deploy Flask" by="Dalao"

WORKDIR /usr/flask/app

RUN pip install flask uwsgi -i https://pypi.tuna.tsinghua.edu.cn/simple/

COPY . .

CMD uwsgi config.ini
```

## Nginx代理

- nginx.conf

```c
http {
    server {
        listen 80;
        server_name localhost;
        location / {
            include uwsgi_params;
            uwsgi_pass http://localhost:5000;
        }
    }
}
```

```sh
docker run -itd -p 5000:5000 --name uswgi_test uwsgi_flask

docker run -itd --name nginx_flask --network host -v $PWD/conf:/etc/nginx nginx
```
