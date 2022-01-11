#!/bin/bash

###
 # @Description: 
 # @Version: 1.0
 # @Author: DaLao
 # @Email: dalao_li@163.com
 # @Date: 2022-01-11 00:24:26
 # @LastEditors: DaLao
 # @LastEditTime: 2022-01-11 00:57:33
### 

name=${1}

mkdir $name

mkdir $name/static

mkdir $name/templates

touch $name/app.py


cat >> $name/app.py <<EOF
from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_world():
    return 'Hello World!'
EOF

python -m virtualenv $name/venv

source $name/venv/bin/activate

pip install flask


