<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-02-04 23:48:41
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-06 23:33:54
-->

## SQLServer


### Docker部署


```sh
docker run -itd \
    -e "ACCEPT_EULA=Y" \
    -e "SA_PASSWORD=Dalao@13546!" \
    -p 1433:1433  \
    --name sqlserver2019 \
    registry.cn-hangzhou.aliyuncs.com/vex/sqlserver:v1
```

```sh
docker run -itd -e "ACCEPT_EULA=Y" -e "SA_PASSWORD=Dalao@13546!" -p 1433:1433 --name sqlserver2019 registry.cn-hangzhou.aliyuncs.com/vex/sqlserver:v1
```

| 值           | 属性   |
| ------------ | ------ |
| SA           | 用户名 |
| Dalao@13546! | 密码   |


### 命令


#### 进入SQLSercer

```sh
/opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P "Dalao@13546!"
```


#### 显示所有数据库

```sql
SELECT Name FROM Master..SysDatabases ORDER BY Name
GO
```

![](https://cdn.hurra.ltd/img/20201012110513.png)


#### 显示表

```sql
SELECT * FROM [表名]
GO
```

![](https://cdn.hurra.ltd/img/20201012130931.png)

别忘记输入`GO`, 那样才会执行命令(反人类的SQLServer)



### Python 交互


#### Navicat 连接

![](https://cdn.hurra.ltd/img/20201012105710.png)

注意:反人类的SQLServer的主机地址需写为: `ip, 端口`, 注意是`逗号`

![](https://cdn.hurra.ltd/img/20201012130100.png)

```py
import pymssql

conn = pymssql.connect(
    host = IP:端口, 
    user = "sa", 
    password = 密码, 
    database = 数据库, 
    charset = 'utf8'
)

# 使用cursor()方法获取操作游标
cursor = conn.cursor()

sql = "SELECT * FROM 表"

try:
    # 执行SQL语句
    cursor.execute(sql)
    results = cursor.fetchall()
except:
    ...

# 关闭数据库连接
conn.close()
```

![](https://cdn.hurra.ltd/img/20201012180210.png)