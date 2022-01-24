<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-01 01:39:36
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-18 15:59:08
-->

## 控件

```html
<input type="text" id="name" />

<button type="button" id="addBtn"></button>
```

- 获取控件

jQuery 利用$("#id")获取的是一个[object Object]

```js
$("#id")[0] 或 

$("#id").get(0)
```

- 获取值

```js
$("#id").val();
```

- 事件

```js
$("#addBtn").click(functon(){
    ...
})
```

- 匿名函数

```js
function(){}
```


## HTTP请求

```js
$.get(URL,callback)


$.post(URL,data,callback)
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
function sendAjax(type,url,param,callback) {
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
            callback(data.result);
        },
        error: function () {
        // 失败处理
    },
  })
}
```
