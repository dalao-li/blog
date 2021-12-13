<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-05 23:22:18
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-13 20:42:03
-->

## 提示框回调

```js
alert()
```

## 确认提示框
 
```js
const msg = "内容？\n\n请确认！"

// 确认按钮
if (confirm(msg)){
    
}
// 取消按钮
else{
    
}
```

## 输入提示框

```js
const value = prompt("Input Text"，"Default Text")

if (value != null && value != ""){
    alert(value)
}
```