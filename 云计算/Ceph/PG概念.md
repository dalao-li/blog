<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-16 23:24:23
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-14 14:18:45
-->

## 概念

PG(Placement Groups)

CRUSH先将数据分解成一组对象，然后根据对象名称、复制级别和系统中的PG数等信息执行散列操作，再将结果生成PG ID

可以将PG看做一个逻辑容器，这个容器包含多个对象，同时这个逻辑对象映射之多个OSD上

如果没有PG，在成千上万个OSD上管理和跟踪数百万计的对象的复制和传播是相当困难的

没有PG这一层，管理海量的对象所消耗的计算资源也是不可想象的

建议每个OSD上配置50~100个PG