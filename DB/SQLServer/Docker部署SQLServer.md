<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 23:48:41
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-06 14:53:36
-->

## Docker部署

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


## 命令

- 进入SQLSercer

```sh
/opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P "Dalao@13546!"
```

- 显示所有数据库

```sql
SELECT Name FROM Master..SysDatabases ORDER BY Name
GO
```

![](https://cdn.hurra.ltd/img/20201012110513.png)

- 显示表

```sql
SELECT * FROM 表名
GO
```

![](https://cdn.hurra.ltd/img/20201012130931.png)

别忘记输入`GO`，那样才会执行命令(反人类的SQLServer)