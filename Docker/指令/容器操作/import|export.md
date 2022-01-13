<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-02 03:13:57
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 12:41:48
-->

## 打包加载

- 打包
  
`docker export 容器ID > 压缩包.tar`


- 加载

`docker import 压缩包.tar 容器:tag`