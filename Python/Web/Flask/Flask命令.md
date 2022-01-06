<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-06 23:24:55
-->


## 运行

```sh
flask run
```
- 指定地址端口
  
```py
flask run --host=0.0.0.0 --port=8080
```

## Vscode 运行

```sh
ps -aux | grep flask | grep -v grep | awk {'print $2'} | xargs kill -9

source venv/bin/activate

python -m flask run
```