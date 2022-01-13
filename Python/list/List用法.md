<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-04 01:28:59
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-14 05:43:36
-->

## List

- 创建

`a = []`

- 二维列表

建立 $x*y$ 大小的数组，初始值为 $z$

`[[z for i in range(x)] for j in range(y)]`

建立3*3二维数组，初始值0

```py
a = [[0 for i in range(3)] for j in range(3)]

a[0][0] = 1

a[1][1] = 3

# 3
print(a[1][1])

# [[1, 0, 0], [0, 3, 0], [0, 0, 0]]
print(a)
```

## List函数

- 添加

`append()` 列表末尾添加新值                                                  

`extend()` 末尾追加另一个序列中的多个值 

```py
a = [1, 2, 3]

# [1,2,3,4]
a.append(4)

# [1, 2, 3, 4, 5, 6, 7]
a.extend([5, 6, 7])
```

- 统计元素在列表中出现次数

`count()`

```py
a = [1, 1, 2, 3]

# 2
a.count(1)                                
```

- 删除

`pop([index])` 删除列表中index下标元素，index为空时删除末尾元素

```py
a = [1, 2, 3, 4]

# 4
a.pop()

# 2
a.pop(1)
```

- 处理 

`reverse()` 反向列表元素


