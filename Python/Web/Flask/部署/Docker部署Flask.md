<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-19 00:00:59
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-12 22:31:38
-->


## Dockerfile

```sh
# 所采用的基础镜像
FROM python:3.7-slim-buster

# 为镜像添加标签
LABEL version="v1" description="Docker deploy Flask" by="Dalao"

# 工作目录
WORKDIR /app

COPY ..

EXPOSE 5000

RUN pip install -i https://pypi.tuna.tsinghua.edu.cn/simple/ Flask

CMD ["python3"，"app.py"]
```