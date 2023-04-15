<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2023-03-10 00:22:04
 * @LastEditors: dalao
 * @LastEditTime: 2023-03-11 00:33:56
-->

# clang编译过程

```sh
clang++ -ccc-print-phases 源文件
```


```s
PS C:\Users\dalao\Documents> clang++ -ccc-print-phases .\main.cpp
            +- 0: input, ".\main.cpp", c++
         +- 1: preprocessor, {0}, c++-cpp-output
      +- 2: compiler, {1}, ir
   +- 3: backend, {2}, assembler
+- 4: assembler, {3}, object
5: linker, {4}, image
```

clang编译分为5个步骤(不包含上面的第0步)
preprocessor、compiler、backend、assembler、linker等


## 步骤


main.cpp 为输入的源码(对应步骤 0)

### .c -> .i

main.i 为预处理文件(对应步骤 1 的输出)

```sh
clang++ main.cpp -E -c -o main.i
```


### .i -> .bc

main.bc 为 bitcode文件, 是clang的一种中间表示(对应步骤 2 的输出)

```
clang main.i -emit-llvm  -c -o main.bc
```

(4) main.ll 为一种文本化的中间表示, 可以打开来看的(对应步骤 2 的输出,  和 .bc 一样都是中间表示, 可以相互转化)；

(5) main.s 为汇编结果(对应步骤 3 的输出)；

(6) main.o 为单文件生成的二进制文件(对应步骤 4 的输出)；

(7) image 为可执行文件(对应步骤 5 的输出)