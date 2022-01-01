<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-22 23:42:03
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-10 21:21:16
-->

```py
from mongoengine import *

connect('admin'， host='localhost'， port=27017，username='admin'，password='123456')

class Score(EmbeddedDocument):
    name = StringField(required=True， max_length=200)
    score = IntField(required=True)

class User(Document):
    name = StringField(required=True， max_length=200)
    age = IntField(required=True)
    scores = ListField(EmbeddedDocumentField(Score))
    meta ={
        'collection': 'user'
    }
```

## 转JSON

```py
user = User.objects.filter(name='Wang').first().to_json(ensure_ascii=False)
```

## 增加

```py
User(....).create()

# 嵌套文档增加
scores = User.objects.filter(name='Wang').first().scores

scores = list(scores)

scores.append(Score(name='C++'，score=90))

User.objects.filter(name='Wang').first().update(scores=scores)
```

## 修改

```py
# 修改值 set__
User.objects.filter(name='Wang').update(set__age=27)

# 修改嵌套文档
```