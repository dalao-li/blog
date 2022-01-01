<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-03 02:43:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-01 01:46:15
-->

## JQ获取表格值

```html
<form method="post" action="" id="form">
    用户名: <input type="text" name="username" /><br />
    密码: <input type="text" name="pwd" /><br />
    <button type="submit" value="" id="submit_demo">提交</button>
</form>
```

```js
function get_form_value() {
  var d = {};
  // serializeArray() 方法
  // 通过序列化表单值来创建对象(name 和 value)的数组
  const t = $("form").serializeArray();

  // .each() 对 jQuery 对象进行迭代，为每个匹配元素执行函数
  $.each(t , function () {
    d[this.name] = this.value;
  })
    
  // 转换为JSON字符串
  return JSON.stringify(d);
}
```

`$.each()`函数
| 返回值       | 含义       |
| ------------ | ---------- |
| return false | `break`    |
| return true  | `continue` |

![](https://cdn.hurra.ltd/img/20200528224751.png)



