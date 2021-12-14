<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-14 21:55:21
-->

## 事务

只有使用 $Innodb$ 数据库引擎的数据库或表才支持事务
  
事务处理可以用来维护数据库的完整性，保证 $SQL$ 语句要么全执行，要么全不执行
  
事务用来管理 $INSERT$、$UPDATE$、$DELETE$ 语句


## 原子性 

$Atomic$

一个事务中的全部操作，要么全部都完成，要么全部不完成.事务在执行过程中发生错误，会被回滚($rollback$)到事务开始前的状态

## 一致性 

$Consistency$

在事务开始之前和事务结束以后，数据库的完整性没有被破坏，表示写入的资料必须完全符合所有的预设规则，这包含资料的精确度、串联性以及后续数据库可以自发性地完成预定的工作

## 隔离性 

$Isolation$

隔离性可以防止多个事务并发执行时，由于交叉执行而导致对数据进行读写和修改产生不一致的情况

事务隔离分为不同级别，包括

- 读未提交($Read$ $uncommitted$)
  
- 读提交($Read$ $committed$)
  
- 可重复读($Repeatable$ $read$)
  
- 串行化($Serializable$)

- 持久性($Durability$)

事务处理结束后，对数据的修改就是永久的


