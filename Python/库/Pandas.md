<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-07 00:20:38
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-07 00:20:38
-->

## 读取Excel

```sh
import pandas as pd

df = pd.read_excel('python.xlsx', sheet_name='Sheet1')
# 逐行读取
for i in df.values:
    for j in i:
        print(j)
```
