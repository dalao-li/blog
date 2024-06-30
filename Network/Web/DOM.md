<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-02-08 20:42:19
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-19 12:06:37
-->

# DOM Nodes

## 节点

HTML 文档中的所有内容都是节点

- 整个文档是一个`文档节点`

- 每个 HTML 元素是`元素节点`, 例如\<html>, \<head>, \<title> 等

- HTML 元素内的文本是`文本节点`

- 每个 HTML 属性是`属性节点`, 例如<a>中的属性href
  
- 注释是`注释节点`

## 方法

- getElementById() 返回带有指定 ID 的元素

```html
<button id = 'submitBtn'>提交</button>

const b = document.getElementById("submitBtn")
```

- appendChild(node)

插入新的子节点(元素)

- removeChild(node)

删除子节点(元素)

- createAttribute()

创建属性节点

- createElement()

创建元素节点

- createTextNode()

创建文本节点

- getAttribute()

返回指定的属性值

- setAttribute()

把指定属性设置或修改为指定的值

## 属性

- innerHTML

节点(元素)的文本值

- parentNode

节点(元素)的父节点

- childNodes

节点(元素)的子节点

- attributes

节点(元素)的属性节点
