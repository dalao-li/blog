<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-14 16:34:34
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-05 22:03:43
-->

### 获取控件ID

```html
<button type="button" class="btn btn-success" id="{{ i.id }}" onclick=download()>下载</button>
```

点击按钮获取控件的ID

```js
function download(){
    const id = event.target.id
    $.get('/del/' + id , function () {
            location.reload()
            alert("删除成功")
    })
}
```


### 动态ID

![](https://cdn.hurra.ltd/img/20200829232106.png)

当前为每行增加了一个 checkbox 控件，希望其动态生成"checkout+序号"的 id，方便后期对选择的行进行操作

```html
<td>
  <div class="checkbox">
    <label>
      <!-- {{i.id}}为后端传来的该行对应序号值-->
      <input type="checkbox" id="checkbox{{ i.id }}" />
    </label>
  </div>
</td>
```

此处为 jinja 模板，其他如 JSP 等等与此大同小异

![](https://cdn.hurra.ltd/img/20200829232740.png)
