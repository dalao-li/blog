<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-10-26 19:55:27
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-16 23:02:07
-->

# C语言变长参数

头文件

```c
#include <stdarg.h>
```

## 步骤

- 声明va_list

- 初始化 va_start

- 处理当前参数 va_arg

- 清理 va_end


## 函数原型

```c++
void func(char *fmt, ...)
```


## 声明

```c++
va_list ap;
```

va_list类型用于声明一个变量, 将一次引用各个参数


## 初始化

```c++
va_start(ap, fmt)
```

将ap初始化为指向第一个参数的指针


## 处理

```c++
va_arg(ap, 类型)
```

调用va_arg将当前指向的参数转换为对应类型并返回, 同时指针移动对应步长, 指向下个参数


## 清理

```c++
va_end()
```

清理工作


## 实现

```c++
#include <stdio.h>
#include <stdarg.h>

void MiniPrint(char *fmt, ...)
{
    char *p, *s;
    int n;
    double d;

    // 声明ap, 依次引用各参数
    va_list ap;

    // 初始化
    va_start(ap, fmt);

    // 处理每个参数
    for (char *p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*(++p))
        {
        case 'd':
            n = va_arg(ap, int);
            printf("%d", n);
            break;
        case 'f':
            d = va_arg(ap, double);
            printf("%f", d);
            break;
        case 's':
            for (s = va_arg(ap, char *); *s; s++)
            {
                putchar(*s);
            }
            break;
        default:
            putchar(*p);
            break;
        }
    }

    va_end(ap);
}

int main(void)
{
    char *name = "dalao";
    int age = 21;
    double weight = 98.2;

    // name = dalao, age = 21, weight = 98.200000
    MiniPrint("name = %s, age = %d, weight = %f", name, age, weight);
    return 0;
}
```