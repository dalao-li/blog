<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-11 11:44:56
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-12 22:03:23
-->

## 扇区(sector)

硬盘的最小存储单位是扇区，每个扇区储存$512$字节($0.5KB$)

## 块(block)

$OS$读取硬盘时为提高效率，会一次性连续读取多个扇区，即一个块($block$)

块由多个扇区组成，是文件存取的最小单位，大小常见为$4KB$，即连续八个扇区组成

## inode

文件数据都储存在块中，还需储存如文件的创建者、文件的创建日期、文件的大小等文件的元信息，储存文件元信息的区域就是$inode$(索引节点)

每个文件都有对应的$inode$，内容包含


- 文件的字节数

- 文件拥有者的User ID

- 文件的Group ID

- 文件的读、写、执行权限

- 文件的时间戳，

    ctime指inode上一次变动的时间
  
    mtime指文件内容上一次变动的时间
  
    atime指文件上一次打开的时间.

- 链接数，即有多少文件名指向这个inode

- 文件数据block的位置


硬盘格式化的时候OS自动将硬盘分成两个区域

- 数据区，存放文件数据

- $inode$区($inode$ $table$)，存放$inode$所包含的信息

每个$inode$节点的大小一般是$128$字节或$256$字节，硬盘格式化时就会给定$inode$节点的总数，一般是每$1KB$或$2KB$设置一个$inode$

如$1GB$的硬盘中，每个$inode$节点的大小为$128$字节，每$1KB$就设置一个$inode$，那么$inode$ $table$的大小为$128MB$，占硬盘空间的$12.8\%$

### inode作用

$inode$号码与文件名分离，导致了$Unix/Linux$系统特有的现象

- 删除文件

当文件名包含特殊字符无法正常删除时，可直接删除$inode$节点，即可删除文件

- 移动/重命名文件

只是改变文件名，不影响$inode$号码

- 文件操作

打开一个文件后，系统就以$inode$号码来识别它，而不再考虑文件名.

通常来说系统通过$inode$号码识别运行中的文件，不通过文件名，这使得可在不关闭软件的情况下进行更新.

更新时，新版文件以同样的文件名，生成一个新的$inode$，不会影响到运行中的文件.下次运行软件的时候，文件名就自动指向新版文件，旧版文件的$inode$则被回收

## 命令

```sh
# 查看分区的indoe信息
df -i
```
![](https://cdn.hurra.ltd/img/20210311131328.png)

```sh
# 查看文件indoe信息
stat 文件
```

![](https://cdn.hurra.ltd/img/20210311115029.png)

```sh
# 查看文件的indoe号码
ls -i
```
![](https://cdn.hurra.ltd/img/20210311132619.png)

```sh
# 硬链接，indoe号码与源文件相同
ln 源文件 链接文件
```
![](https://cdn.hurra.ltd/img/20210311133933.png)

```sh
# 软链接，号码不同但是indoe号码指向的是源文件的名字
ln -s 源文件 链接文件
```
![](https://cdn.hurra.ltd/img/20210311134110.png)

- 

```sh
# 通过inode删除/root/目录下的new.sh文件
find [搜索的路径] -inum [文件的indoe号码] -delete
```
![](https://cdn.hurra.ltd/img/20210311135552.png)



