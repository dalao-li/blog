<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email:  
 * @Date: 2023-04-19 09:08:42
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-20 15:36:50
-->

# QObject

## 派生

```c++
#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TEST_H
```

### 构造函数

```c++
#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}
```