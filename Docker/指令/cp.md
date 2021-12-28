<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-09 00:07:41
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-13 23:28:08
-->

## 文件拷贝

- 宿主机 ==> 容器
```sh
docker cp 宿主机目录/文件 容器ID:容器内目录/文件
```

- 容器 ==> 宿主机

```
docker cp 容器ID:容器内目录/文件 宿主机目录/文件
```