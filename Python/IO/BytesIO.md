<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-14 16:29:38
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-14 16:33:26
-->

## BytesIO

BytesIO实现了在内存中读写bytes

```py
from io import BytesIO

f = BytesIO()
f.write('中文'.encode('utf-8'))

# b'\xe4\xb8\xad\xe6\x96\x87'
print(f.getvalue())
```