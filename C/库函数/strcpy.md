<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-28 12:45:28
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 12:47:25
-->


## strcpy

```c
// 把 src 所指向的字符串复制到 dest
char *strcpy(char *dest, const char *src)
```

```c
char a[7] = "abcdef";
char b[4] = "ABC";

strcpy(a,b);
// ABC
printf("%s\n",a);
```
