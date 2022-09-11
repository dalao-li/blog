<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-02 03:13:57
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-03 13:03:25
-->

## 打包加载


### export

打包

```sh
docker export 容器ID > 压缩包.tar
```


### import

加载

```sh
docker import 压缩包.tar 容器:tag
```