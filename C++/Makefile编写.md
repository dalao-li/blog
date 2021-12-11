<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-11 23:58:36
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-13 01:31:16
-->

## 手动编译

```c
//hellomake.c
#include"hellomake.h"
int main(){
    myPrintHelloMake();
    return 0;
}
```

```c
//hellofunc.c
#include<stdio.h>
#include"hellomake.h"

void myPrintHelloMake(){
    printf("Hello, makefiles!\n");
    return;
}
```

```c
//hellomake.h
void myPrintHelloMake();
```

```sh
# 编译两个c文件，并且生成可执行文件hellomake

# -I 告诉gcc从当前目录寻找头文件hellomake.h
gcc -o hellomake hellomake.c hellofunc.c -I.
```
![](https://cdn.hurra.ltd/img/20211112220904.png)

## Makefile v1

```makefile
hellomake: hellomake.c hellofunc.c
    gcc -o hellomake hellomake.c hellofunc.c -I.
```

![](https://cdn.hurra.ltd/img/20211112222231.png)

make命令不带参数会默认执行makefile文件中的第一条规则

通过将命令依赖的文件列表放在`:`之后的第一行，若其中的任何文件发生更改，make就会执行hellomake规则

##  Makefile v2

```makefile
# 定义使用哪个编译器
CC=gcc

# 编译标志，告诉make如何编译
CFLAG=-I.

# 将目标文件hellomake.o和hellofunc.o放入依赖列表，告知make首先编译.c文件得到目标文件，然后链接得到可执行文件hellomake
hellomake:hellomake.o hellofunc.o
    $(CC) -o hellomake hellomake.o hellofunc.o
```

![](https://cdn.hurra.ltd/img/20211112225303.png)

## Makefile v3

上个版本的makefile还忽略对头文件的依赖，若修改了hellomake.h文件，然后重新执行make，并不会重编头文件，需告诉make所有.c文件依赖哪些.h文件

```makefile
CC=gcc
CFLAG=-I.
# c文件依赖的头文件集合
DEPS = hellomake.h

# 规定.o文件依赖于同名的.c文件和DEPS中包含的头文件
%.o:%.c $(DEPS)
    $(CC) -c -o $@ $<  $(CFLAG)
hellomake:hellomake.o hellofunc.o
    $(CC) -o hellomake hellomake.o hellofunc.o
```

为产生.o文件，make需要使用CC常量定义的编译器编译.c文件

| 参数    | 含义                                  |
| ------- | ------------------------------------- |
| `-c`    | 产生目标文件                          |
| `-o $@` | 将输出文件命名为上一行`:`左边的文件名 |
| `$<`    | 依赖列表中首项                        |

![](https://cdn.hurra.ltd/img/20211113010244.png)

## Makefile v4

最后使用特殊宏`$@ $^`分别表示`:`左边和右边做最后一次简化

下例中，所有的头文件都应该作为DEPS宏的一部分，

```makefile
CC=gcc
CFLAG=-I.
DEPS=hellomake.h

# 所有目标文件.o作为OBJ宏的一部分
OBJ=hellomake.o hellofunc.o

%.o:%.c $(DEPS)
    $(CC) -c -o $@ $<  $(CFLAG)
hellomake: $(OBJ)
    $(CC) -o $@ $^ $(CFLAG)
```

## Makefile v5

若想把头文件，源文件和其他库文件分别放在不同文件夹，并隐藏中间文件(目标文件)，则需在makefile定义include文件夹，lib文件夹路径，并且把目标文件放到项目src文件夹的子文件夹obj里面

同时定义了宏，用于包含想要包含的库，还包含了一个规则用于清理source和obj文件夹，需使用make clean

.PHONY规则可以让make不去改动任何名为clean的文件（如果有的话）

```makefile
IDIR = ../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS=hellomake.h
DEPS=$(pathsubst %,$(IDIR)/%,$(_DEPS))

_OBJ= hellomake.o hellofunc.o
OBJ = $(pathsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o:%.c $(DEPS)
    $(CC -c -o $@ $< $(CFLAGS
hellomake:$(OBJS)
    $(CC) -o $@ $^ $(CFLAGS) $(LIBS)
.PHONY:clean
clean:
    rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
```


