'''
Description: 
Version: 1.0
Author: dalao
Email: dalao@xxx.com
Date: 2022-04-10 14:34:20
LastEditors: DaLao
LastEditTime: 2022-07-03 00:38:59
'''

import requests

ip = ''

r = requests.get("http://ip-api.com/json/" + ip)

print(r.json())