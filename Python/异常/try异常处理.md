<!--
 * @Description: 
 * @Version: 
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @QQ: 1061299112
 * @Date: 2021-01-25 22:06:50
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-16 13:46:07
-->

## 异常

### 格式

```py
try:
    # 可能会有异常产生的代码
except:
    # 处理预期的异常
else:
    # 没有异常时执行
finally:
    # 最终都会执行
```

```py
def judge(s: str)-> bool:
    if len(s) > 5:
        throw 

```