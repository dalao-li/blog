<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-18 16:29:32
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-24 10:06:16
-->

# JS用法

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
