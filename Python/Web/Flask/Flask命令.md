<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 19:57:58
-->


### 运行


```sh
flask run
```

- 指定地址端口
  
```py
flask run --host=0.0.0.0 --port=5000
```


### shell

```sh
source venv/bin/activate

python -m flask run --host=0.0.0.0 --port=5000

ps -aux | grep flask | grep -v grep | awk {'print $2'} | xargs kill -9 && python -m flask run --host=0.0.0.0 --port=500
```


### 脚本


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