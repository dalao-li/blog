<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-07 00:42:42
-->

## 概念

$JSON(JavaScript Object Notation)$ 是一种轻量级的数据交换格式，是$JavaScript$原生格式，有对象和数组两种结构

## JSON字符串

数据传输过程中，$JSON$ 以字符串形式传递

```js
// JSON字符串
const jsonstr = '{"name":"dalao"， "pwd":123}';

// 字符串转换为对象
const obj = jQuery.parseJSON(jsonstr)
```

## JSON对象

$JS$ 操作的是 $JSON$ 对象

```js
// JSON对象
const obj = { name: "dalao"， pwd: 123456 };

// 对象转换为字符串
const jsonstr = JSON.stringify(obj);
```

