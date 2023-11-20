<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-11-18 21:54:04
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-11-19 22:52:35
-->
# ctypes

参考

- [Python--ctypes(数据类型详细踩坑指南)](https://zhuanlan.zhihu.com/p/145165873)

## 普通函数

```c++
int add(int x, int y) {
    return x + y;
}
```

```py
dll = cdll.LoadLibrary('...')

x, y = 1, 2
res = dll.add(x, y)
```

## 数组

```c
int get_array(int a[], int index) {
    int len = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < len; ++i) {
        a[i] *= 2;
    }

    return a[index];
}
```

```py
dll = cdll.LoadLibrary('...')

a = [1, 2, 3, 4, 5]

array = (c_int * 5)(*a)
res = dll.get_array(array, c_int(1))
print(res)

```


## 指针

```c++
void set_pointer(int* a) {
    *a = 0xFFFF;
}
```

```py
dll = cdll.LoadLibrary('...')

p = pointer(c_int(1))

dll.set_pointer(p)
print(p.contents)
```