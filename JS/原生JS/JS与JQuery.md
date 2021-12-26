<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-18 16:29:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-07 00:30:52
-->

```html
<input type="text" id="name" />

<button type="button" id="addBtn"></button>
```

## 获取控件

```js
// js可直接获取当前对象 
document.getElementById("id")

// jQuery 利用$("#id")获取的是一个[object Object]，需修改为
$("#id")[0] 或 $("#id").get(0)
```

## 获取值

```js
// js
document.getElementById("name").value();

// jquery
$("#name").val();
```

## 事件

```js
// js
const addBtn = document.getElementById("addBtn");

addBtn.addEventListener("click"， ()=>{
    ...
})

// JQuery
$("#addBtn").click(functon(){
    ...
})
```

## 匿名函数
```js
// js
()=>

// jQuery
function(){}
```
