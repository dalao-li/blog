<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-02-28 21:17:13
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-15 11:00:24
-->

# isort


PEP8 有建议 Python 模块中 import 的导入顺序

- 首先引入标准库里的模块

- 然后引入第三方模块

- 最后引入自己的模块



## isort 的作用

可以自动将 Python 模块中的 import 进行排序, 并自动按类型划分以满足上面说的 PEP8 规范

属于同一个部分的 import 语句按字母顺序排列

```sh
pip install isort
```


## 排序

- 当前目录所有文件

```py
isort .
```

- 查看修改建议, 但不会修改文件

```py
isort mypythonfile.py --diff
```
