<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-18 16:29:32
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-05 02:03:56
-->

# JS用法


## 控件

```html
<input type="text" id="name" />

<button type="button" id="addBtn"></button>
```

### 获取控件

```js
document.getElementById("id")
```


### 获取值

```js
document.getElementById("id").value();

// div
document.getElementById("id").innerHTML
```


## 事件

```js
const addBtn = document.getElementById("addBtn");

addBtn.addEventListener("click", ()=>{
    ...
})
```

### 匿名函数

```js
()=>
```


## 弹窗


### 提示框回调

```js
alert()
```


### 确认提示框

```js
const msg = "内容？\n\n请确认！"

// 确认按钮
if (confirm(msg)){
    
} else {

}
```


### 输入提示框

```js
const value = prompt("Input Text", "Default Text")

if (value != null && value != "") {
    alert(value)
}
```


## HTTP


### GET

```js
function get(url, callback) {
    const XMLHttpRequest = require("xhr2")
    const httpRequest = new XMLHttpRequest()

    httpRequest.open("GET", url, true)
    httpRequest.send()
    httpRequest.onreadystatechange = () => {
        if (httpRequest.readyState == 4 && httpRequest.status == 200) {
            const json = httpRequest.responseText
            // ...
            callback()
        }
    };
}
```

![](https://cdn.hurra.ltd/img/20211113203754.png)


### POST

```js
function post(url, data, callback){
    const XMLHttpRequest = require("xhr2")
    const httpRequest = new XMLHttpRequest()

    httpRequest.open('POST', url, true)
    httpRequest.setRequestHeader("Content-type", "application/json")
    // 转为JSON字符串
    httpRequest.send(JSON.stringify(data))
    httpRequest.onreadystatechange = ()=> {
        if (httpRequest.readyState == 4 && httpRequest.status == 200) {
            const result = httpRequest.responseText
            callback(result)
        }
    }
}
```