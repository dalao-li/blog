<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-20 20:16:43
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-07 00:54:24
-->
## 描述

![](https://cdn.hurra.ltd/img/20200829232106.png)

当前为每行增加了一个 checkbox 控件，希望其动态生成"checkout+序号"的 id，方便后期对选择的行进行操作

## 修改

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


