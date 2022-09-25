<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-11-09 00:07:41
 * @LastEditors: daLao
 * @LastEditTime: 2022-09-15 00:19:43
-->

## cp


用于宿主机与容器内文件拷贝


### 宿主机 --> 容器

```sh
docker cp [宿主机中文件路径] [容器ID]:[容器目标路径]
```


### 容器 --> 宿主机

```sh
docker cp [容器ID]:[容器中文件路径] [宿主机目标路径]
```
