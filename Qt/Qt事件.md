<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2023-02-27 00:30:30
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 09:10:59
-->

# Qt 事件

[参考链接](https://www.cnblogs.com/linuxAndMcu/)

## Qt键盘事件

```c
#include <QKeyEvent>
```

### 按下

### 释放

## Qt鼠标事件

```c
#include <QMouseEvent>
```

### 按下

```c
void mousePressEvent(QMouseEvent *event);
```

- 判断鼠标键

```c
void MainWindow::mousePressEvent(QMouseEvent *event)
{   
    // 左键被按下
    if (event->button() == Qt::LeftButton) {
        // ...
    }
    // 右键被按下
    if (event->button() == Qt::RightButton) {
        // ...
    }
}

```

### 释放

```c
void mouseReleaseEvent(QMouseEvent *event);
```

### 移动

```c
void mouseMoveEvent(QMouseEvent *event);
```
