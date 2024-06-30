'''
Description: 
Version: 1.0
Author: dalao
Email:  
Date: 2022-04-10 14:34:20
LastEditors: DaLao
LastEditTime: 2022-07-03 00:38:59
'''

import requests

ip = '61.185.159.167'

r = requests.get("http://ip-api.com/json/" + ip)

print(r.json())