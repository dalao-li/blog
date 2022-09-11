<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-08-31 21:07:07
 * @LastEditors: DaLao
 * @LastEditTime: 2022-08-31 21:16:46
-->

## logging 模块


### 日志级别

| 日志等级(level) | 描述                                                                                       |
| --------------- | ------------------------------------------------------------------------------------------ |
| DEBUG           | 最详细的日志信息, 典型应用场景是 问题诊断                                                  |
| INFO            | 信息详细程度仅次于DEBUG, 通常只记录关键节点信息,用于确认一切都是按照我们预期的那样进行工作 |
| WARNING         | 当某些不期望的事情发生时记录的信息(如,磁盘可用空间较低), 但是此时应用程序还是正常运行的    |
| ERROR           | 由于一个更严重的问题导致某些功能不能正常运行时记录的信息                                   |
| CRITICAL        | 当发生严重错误, 导致应用程序不能继续运行时记录的信息                                       |


### 函数

logging模块定义的模块级别的常用函数

| 函数                                   | 说明                                 |
| -------------------------------------- | ------------------------------------ |
| logging.debug(msg, *args, **kwargs)    | 创建一条严重级别为DEBUG的日志记录    |
| logging.info(msg, *args, **kwargs)     | 创建一条严重级别为INFO的日志记录     |
| logging.warning(msg, *args, **kwargs)  | 创建一条严重级别为WARNING的日志记录  |
| logging.error(msg, *args, **kwargs)    | 创建一条严重级别为ERROR的日志记录    |
| logging.critical(msg, *args, **kwargs) | 创建一条严重级别为CRITICAL的日志记录 |
| logging.log(level, *args, **kwargs)    | 创建一条严重级别为level的日志记录    |
| logging.basicConfig(**kwargs)          | 对root logger进行一次性配置          |