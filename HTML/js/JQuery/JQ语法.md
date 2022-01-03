<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-01 01:39:36
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-03 10:57:16
-->


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
