<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-22 13:17:11
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 19:59:22
-->

## 部署Registry

```sh
docker run -itd \
    -p 15000:5000
    -v /usr/local/registry:/var/lib/registry
    --name my_registry
    registry
```

```sh
docker run -itd -p 15000:15000 -v /usr/local/registry:/var/lib/registry --name my_registry registry
```

- 上传

```sh
docker push IP:端口/镜像名
```

- 下载
  
```sh
docker pull IP:端口/镜像名
```