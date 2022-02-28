## isort

PEP8 有建议 Python 模块中 import 的导入顺序

- 首先引入标准库里的模块

- 然后引入第三方模块

- 最后引入自己的模块


### isort 的作用

可以自动将 Python 模块中的 import 进行排序，并自动按类型划分以满足上面说的 PEP8 规范

属于同一个部分的 import 语句按字母顺序排列

```sh
pip install isort
```


### 排序

- 当前目录所有文件

```py
isort .
```

- 查看修改建议，但不会修改文件

```py
isort mypythonfile.py --diff
```
