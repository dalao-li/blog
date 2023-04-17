

<!--

 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-15 10:21:24
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 16:50:39
-->

# Shell Docker

## 删除

### 删除none镜像

```sh
docker rmi -f  `docker images | grep '<none>' | awk '{print $3}'` 
```

### 删除异常容器

```sh
docker rm `{docker ps -a | grep Exited | awk '{print $1}'`
```

### 获取容器ID

```sh
$(docker ps | grep "容器名" | awk '{print $1}') 或

$(docker ps -aqf "name=容器名")
```

| 参数 | 说明                   |
| ---- | ---------------------- |
| a    | 即使容器没运行也能获取 |
| q    | 仅输出容器ID           |
| f    | filter                 |

## 判断容器是否存在

```sh
name=""

docker images | grep ${name} &> /dev/null

# 若不存在
if $? -ne 0;then
    ...
fi
```

## 备份还原

### 备份

```sh
docker images | awk '{print $1}' > images.txt

sed -i '1d' images.txt

while read -r line; do
    file=${line//\//_}.tar
    if [ ! -f "$file" ]; then
        docker save "$line" > "$file"
        echo "docker saved $file"
    fi
done < images.txt
```

### 还原

```sh
while read -r line;do
    docker load < "\${line//\//_}".tar
done < images.txt
```

