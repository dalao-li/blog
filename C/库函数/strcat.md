<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-28 12:47:56
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-09 21:38:12
-->

## strcat

- 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾
```c
char *strcat(char *dest, const char *src)
```

```c
char src[50], dest[50];
 
strcpy(src,"This is source");
strcpy(dest,"This is destination");

// This is destinationThis is source
strcat(dest,src);
```