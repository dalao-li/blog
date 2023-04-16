<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-11-13 19:15:39
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-03 22:39:13
-->

# send_from_directory


## 返回静态文件

```py
send_from_directory('文件目录', 文件名)
```

```py
@app.route('/<path>')
def get_image(path):
    return send_from_directory('templates', path)
```

图片路径为/templates/a.jpg, 访问127.0.0.1:5000/a.jpg即返回静态文件

![](https://cdn.hurra.ltd/img/20211113191621.png)


![](https://cdn.hurra.ltd/img/20211113191826.png)
