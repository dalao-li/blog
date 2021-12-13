<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-12 22:14:56
-->

## 创建文件

```py
# 文件已存在
if os.path.exists(file_path):
    return
f = open(file_path，'w'，encoding='utf-8')
if os.path.exists(file_path):
    f.close()
    # 创建成功
    return
# 创建失败
```

![](https://cdn.hurra.ltd/img/20200628230114.png)

## 修改文件

```py
# 'w'代表写入
# 'a'代表追加
with open(file_path， 'w'，encoding='utf-8') as f:
    f.write(data)
f.close()   
```

![](https://cdn.hurra.ltd/img/20200628231431.png)

![](https://cdn.hurra.ltd/img/20200628232636.png)

```py
# 重命名
os.rename(old_path， new_path)
```

![](https://cdn.hurra.ltd/img/20200628233529.png)

![](https://cdn.hurra.ltd/img/20200628234541.png)

## 读取文件

```py
with open(file_path， 'r'， encoding='utf-8') as f:
    # 整体读取
    data = f.read()

    # 逐行读取
    for i in f.readlines():
        ......
f.close()   
```

## 移动文件

```py
import os
import shutil

def move_file(source_path， target_path):
    if not os.path.isfile(source_path):
        print('待移动文件不存在')
        return
    file_path， file_name = os.path.split(target_path)
    if not os.path.exists(file_path):
        os.makedirs(file_path)
    # 复制文件 shutil.copyfile() 
    shutil.move(source_path， target_path)
    print('移动成功')

if __name__ == '__main__':
    source_path = 'D:/Code/Python/File/newFiles.txt'
    target_path = 'D:/Move/file.txt'
    move_file(source_path， target_path)
```

![](https://cdn.hurra.ltd/img/20200629001956.png)


```py
# 删除
def delete_file(source_path):
    if not os.path.exists(source_path):
        print('待删除文件不存在')
        return
    os.remove(source_path)
```



