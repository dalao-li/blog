<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-09 00:07:41
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-05 21:56:19
-->

## cp


用于宿主机与容器内文件拷贝


### 宿主机 --> 容器

```sh
docker cp [宿主机路径] [容器ID]:[容器路径]
```


### 容器 --> 宿主机

```sh
docker cp [容器ID]:[容器路径] [宿主机路径]
```
