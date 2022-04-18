<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 10:04:26
-->


## Pipfile


- Pipfile 文件是 `TOML格式`而不是 requirements.txt 这样的纯文本.


- 一个项目对应一个 Pipfile，支持开发环境与正式环境区分.默认提供 default 和 development 区分


- 提供版本锁支持，存为 Pipfile.lock

```sh
# 创建
pipenv install
```

若项目中有 requirements.txt 文件，则生成对应内容的 Pipfile 文件与 Pipfile.lock 文件



### 内容


```sh
# 库安装源
[[source]]
url = "https://pypi.python.org/simple"
verify_ssl = true
name = "pypi"

# 用于开发环境的包
[dev-packages]
watchdog = "*"
faker = "*"

# 运行程序需要的包
[packages]
bootstrap-flask = "*"
flask-moment = "*"
flask-sqlalchemy = "*"
python-dotenv = "*"
flask-wtf = "*"
flask = "*"

# python版本
[requires]
python_version = "3.6"
```



### 全部安装


进入目录，创建虚拟环境

![](https://cdn.hurra.ltd/img/20210122224056.png)

打开 Pipfile 文件，修改为

```sh
[[source]]
url = "http://mirrors.aliyun.com/pypi/simple/"
verify_ssl = true
name = "pypi"

[packages]
flask = "*"

[dev-packages]
gunicorn = "*"

[requires]
python_version = "3.8"
```

安装，查看安装的包

![](https://cdn.hurra.ltd/img/20210122224537.png)

可以看到 Flask 包已经安装



### 部分安装


通常有一些 Python 包只在开发环境中需要，而不是在生产环境中，例如单元测试包

Pipenv 使用--dev 标志区分两个环境. 加 --dev 表示包括 Pipfile dev-packages 中的依赖

- 安装包记录是在[dev-packages] 部分，或是[packages] 部分


- 在安装时指定`--dev`参数，则安装全部的模块


- 若安装时不定指定`--dev` 参数，只会安装`[packages]` 下面的模块

另建立 Pipfile 文件

```sh
[[source]]
url = "http://mirrors.aliyun.com/pypi/simple/"
verify_ssl = true
name = "pypi"

[packages]
jieba = "*"

[dev-packages]
faker = "*"

[requires]
python_version = "3.8"
```

若输入 pipenv install 则只会安装[packages] 下的包

![](https://cdn.hurra.ltd/img/20210123141415.png)

若输入 pipenv install --dev 则安装项目的所有依赖项(包括dev)

![](https://cdn.hurra.ltd/img/20210123141743.png)