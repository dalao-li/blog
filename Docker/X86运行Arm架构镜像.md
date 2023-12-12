<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-12-12 21:26:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-12 21:33:12
-->
# X86

## 拉取qemu

```sh
docker run --rm --privileged multiarch/qemu-user-static --reset --persistent yes
```

## 测试

```sh
docker pull arm32v7/gcc:9
```