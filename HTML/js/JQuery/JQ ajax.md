<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-13 20:43:00
-->

## HTTP请求

```js
$.get(URL，callback)


$.post(URL，data，callback)
```

## 封装 Ajax

| 参数     | 含义       |
| -------- | ---------- |
| type     | 请求方式   |
| url      | 发送的 url |
| parm     | 发送的数据 |
| callback | 回调函数   |

```javascript
//发送ajax请求
function sendAjax(type， url， param， callback) {
  $.ajax({
    async: false，
    ache: false，
    type: type，
    url: url，
    //将发送的数据转换为JSON字符串
    data: JSON.stringify(param)，
    //服务端返回数据的格式
    dataType: "json"，
    success: function (data) {
      callback(data.result);
    }，
    error: function () {
      //失败处理
    }，
  });
}
```

## 示例

```js
// 回调函数
function login_callback(value) {
  switch (value) {
    case 1:
      alert("登录成功");
      window.location.href = "index.html"
      break;
    case 0:
      alert("密码错误");
      $("#pass").val("")
      break;
    case -1:
      alert("该账号不存在")
      $("#name").val("")
      break;
  }
}
```

```js
// 登录函数
function userLogin(name， pwd) {
  if (name === "") {
    alert("请输入用户名");
    return;
  }
  if (pwd === "") {
    alert("请输入密码");
    return;
  }
  const data = {status: 1，name: name，pwd: pwd，};

  sendAjax("POST"， "/api"， data， login_callback);
}
```
