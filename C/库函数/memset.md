<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-28 12:17:39
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-09 21:37:30
-->

## memset

- 复制字符 c(一个无符号字符)到参数 str 所指向字符串的前 n 个字符

```c
void *memset(void *str, int c, size_t n)
```
| 参数 | 含义                   |
| ---- | ---------------------- |
| str  | 指向要填充的内存块     |
| c    | 要被设置的值           |
| n    | 要被设置为该值的字符数 |

示例，给数组a赋值0

```c
int a[10];

memest(a, 0, sizeof(a));
```