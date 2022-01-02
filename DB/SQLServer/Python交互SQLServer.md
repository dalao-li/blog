<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 21:03:27
-->

## Navicat 连接

![](https://cdn.hurra.ltd/img/20201012105710.png)

注意:反人类的SQLServer的主机地址需写为: `ip，端口`，注意是`逗号`


## Python 交互

![](https://cdn.hurra.ltd/img/20201012130100.png)

```py
import pymssql

conn = pymssql.connect(
    host = IP:端口，
    user = "sa"，
    password = 密码，
    database = 数据库，
    charset = 'utf8'
)

# 使用cursor()方法获取操作游标
cursor = conn.cursor()

sql = "SELECT * FROM 表"

try:
    # 执行SQL语句
    cursor.execute(sql)
    results = cursor.fetchall()
    # print(results)
except:
    # print(results)

# 关闭数据库连接
conn.close()
```

![](https://cdn.hurra.ltd/img/20201012180210.png)
