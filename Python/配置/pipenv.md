<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email:  
 * @Date: 2021-01-22 21:58:02
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 15:24:06
-->

# Pipenv

Python依赖管理工具, pip和virtualenv的组合体, 基于 Pipfile 的依赖记录方式, 用于替代requirements.txt.

pipenv 会自动管理虚拟环境和依赖文件, 并且提供一系列命令和选项来实现各种依赖和环境管理相关的操作, 它更方便、完善和安全.

```sh
# 安装
pip install pipenv

# 创建
pipenv install
```

- 若项目目录中虚拟环境未创建且无 Pipfile 文件, 将安装虚拟环境并创建 Pipfile 文件

- 若项目目录中虚拟环境未创建且有 Pipfile 文件, 将根据 Pipfile 文件来安装相应 python 版本和依赖包

- 若项目目录中虚拟环境已创建且有 Pipfile 文件, 将根据 Pipfile 文件来安装依赖包

使用 pipenv 创建虚拟环境, 自动生成一个随机的虚拟环境目录名

如果在windows 系统下执行命令, 生成的虚拟环境在 C:\Users\用户名\.virtualenvs 文件夹下.

虚拟环境目录名的前缀是创建环境时所在的项目目录名, 如在 myblog 目录下执行命令, 虚拟环境的目录名称就是 myblog-<随机字符串>

```sh
# 进入
pipenv shell
``` 

```sh
# 安装
pipenv install requests
```

不管是否激活虚拟环境, 都可以执行 pipenv install 库名来安装.

```sh
# 查看已经安装模块
pipenv graph
```

```sh
# 卸载
pipenv uninstall requests

# 全部卸载
pipenv uninstall --all
```

```sh
# 显示目录信息即路径
pipenv --venv

# 显示虚拟环境的信息
pipenv --where

# 通过 requirements.text 安装模块
pipenv install -r requirements.txt
```