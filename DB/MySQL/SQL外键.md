<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-03-18 00:33:39
-->

# SQL外键


## 概念


外键是另一表的主键, 可重复, 可为空, 用于数据约束

- 一个表中的 `FOREIGN KEY`(外键) 指向另一个表中的 `PRIMARY KEY`(主键)

- `FOREIGN KEY` 必须是其指向的那个表中的值之一

- `FOREIGN KEY` 用于约束预防破坏表之间连接的动作, 防止非法数据插入外键列


## 实例


```sql
CREATE TABLE `Stu`  (
  `s_id` varchar(255)  NOT NULL, 
  `s_name` varchar(255), 
  PRIMARY KEY (`s_id`) USING BTREE
);

CREATE TABLE `Course`  (
  `c_id` varchar(255)  NOT NULL, 
  `c_name` varchar(255), 
  PRIMARY KEY (`c_id`) USING BTREE
);

CREATE TABLE `Score`  (
  `r_id` int(0) NOT NULL AUTO_INCREMENT, 
  `s_id` varchar(255), 
  `c_id` varchar(255), 
  `score` int(0), 
  PRIMARY KEY (`r_id`) USING BTREE, 
  INDEX `s_id`(`s_id`) USING BTREE, 
  INDEX `c_id`(`c_id`) USING BTREE, 
  
  # Score.c_id(外键)指向 Course.c_id(主键)
  CONSTRAINT `c_id` FOREIGN KEY (`c_id`) REFERENCES `Course` (`c_id`) ON DELETE RESTRICT ON UPDATE RESTRICT, 

  # Score.s_id(外键)指向 Stu.s_id(主键)
  CONSTRAINT `s_id` FOREIGN KEY (`s_id`) REFERENCES `Stu` (`s_id`) ON DELETE RESTRICT ON UPDATE RESTRICT
);
```

若向 Score 表中插入一行数据, 其中 Score.s_id, Score.c_id 值必须存在于 Stu 表与Course 表中, 否则会报错

Stu 表

| s_id          | s_name |
| ------------- | ------ |
| 2017-XAB-3653 | 李五句 |
| 2017-XAB-3663 | 崔大机 |
| 2017-XAB-3669 | 武杀朱 |

Course 表

| c_id      | c_name   |
| --------- | -------- |
| AV-170001 | 结构力学 |
| AV-275455 | 量子力学 |
| AV-999900 | 流体力学 |

- 向 Score 表中插入李五句的量子力学成绩 97 分

```sql
INSERT INTO Score (s_id, c_id, score) VALUES ('2017-XAB-3653', 'AV-275455', 97);
```

![](https://cdn.hurra.ltd/img/20201005170211.png)

插入正常, 因为s_id, c_id 的值都在 Stu 与 Course 表中存在

- 现在李五句有门课编号为 BV-000001, 成绩为 80 分, 插入 Score 

![](https://cdn.hurra.ltd/img/20201005170512.png)

显示插入错误, 因为 c_id = BV-000001 在其指向的 Course 表中不存在, 产生了约束错误


- 现在有位同学编号为 X-47-W, 其量子力学成绩为 80 分, 插入 Score 表

![](https://cdn.hurra.ltd/img/20201005170843.png)

同样显示因为外键约束错误, 插入失败, 因为 s_id 的值在 Stu 表中不存在