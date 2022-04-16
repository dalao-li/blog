<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-16 01:11:13
-->

## 1 MySQL事务


事务处理可以用来维护数据库的完整性，保证 SQL 语句要么全执行，要么全不执行

事务用来管理 `INSERT`，`UPDATE`，`DELETE` 语句，只有使用 Innodb 数据库引擎的数据库或表才支持事务


### 1.1 特性


#### 1.1.1 原子性 Atomic

一个事务中的全部操作，要么全部都完成，要么全部不完成.事务在执行过程中发生错误，会被回滚(rollback)到事务开始前的状态


#### 1.1.2 一致性Consistency

在事务开始之前和事务结束以后，数据库的完整性没有被破坏，表示写入的资料必须完全符合所有的预设规则，这包含资料的精确度、串联性以及后续数据库可以自发性地完成预定的工作


#### 1.1.3 隔离性 Isolation

隔离性可以防止多个事务并发执行时，由于交叉执行而导致对数据进行读写和修改产生不一致的情况

事务隔离分为不同级别，包括，

- 读未提交(Read uncommitted)

- 读提交(Read committed)

- 可重复读(Repeatable read)

- 串行化(Serializable)

- 持久性(Durability)

事务处理结束后，对数据的修改即是永久



### 1.2 事务控制

| 操作     | 指令       |
| -------- | ---------- |
| 事务开始 | `BEGIN`    |
| 事务回滚 | `ROLLBACK` |
| 事务确认 | `COMMIT`   |

```sql
CREATE TABLE "info" (
  "id" text NOT NULL,
  "name" text,
  PRIMARY KEY ("id")
);
```

- 事务开始

```sql
BEGIN;

INSERT INTO info (id,name) VALUES ('000A-X'，'WANG-LI');

# 事务确认
COMMIT;
```

![](https://cdn.hurra.ltd/img/20200712233125.png)


- 回滚事务

```sql
BEGIN;

INSERT INTO info (id,name) VALUES ('000B-Y','QING-XU');

COMMIT;

BEGIN;

INSERT INTO info (id,name) VALUES ('000C-Z','SONG-LING');

# 回滚，撤回插入
ROLLBACK;
```

可以看到第二条数据并未写入

![](https://cdn.hurra.ltd/img/20200712235320.png)

```sql
BEGIN;

DELETE FROM info WHERE id = '000B-Y';

# 回滚，撤销删除
ROLLBACK;
```

数据没有被删除

![](https://cdn.hurra.ltd/img/20200713000345.png)

