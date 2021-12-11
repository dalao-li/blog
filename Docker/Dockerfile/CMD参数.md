<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 17:13:31
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-28 22:33:41
-->


```sh
# shell格式
[instruction] [command]

# 例如，apt-get install python3

# exec格式
[instruction] ["executable"， "param1"， "param2"， ...]

# 例，CMD ["python3"，"manage.py"，"runserver 0.0.0.0：8000"]

# 例，CMD ["apt-get"， "install"， "python3"]
```
`CMD` 在`docker run`时运行，Dockerfile中只能在末尾有一条CMD指令

