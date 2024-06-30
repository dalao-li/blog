<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email:  
 * @Date: 2023-04-17 09:00:16
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-03 00:42:15
-->

# QML调用C++

## 交互方式

​Qt 提供了两种在 QML 环境中使用 C++对象的方式

- C++中实现类, 注册为 QML的类型, 在 QML中使用该类型创建对象

- C++中构造对象, 将其设置为 QML 的上下文属性, 在QML 环境中直接使用该属性

## 交互约束

定义可以导出的 C++类前提条件要想将一个类或对象导出到 QML 中, 需满足

- 从 QObject 或 QObject 的派生类继承, 并使用Q_OBJECT宏

和使用信号与槽的前提条件一样, 这两个条件是为了让类能够进入Qt的元对象系统(meta-object system)中

只有使用元对象系统, 类的某些方法或属性才可能通过字符串形式的名字来调用, 才可在 QML 中被访问

- 成员函数想在 QML 中被调用, 则需要在声明前加上 `Q_INVOKABLE`

- 槽函数可以用类对象在QML代码中直接调用

- C++的成员属性可以用 `Q_PROPERTY` 宏设置

- 枚举需用 `Q_ENUMS` 导出

## 示例

- Controller类

```c++
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QString>


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);

    Q_INVOKABLE void PrintInfo();

    Q_INVOKABLE const QString GetInfo();
};

#endif // CONTROLLER_H
```

```c++
#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent) {}

void Controller::PrintInfo() {
    qDebug() << "Debug Info\n";
}

const QString Controller::GetInfo() {
    return "Hello World";
}
```

### 注册方式

C++中实现类, 注册为 QML的类型, 在 QML中使用该类型创建对象

- main.cpp

```c++
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // 注册
    qmlRegisterType<Controller>("io.qt.Controller", 1, 0, "Controller");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
```

- main.qml

```js
// import组件
import io.qt.Controller 1.0

// 添加组件
Controller {
    id: controller
}

Button {
    id: exchange

    text: "变换"

    onClicked: {
        // 调用
        controller.PrintInfo()

        exchange.text = controller.GetInfo()
    }
}
```

### 上下文方式

C++中构造对象, 将其设置为 QML 的上下文属性, 在QML 环境中直接使用该属性

- main.cpp

```c++
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller.h"


int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // 设置上下文属性
    QQmlContext *context = engine.rootContext();

    // 设置组件名称
    context->setContextProperty("ControllerDemo", new Controller);

    return app.exec();
}
```

- main.qml

```js
Button {
    id: exchange

    text: "变换"

    onClicked: {
        // 直接调用
        ControllerDemo.PrintInfo()

        exchange.text = ControllerDemo.GetInfo()
    }
}
```

## 参考

[QML调用C++代码](https://www.jianshu.com/p/c3f66b463ef3)

[QML入门教程(11) : qml C++交互介绍](https://mingshiqiang.blog.csdn.net/article/details/115032268)

[一文入门Qt Quick](https://mp.weixin.qq.com/s/dvamU6q5lZQb5hztfD2zNg)