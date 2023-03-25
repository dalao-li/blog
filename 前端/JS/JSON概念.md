<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 20:00:51
-->

## JSON

JSON(JavaScript Object Notation) 是JavaScript原生格式, 有对象和数组两种结构


### JSON字符串

JSON 以字符串形式用于数据传输

```js
const str = '{"name":"dalao", "pwd":123}'
```

#### JSON字符串转换为对象

```sh
const obj = jQuery.parseJSON(str)
```

### JSON对象

JS 操作的是 JSON 对象

```js
const obj = { "name": "dalao", "pwd": 123456 }
```

#### JSON对象转换为字符串

```js
const str = JSON.stringify(obj)
```

