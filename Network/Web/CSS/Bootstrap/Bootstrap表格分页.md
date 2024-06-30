<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: dalao
 * @LastEditTime: 2023-04-05 02:01:37
-->

# Bootstrap表格分页

## 效果

![](https://cdn.hurra.ltd/img/20200708224302.png)

<center>每页显示一定量数据</center>

![](https://cdn.hurra.ltd/img/20200708224344.png)

![](https://cdn.hurra.ltd/img/20200708224537.png)

<center>按关键字显示数据</center>

![](https://cdn.hurra.ltd/img/20200708234616.png)

<center>点击表格后显示被点击行的信息</center>

## 前端

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <title></title>
    <link rel="stylesheet" href="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css"/>
    <script src="https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js"></script>
    <script src="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <link rel="stylesheet" type="text/css" href="https://www.huangwx.cn/css/sweetalert.css"/>
    <script type="text/javascript" src="https://www.huangwx.cn/js/sweetalert-dev.js"></script>
    <link rel="stylesheet" href="https://unpkg.com/bootstrap-table@1.16.0/dist/bootstrap-table.min.css"/>
    <script src="https://unpkg.com/bootstrap-table@1.16.0/dist/bootstrap-table.min.js"></script>
    <script src="https://unpkg.com/bootstrap-table@1.16.0/dist/locale/bootstrap-table-zh-CN.min.js"><script>
  </head>
  <body>
    <div style="text-align: center;">
      <h2>Bootstrap表格分页示例</h2>
    </div>

    <table class="table table-hover" id="demoTable">
      <thead>
        <tr>
          <th>学号</th>
          <th>姓名</th>
          <th>年龄</th>
          <th>性别</th>
        </tr>
      </thead>
      <tbody>
        <!--这里使用Flask作为后端-->
        {% for i in data %}
        <tr>
          <td>{{ i.num }}</td>
          <td>{{ i.name }}</td>
          <td>{{ i.age }}</td>
          <td>{{ i.sex }}</td>
        </tr>
        {% endfor %}
      </tbody>
    </table>
  </body>
  <script>
    // 实现表格分页
    $("#demoTable").bootstrapTable({
      // 点击行事件, element为被点击行的tr元素对象
      onClickRow: function (row, $element) {
        $element.each(function () {
          // 获取所有td的值
          const tds = $(this).find("td");
          const num = tds.eq(0).text();
          const name = tds.eq(1).text();
          const age = tds.eq(2).text();
          const sex = tds.eq(3).text();
          ...
        });
      }, 
      // 首页页码
      pageNumber: 1, 
      // 是否显示分页条
      pagination: true, 
      // 一页显示的行数
      pageSize: 5, 
      // 是否开启分页条无限循环
      paginationLoop: false, 
      // 选择每页显示多少行
      pageList: [5, 10, 20], 
      // 启用关键字搜索框
      search: true, 
    });
  </script>
</html>
```
