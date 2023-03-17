<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-28 20:39:27
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-27 22:25:21
-->

## Excel 


### 读取excel

```py
def read_excel(f):
    def is_number(s):
        try:
            float(s)
            return True
        except ValueError:
            pass
 
        try:
            import unicodedata
            unicodedata.numeric(s)
            return True
        except (TypeError, ValueError):
            pass
 
        return False
    f.save("static/" + f.filename)
    e = xlrd.open_workbook("static/" + f.filename)
    # 读取第一个sheet
    s = e.sheets()[0]
    a = []
    for i in range(s.nrows):
        # 读取这一行的数据
        j = s.row_values(i)
        # 跳过非数据行
        if is_number(j[0]) is False:
            continue
        # j[0], j[1], j[2]...
```


### 下载excel

```py
def download_excel():
    fp = io.BytesIO()
    b = Workbook(fp, {'in_memory': True})
    s = b.add_worksheet('Sheet1')
    data = {
        '事项名称: ': p.name, 
        '受理时间: ': p.time, 
        # ....
    }
    # 写入标题
    s.write_row('A1', list(data.keys()))
    
    # 按坐标写入
    # s.write('B2', v)
    b.close()
    response = make_response(fp.getvalue())
    fp.close()
    return response

@app.route('/download/<id>', methods=['GET'])
def download(id):
    response = download_excel()
    response.headers['Content-Type'] = "utf-8"
    response.headers["Cache-Control"] = "no-cache"
    name = datetime.datetime.now()
    response.headers["Content-Disposition"] = "attachment; filename=" + str(name) + ".xlsx"
    return response
```

### GUI

```py
import tkinter as tk 

import pandas as pd

window = tk.Tk()
 

window.title('My Window')
 

window.geometry('1500x900')

e = tk.Entry(window, show = None, font=('Arial', 14), width = 50) 
e.place(x = 20, y = 20)

def download():
    url = e.get()
    name = ''
    df = pd.read_html(url, encoding='utf-8', header = 0)[0]
    df.to_excel(name + '.xlsx', index = False)

b = tk.Button(window, text='下载', font=('Arial', 12), width = 10, height = 1, command=download)
b.place(x = 20, y = 80)

c = tk.Button(window, text='清空', font=('Arial', 12), width = 10, height = 1, command=e.select_clear())
c.place(x = 250, y = 80)
window.mainloop()
```