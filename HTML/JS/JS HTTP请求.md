<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-07-13 08:46:53
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-06 21:07:01
-->

## GET

```js
function get(url , callback) {
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

## POST

```js
function post(url , data , callback){
    const XMLHttpRequest = require("xhr2")
    const httpRequest = new XMLHttpRequest()

    httpRequest.open('POST', url, true)
    httpRequest.setRequestHeader("Content-type","application/json")
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