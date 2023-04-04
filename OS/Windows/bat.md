<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-10-26 22:19:58
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:48:35
-->

## bat


### 指令


#### 注释


```bat
REM 注释内容

:: 注释内容
```



#### 系统变量


```bat
REM 获取当前目录
%CD%

REM 获取命令搜索路径
%PATH%

REM 获取当前时间
%TIME%

REM 获取当前日期
%DATE%

REM 获取上一命令执行结果码
%ERRORLEVEL% 
```



#### echo


```bat
REM 输出提示信息
echo 输出内容

REM @echo将关闭该命令回显, 即执行时不会显示该命令
@echo 输出内容
```

- 关闭回显

```bat
@echo off
```



#### 跳转

goto 和 :


```bat
REM 建立index标号
:index

REM 跳转到index标号处, 注意标号需以字母开头
goto index
```



#### 文件


```bat
REM 复制文件

copy 原路径 目标路径
```