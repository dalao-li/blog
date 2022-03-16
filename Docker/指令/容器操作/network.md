<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-16 21:59:42
-->

## 网络

- 查看当前可使用网络
  
```sh
docker network ls
```

### 互联

- 创建网络

```sh
docker network create -d [类型] [网络名]
```

创建一个 docker 网络，命名为my_bridge

```sh
docker network create -d bridge my_bridge
```

![](https://cdn.hurra.ltd/img/20220316205625.png)


- 同网络互联

新建 box_3，使用 my_bridge 网络

```sh
docker run -itd --name box_3 --network my_bridge busybox
```

![](https://cdn.hurra.ltd/img/20220316215935.png)