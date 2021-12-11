<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-15 22:02:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-14 00:01:18
-->

## malloc函数

malloc 用于从堆中分配内存

```c
void *malloc(size_t size);
```

| 参数   | 说明                                                                                |
| ------ | ----------------------------------------------------------------------------------- |
| size_t | 申请的空间字节数<br>成功会返回该内存空间的地址(不会自动进行初始化)<br>失败返回 NULL |
| void * | 该函数返回类型不确定，通过接收的指针变量从而进行类型转换                            |

分配内存时需注意，即使在程序关闭时系统会自动回收该手动申请的内存，也要进行手动的释放，以保证内存能够在不需要时返回至堆空间，使内存能够合理的分配使用

## free 函数

free用于从堆中释放内存，释放需将指针指向NULL，否则会出现野指针

```c
void free(void *ptr);
```

```c
#include <stdio.h>
#include <malloc.h>

int main(void){
    char *p1 = (char *)malloc(1);
    char *p2 = (char *)malloc(1);

    printf("p1 = %d\n",p1);
    printf("p2 = %d\n",p2);

    free(p1);
    p1 = NULL;

    free(p2);
    p2 = NULL;
}
```
![](https://cdn.hurra.ltd/img/20211113234806.png)

动态分配的内存位于堆区中，堆地址`向上增长`

```c
// 动态数组
#include <stdio.h>
#include <malloc.h>

int main(void){
    int *p = (int *)malloc(4 * sizeof(int));
    
	for(int i = 0 ; i<4;i++){
		p[i] = i;
	}
    printf("%d"，p[1]);
    
    free(p);
    p = NULL;
}
```