<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email:  
 * @Date: 2023-04-19 00:22:12
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-28 22:32:52
-->

# Qt环境搭建

## Linux

### 在线安装

```sh
sudo apt-get install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qtcreator qtdeclarative5-dev qtquickcontrols2-5-dev
```

### 查看版本

```sh
qmake --version
```

![20230421000200](https://cdn.hurra.ltd/img/20230421000200.png)

### 问题

#### QtQuick.Controls 未注册

![20230422185540](https://cdn.hurra.ltd/img/20230422185540.png)

```sh
QtQuick.Controls": Cannot protect module QtQuick.Controls 2 as it was never registered
```

- 解决

```sh
sudo apt install qml-module-qtquick-controls2
```

- 参考

[import QtQuick.Controls 2.0 not working - QQmlApplicationEngine failed to load component](https://stackoverflow.com/questions/38030140/import-qtquick-controls-2-0-not-working-qqmlapplicationengine-failed-to-load-c)

## 安装模块

```sh
sudo apt install qml-module-qtquick-dialogs
```


## Windows


### 离线安装
[QT5.14下载地址](https://download.qt.io/archive/qt/5.14/5.14.0/qt-opensource-windows-x86-5.14.0.exe)


### 在线安装

- 下载

[https://download.qt.io/official_releases/online_installers/](https://download.qt.io/official_releases/online_installers/)

- 安装

```sh./qt-unified-windows-x64-X.X.X-online.exe --mirror https://mirror.nju.edu.cn/qt  
```