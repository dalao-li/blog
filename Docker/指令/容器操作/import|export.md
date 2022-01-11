<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-02 03:13:57
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 03:16:52
-->

## 打包加载

- 打包
  
```sh
docker export 容器ID > 压缩包.tar
````
- 加载

```sh
docker import 压缩包.tar 容器:tag
```