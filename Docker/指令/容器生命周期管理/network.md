<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-12 04:55:14
-->

## 网络

- 查看当前可使用网络
  
```docker
docker network ls
```

![](https://cdn.hurra.ltd/img/20211229000515.png)

- 创建网络

```sh
docker network create -d [类型] [网络名]
```

创建一个 docker 网络，命名为my_bridge

```sh
docker network create -d bridge my_bridge
```

![](https://cdn.hurra.ltd/img/20200726153641.png)

新建 box_3，使用 my_bridge 网络

```docker
docker run -itd --name box_3 --network my_bridge  busybox /bin/sh
```

![](https://cdn.hurra.ltd/img/20200726154102.png)

可看到 box_3  IP 为 172.18.0.2，与之前创建的容器网段不同

建立 box_4，使用 my_bridge 网络

![](https://cdn.hurra.ltd/img/20200726154325.png)

box_3 ping box_4

![](https://cdn.hurra.ltd/img/20200726154511.png)

box_4 ping box_3

![](https://cdn.hurra.ltd/img/20200726154622.png)