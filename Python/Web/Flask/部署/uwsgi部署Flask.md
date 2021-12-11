<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 20:37:23
-->

## uwsgi操作

```py
# test.py
def application(env， start_response):
    start_response('200 OK'， [('Content-Type'，'text/html')])
    return [b"Hello World"]
```


```py
# --plugin python 是告诉 uWSGI 在使用 python 插件
uwsgi --http :8080 --plugin python --wsgi-file test.py
```

访问http://127.0.0.1:8080

![](https://cdn.hurra.ltd/img/20200711123744.png)

![](https://cdn.hurra.ltd/img/20200711123908.png)

## 文件

- app.py

```py
# app.py
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
    return 'hello world ! '

if __name__ == '__main__':
	app.run()
```

- config.ini

```ini
[uwsgi]
# 启动主进程，来管理其他进程
master = true

# 地址和端口号
http = :5000

# app.py路径
wsgi-file =  app.py

# uwsgi指定的是application，而flask中是app
callable = app

# 开启的进程数量
processes = 2

# 运行线程
threads = 8

# 设置用于uwsgi包解析的内部缓存区大小为64k.默认是4k
buffer-size = 32768
```

- Dockerfile

```sh
# 所采用的基础镜像
FROM python:3.7-slim-buster

# 为镜像添加标签
LABEL version="v1" description="Docker deploy Flask" by="Dalao"

# 配置工作目录
WORKDIR /usr/flask/app

# 在镜像容器中执行命令
RUN pip install Flask uwsgi -i https://pypi.tuna.tsinghua.edu.cn/simple/

# 将主机中目录内容拷贝到镜像目录下
COPY . .

# 容器启动时执行指令，每个Dockerfile只能有一条CMD命令
CMD ["uwsgi"，"config.ini"]
```

- 构建镜像

```sh
docker build -t uwsgi_flask:v1 .

docker run -itd -p 5000:5000 --name uswgi_test uwsgi_flask
```

![](https://cdn.hurra.ltd/img/20200712114018.png)


## Nginx代理

```c
//修改nginx.conf
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
# 部署nginx容器，uwsgi容器，conf目录为Nginx的默认配置目录
docker run -itd -p 5000:5000 --name uswgi_test uwsgi_flask

docker run -itd --name nginx_flask --network host -v $PWD/conf:/etc/nginx nginx
```