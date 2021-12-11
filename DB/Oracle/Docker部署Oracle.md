<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-10 21:23:47
-->

## Docker部署Oracle

```sh
docker run -itd \
    --name=orace \
    -p 8080:8080 \
    -p 1521:1521 truevoly/oracle-12c

# docker run -itd --name=orace -p 8080:8080 -p 1521:1521 truevoly/oracle-12c

# 进入Oracle
sqlplus sys as sysdba

# 输入 sys 用户的默认密码 oracle
```

```sql
# 查看表空间
SELECT tablespace_name FROM dba_tablespaces;

# 查看表空间路径
SELECT * FROM dba_data_files;

# path = /u01/app/oracle/oradata/xe/...
```

![](https://cdn.hurra.ltd/img/20201130153639.png)


```sql 
# 创建了名为 space_demo，路径为'/u01/app/oracle/oradata/xe/space_demo.DBF'的表空间
CREATE TABLESPACE space_demo DATAFILE '/u01/app/oracle/oradata/xe/space_demo.DBF' SIZE 32M AUTOEXTEND ON NEXT 32M MAXSIZE 20480M EXTENT MANAGEMENT LOCAL;

# 创建了名为 user_test 的用户，其密码是 123，默认表空间 space_demo
CREATE USER user_test IDENTIFIED BY 123 ACCOUNT UNLOCK DEFAULT TABLESPACE space_demo;

# 将connect，resource，dba 权限赋予 test 用户
GRANT CONNECT，RESOURCE，DBA TO user_test;
```


