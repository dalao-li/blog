<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-14 16:29:38
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 00:08:12
-->

# BytesIO

BytesIO实现了在内存中读写bytes

```py
from io import BytesIO

f = BytesIO()
f.write('中文'.encode('utf-8'))

# b'\xe4\xb8\xad\xe6\x96\x87'
f.getvalue()
```

```py
f= <FileStorage: '涉农股专家公示名录.xlsx' ('application/vnd.openxmlformats-officedocument.spreadsheetml.sheet')>

type f=  <class 'werkzeug.datastructures.FileStorage'>
```