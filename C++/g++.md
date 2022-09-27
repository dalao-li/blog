<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-26 22:54:49
 * @LastEditors: daLao
 * @LastEditTime: 2022-09-26 22:56:34
-->

## g++

### 优化

- -O1：它主要对代码的分支,常量以及表达式等进行优化

- -O2：尝试更多的寄存器级的优化以及指令级的优化,它会在编译期间占用更多的内存和编译时间

- -O3：在O2的基础上进行更多的优化,例如普通函数的内联,针对循环的更多优化

- -Os：主要是对代码大小的优化