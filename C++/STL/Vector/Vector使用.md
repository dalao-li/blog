<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-15 20:40:55
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-28 00:39:57
-->


## 初始化

```c
vector<T> v;
```

- 二维Vector

```c
vector<vector<T> > v;
```

## 增加

- 尾部插入

```c
v.push_back(value);
```

## 删除

```c
// 删除x，y之间的元素
v.earse(v.begin() + x , v.end() - y);
```
- 清空

```c
v.clear();
```
## 遍历

```c
for(vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
	// *it
}
```

## 翻转

```c
reverse(v.begin()，v.end());
```

