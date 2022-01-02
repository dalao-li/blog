<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-09 00:07:16
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 05:47:20
-->

## 目录映射

`--mount` 指定挂载一个本地目录到容器中

```sh
--mount type=bind,source=[本地路径],target=[容器路径](权限)
```

例，将本地/src/webapp挂载到容器/usr/share/nginx/
```sh
docker run -d -P \
    --name web \
    --mount type=bind,source=/src/webapp,target=/usr/share/nginx/html \
    nginx:alpine
```
本地目录的路径必须是绝对路径

使用 `-v` 时，若本地目录不存在， Docker 会自动创建此文件夹

使用 `--mount` 时， 若本地目录不存在，Docker会报错

挂载主机目录的默认权限是`读写`，用户也可以通过增加 `readonly` 指定为只读

```sh
docker run -d -P \
    --name web \
    --mount type=bind,source=/src/webapp,target=/usr/share/nginx/html,readonly \
    nginx:alpine
```