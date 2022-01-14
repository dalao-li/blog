<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-14 16:34:34
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-14 16:38:28
-->

## 获取控件id

```html
<button type="button" class="btn btn-success" id="{{ i.id }}" onclick=download()>下载</button>
```

点击按钮获取控件的ID

```js
function download(){
    const id = event.target.id
    $.get('/del/' + id, function () {
            location.reload()
            alert("删除成功")
        })
    }
}
```