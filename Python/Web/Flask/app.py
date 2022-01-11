'''
Description: 
Version: 1.0
Author: DaLao
Email: dalao_li@163.com
Date: 2022-01-11 00:51:51
LastEditors: DaLao
LastEditTime: 2022-01-11 00:51:52
'''

from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_world():
    return 'Hello World!'