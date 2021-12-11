<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-22 13:17:11
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-10 23:09:18
-->

## 部署Registry

```sh
docker run -itd \
    -p 15000:5000
    -v /usr/local/registry:/var/lib/registry
    --name my_registry
    registry

# docker run -itd -p 15000:15000 -v /usr/local/registry:/var/lib/registry --name my_registry registry
```

```sh
# 上传
docker push registry-host:端口/镜像名

# 下载
docker pull registry-host:端口/镜像名
```