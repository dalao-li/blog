<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-17 06:34:26
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-16 23:42:39
-->


# Flask表单


## 表单


```html
<form action="{{ url_for('main_page')}}" method='POST'>
    <input type="text" class="form-control" id="name" name="name" required />
    <input type="datetime-local" class="form-control" id="time" name="time" />
    <select class="form-control" name="identify">
        <option value="水务类">水务类</option>
        <option value="工程消费类">工程消费类</option>
        <option value="卫生健康类">卫生健康类</option>
    </select>
        
    <input type="submit" class="btn btn-success" value="开始抽签"></input>
    <input type="reset" class="btn btn-danger" value="清空"></input>
</form>
```


## 后端


```py
@app.route('/main', methods=['GET', 'POST'])
def main_page():
    if request.method == 'GET':
        return render_template('main.html')
    if request.method == 'POST':
        # 获取表单值
        name = request.form.get("name")
        time = request.form.get("time")
        identify= request.form.get("identify")
        # 转为dict
        data = request.form.to_dict()
        return render_template('main.html', data=data)
```
