<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-02 21:05:18
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-09 00:27:40
-->

# rm


## 强制删除

```sh
docker rm -f 容器ID
```


## 删除所有容器

```sh
docker rm $(docker ps -aq)
```


## 先停用删除

```sh
docker stop $(docker ps -aq) && docker rm $(docker ps -aq)
```