<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-15 10:21:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-10 00:35:09
-->


## 获取容器ID

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
docker images | grep "容器名" &> /dev/null

# 若不存在
if $? -ne 0;then
    ....
fi
```


