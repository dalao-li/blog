<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-06 13:09:18
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-10 14:52:02
-->

## 单元测试


单元测试是指, 对软件中的最小可测试单元在与程序其他部分相隔离的情况下进行检查和验证的工作

最小可测试单元通常是指函数或者类, 一般是开发来做, 按照测试阶段来分, 为单元测试、集成测试、系统测试以及验收测试


### unittest框架

- test case

测试用例, unittest中提供了一个基本类TestCase, 可以用来创建新的测试用例

调用run()方法, 会依次调用setUp方法、执行用例的方法、tearDown方法.

- test fixure

测试夹具, 用于测试用例环境的搭建和销毁

用例测试前准备环境的搭建(SetUp前置条件), 测试后环境的还原(TearDown后置条件), 比如测试前需要登录获取token等就是测试用例需要的环境, 运行完后执行下一个用例前需要还原环境

- test suite

测试套件, 用来把需要一起执行的测试用例集中放到一块执行, 可以通过addTest()方法手动增加Test Case, 也可以通过TestLoader自动添加Test Case, TestLoader在添加用例时会没有顺序

- test runner

执行测试用例, 并返回测试用例的执行结果.它还可以用图形或者文本接口, 把返回的测试结果更形象的展现出来, 如:HTMLTestRunner


### TestCase测试用例

编写测试用例前, 需建一个测试类继承unittest里的TestCase类, 编写测试用例的步骤如下

- 导入unittest模块
  
- 创建一个测试类, 并继承unittest.TestCase()
  
- 定义测试方法, 方法名必须以test_开头
  
- 调用unittest.main()方法来运行测试用例, unittest.main()方法会搜索该模块下所有以test开头的测试用例方法, 并自动执行


以注册功能为例

- 注册功能

```py
# register.py
users = [{'name': 'test', 'pwd': '123456'}]

def register(name, pwd1, pwd2):
    if not all([name, pwd1, pwd2]):
        return {
            "code": 0, 
            "msg": "所有参数不能为空"
        }
    for user in users:
        if name == user['name']:
            return {
                "code": 0, 
                "msg": "该用户名已存在！"
            }
    if pwd1 != pwd2:
        return {
            "code": 0, 
            "msg": "两次密码输入不一致！"
        }
    if 6 <= len(name) <=18 and 6 <= len(pwd1) <= 18:
        users.append({'name': name, 'pwd': pwd2})
        return {
            "code": 1, 
            "msg": "注册成功"
        }
    else：
        return {
            "code": 0, 
            "msg": "用户名和密码必须在6-18位之间"
        }
        
```

- 测试代码

```py
import unittest

# 导入被测试的代码
from register import register

# 注册接口测试用例类
class TestRegister(unittest.TestCase):

    # 注册成功
    def test_register_success(self):
        # 测试数据
        data = ("mikitest", "miki123", "miki123")
        # 把测试数据传到被测的代码, 接收实际结果
        result = register(*data)
        # 预期结果
        expected = {
            "code": 1, 
            "msg": "注册成功!"
        }
        # 断言, 预期和实际是否一致, 一致即用例通过
        self.assertEqual(expected, result)

    # 注册失败, 用户名为空
    def test_username_isnull(self):
        data = ("", "miki123", "miki123")
        result = register(*data)
        expected = {
            "code": 0, 
            "msg": "所有参数不能为空！"
        }
        self.assertEqual(expected, result)

    # 注册失败, 用户名大于18位
    def test_username_lt6(self):
        data = ("mikitestmikitestmikitest", "miki123", "miki123")
        result = register(*data)
        # 这条用例应该是不通过的, 注册代码bug
        expected = {
            "code": 0, 
            "msg": "用户名和密码必须在6-18位之间！"
        }
        self.assertEqual(expected, result)

    # 注册失败, 两次密码不一致
    def test_passwd(self):
        data = ("miki123", "test123", "test321")
        result = register(*data)
        expected = {
            "code": 0, 
            "msg": "两次密码输入不一致！"
        }
        self.assertEqual(expected, result)


# 如果直接运行这个文件, 需要使用unittest中的main函数来执行测试用例
if __name__ == '__main__':
    unittest.main()
```
