<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-04 01:28:59
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-04 01:46:13
-->

## 函数

| 函数                           | 作用                                   |
| ------------------------------ | -------------------------------------- |
| index(obj)                     | 从列表中找出某个值首次匹配项的索引位置 |
| insert(index, obj)             | 将对象插入列 表                        |
| remove(obj)                    | 移除列表中某个值的第一个匹配项         |
| sort( key=None, reverse=False) | 对原列表进行排序                       |


## 添加

- `append()`

列表末尾添加新值                                                  

- `extend()`

末尾追加另一个序列中的多个值 

```py
a = [1,2,3]

# [1,2,3,4]
a.append(4)

# [1, 2, 3, 4, 5, 6, 7]
a.extend([5,6,7])
```

## 统计

- `count()`

统计元素在列表中出现次数

```py
a = [1,1,2,3]

# 2
a.count(1)                                
```

## 删除

- `pop([index])`

删除列表中元素，默认删除末尾元素

```py
a = [1,2,3,4]

# 4
a.pop()

# 2
a.pop(1)
```

## 处理

- `reverse()`

反向列表元素