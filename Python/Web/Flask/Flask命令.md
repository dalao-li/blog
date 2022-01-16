<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-16 13:36:00
-->


## 运行

```sh
flask run
```
- 指定地址端口
  
```py
flask run --host=0.0.0.0 --port=5000
```

## shell 运行

```sh
source venv/bin/activate

python -m flask run --host=0.0.0.0 --port=5000

ps -aux | grep flask | grep -v grep | awk {'print $2'} | xargs kill -9 && python -m flask run --host=0.0.0.0 --port=500
```

## 建立脚本

```sh
#!/bin/bash

name=${1}

mkdir $name

mkdir $name/static

mkdir $name/templates

python -m virtualenv $name/venv

source $name/venv/bin/activate

pip install flask

touch app.py
```