<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-14 14:20:16
-->

## Windows平台

- 编译

QT IDE 选择 Release 模式编译，将 build-....文件夹中的 exe 文件拷贝到根文件夹

- 打包

```sh
# 进入 QT 命令行，到当前目录
windeployqt 名字.exe
```
