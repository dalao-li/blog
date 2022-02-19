<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-19 23:44:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-19 22:00:29
-->

## 换源

```sh
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U

pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
```

## requestment

```sh
pip freeze > requirements.txt
```