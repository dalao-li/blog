<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-19 23:44:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-22 21:25:08
-->

## Python设置


### 换源

```sh
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple pip -U

pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple
```


### 生成requestment

```sh
pip freeze > requirements.txt
```


### venv


#### 激活

```sh
source venv/bin/activate
```


#### 退出

```sh
deactivate
```