'''
Description: 
Version: 1.0
Author: dalao
Email: dalao_li@163.com
Date: 2022-04-10 14:34:20
LastEditors: dalao
LastEditTime: 2022-04-10 14:38:01
'''

import requests

ip = ''
r = requests.get("http://ip-api.com/json/" + ip)

print(r.json())