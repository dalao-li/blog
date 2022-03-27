<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-01 17:20:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 23:22:53
-->

## url_for


### 返回静态文件

```js
<link rel="stylesheet" href="{{ url_for('static',filename='bootstrap.min.css') }}">


<script src="{{ url_for('static',filename='jquery.min.js') }}"></script>
```


### 动态路由

```html
<a href="{{ url_for('test',name=1) }}">点击这里查看</a>
```

```py
@app.route('/index/<name>', methods=['GET'])
def test(name):
    return name
```

![](https://cdn.hurra.ltd/img/20211001235447.png)