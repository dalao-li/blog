<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-01-01 01:39:36
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-26 23:55:13
-->

# JQ语法

```html
<input type="text" id="name" />

<button type="button" id="addBtn"></button>
```

## 获取控件

利用$("#id")获取的是一个[object Object]

```js
$("#id")[0] 或 

$("#id").get(0)
```

## 获取值

```js
$("#id").val();
```

## 事件

```js
$("#addBtn").click(functon(){
    //...
})
```

## 匿名函数

```js
function(){}
```

## HTTP请求

```js
$.get(URL, callback)


$.post(URL, data, callback)
```

### 封装 Ajax

| 参数     | 含义       |
| -------- | ---------- |
| type     | 请求方式   |
| url      | 发送的 url |
| parm     | 发送的数据 |
| callback | 回调函数   |

```js
// 发送ajax请求
function sendAjax(type, url, param, callback) {
    $.ajax({
        async: false, 
        ache: false, 
        type: type, 
        url: url, 
        // 将发送的数据转换为JSON字符串
        data: JSON.stringify(param), 
        // 服务端返回数据的格式
        dataType: "json", 
        success: function (data) {
            callback(data.result)
        },
        error: function () {
        // 失败处理
    }, 
  })
}
```

### 获取表格值

```html
<form method="post" action="" id="form">
    用户名: <input type="text" name="username" /><br />
    密码: <input type="text" name="pwd" /><br />
    <button type="submit" value="" id="submit_demo">提交</button>
</form>
```

```js
function get_form_value() {
    var d = {};
    // serializeArray() 方法
    // 通过序列化表单值来创建对象(name 和 value)的数组
    const t = $("form").serializeArray();
    // .each() 对 jQuery 对象进行迭代, 为每个匹配元素执行函数
    $.each(t, function () {
        d[this.name] = this.value;
    })
    // 转换为JSON字符串
    return JSON.stringify(d);
}
```

`$.each()`函数
| 返回值       | 含义       |
| ------------ | ---------- |
| return false | `break`    |
| return true  | `continue` |

![](https://cdn.hurra.ltd/img/20200528224751.png)