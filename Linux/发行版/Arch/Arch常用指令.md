<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-06-13 20:32:36
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-16 12:45:19
-->

## 更新源



```sh
# 编辑 /etc/pacman.d/mirrorlist,添加
Server = https://mirrors.tuna.tsinghua.edu.cn/archlinux/$repo/os/$arch
```

```sh
# 更新软件包缓存
sudo pacman -Syy
```