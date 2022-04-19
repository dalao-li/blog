<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-27 20:45:27
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-19 22:38:14
-->

## string函数


- 头文件

```c
#include<string.h>
```



### 函数


| 函数             | 说明                                                        |
| ---------------- | ----------------------------------------------------------- |
| `strlen(s1)`     | 返回s1 的长度。                                             |
| `strcmp(s1, s2)` | 若 s1 == s2，值 0<br>若 s1<s2 值小于 0<br>若 s1>s2 值大于 0 |
| `strchr(s1, ch)` | 返回一个指针，指向 ch在s1中首次出现位置                     |



### strstr


- 查找 s2在s1中首次出现的位置，返回第一次出现s2的位置，若未找到则返回NULL

```c
char *strstr(const char *s1, const char *s2)
```

```c
const char haystack[20] = "RUNOOB";
const char needle[10] = "NOOB";
char *ret;

// NOOB
ret = strstr(haystack, needle);
```



### strcat


- 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾

```c
char *strcat(char *dest, const char *src)
```

```c
char src[50], dest[50];

strcpy(src, "AAAA");
strcpy(dest, "BBBB");

strcat(dest,src);

// BBBBAAAA
printf("%s\n", dest);
```



### strcpy


- 把 src 所指向的字符串复制到 dest

```c
char *strcpy(char *dest, const char *src)
```

```c
char a[7] = "abcdef";
char b[4] = "ABC";

strcpy(a,b);

// ABC
printf("%s\n", a);
```



### memset


- 复制字符 c(一个无符号字符)到参数 str 所指向字符串的前 n 个字符

```c
void *memset(void *str , int c , size_t n)
```
| 参数 | 含义                   |
| ---- | ---------------------- |
| str  | 指向要填充的内存块     |
| c    | 要被设置的值           |
| n    | 要被设置为该值的字符数 |

```c
int a[10];

// 给数组a赋值0
memest(a, 0, sizeof(a));
```