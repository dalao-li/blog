<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-05-28 23:30:58
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 20:36:51
-->

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>带参URL传值方法</title>
</head>
<body>
    <a href="{{ url_for('test',name=1) }}">点击这里查看</a>
</body>
<html>
```

```py
from flask import Flask,render_template
 
app = Flask(__name__)
 
@app.route('/')
def my():
    return render_template('/index.html')
 
@app.route('/index/<name>', methods=['GET'])
def test(name):
    return name
 
if __name__ == '__main__':
    app.run(debug=True)
```



![](https://cdn.hurra.ltd/img/20211001235447.png)