<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-08 15:24:45
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-27 22:24:49
-->

## selenium


### 下载 chromedriver


下载与谷歌浏览器版本对应的chromedriver.exe并放在谷歌浏览器的安装目录与Python安装目录下


### 模拟搜索

```py
from selenium import webdriver
from selenium.webdriver.common.keys import Keys

# 打开浏览器
browser = webdriver.Chrome()

# 获取页面
browser.get('https://www.baidu.com')

# 定位到搜索框
inputs = browser.find_element_by_id("kw")

# 输入值
inputs.send_keys('python')

# 提交
inputs.submit()
```

![](https://cdn.hurra.ltd/img/20210308152746.png)



### 元素定位

```py
find_element_by_id()

find_element_by_name()

find_element_by_class_name()

find_element_by_tag_name()

find_element_by_link_text()

find_element_by_partial_link_text()

find_element_by_xpath()

find_element_by_css_selector()
```


### 浏览器操作

- 控制浏览器大小

```py
browser = webdriver.Chrome()

browser.set_window_size(480, 800)
```

- 浏览器后退, 前进

```py
# 后退
browser.back()

# 前进
browser.refresh()
```

- 刷新

```py
browser.refresh() 
```


### 键盘鼠标操作

- 点击和输入

```py
# 清除文本
browser.find_element_by_id("kw").clear()  

# 模拟按键输入
browser.find_element_by_id("kw").send_keys("selenium")  

# 单机元素
browser.find_element_by_id("su").click() 
```

- 提交

```py
text = browser.find_element_by_id('kw') 

text.send_keys('selenium') 

text.submit()
```

- 键盘操作

```py
from selenium import webdriver
from selenium.webdriver.common.keys import Keys


# 删除键(BackSpace
send_keys(Keys.BACK_SPACE) 

# 空格键(Space)
send_keys(Keys.SPACE) 

# 回退键(Esc)
send_keys(Keys.ESCAPE) 

# 回车键(Enter)
send_keys(Keys.ENTER) 

# 全选(Ctrl+A)
send_keys(Keys.CONTROL, 'a') 

# 复制(Ctrl+C)
send_keys(Keys.CONTROL, 'c') 

# 剪切(Ctrl+X)
send_keys(Keys.CONTROL, 'x') 

# 粘贴(Ctrl+V)
send_keys(Keys.CONTROL, 'v') 

# 键盘 F1
send_keys(Keys.F1) 
......
```


### 获取断言信息

```py
# 打印当前页面title
title = browser.title 

# 打印当前页面URL
now_url = browser.current_url 

# 获取结果数目
user = browser.find_element_by_class_name('nums').text
```