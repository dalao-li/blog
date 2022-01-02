<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-02 21:05:18
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 21:07:31
-->

## 删除

- 强制删除

```sh
docker rm -f 容器ID
```

- 删除所有容器

```sh
docker rm $(docker ps -aq)
```

- 先停用删除

```sh
docker stop $(docker ps -aq) && docker rm $(docker ps -aq)
```