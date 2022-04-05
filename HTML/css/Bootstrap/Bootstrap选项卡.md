<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-05 22:03:10
-->

### 效果

![](https://cdn.hurra.ltd/img/20200524194114.png)

![](https://cdn.hurra.ltd/img/20200524194134.png)

- nav-link active 即默认选择的选项卡

- href 后跟选项卡对应页面的 id

- data-toggle="tab" 用以绑定触发事件，即点击不同选项卡时切换页面


### 全部代码

```html
<!DOCTYPE html>
<html lang="zh-CN">
  <head>
    <meta charset="UTF-8" />
    <link
      rel="stylesheet"
      href="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css"
    />
    <script src="https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js"></script>
    <script src="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js"></script>

    <style>
      .container {
        width: 500px;
        height: 1000px;
      }
    </style>
  </head>

  <body>
    <div class="container" style="margin-top:80px">
      <!--选项卡部分-->
      <nav class="navbar nav-tabs" role="navigation">
        <ul class="nav nav-tabs">
          <li class="nav-item ">
            <a class="nav-link active" href="#tab_login" data-toggle="tab"
              >登录</a
            >
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#tab_register" data-toggle="tab">注册</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#tab_modify" data-toggle="tab">修改</a>
          </li>
        </ul>
      </nav>

      <!--页面部分-->
      <div class="tab-content">
        <!--页面一-->
        <div id="tab_login" class="tab-pane  in active">
          <form action="" method="POST">
            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">用户名</span>
              </div>
              <label for="id"></label>
              <input
                type="text"
                class="form-control"
                id="name"
                name="name"
                placeholder="请输入用户名"
              />
            </div>

            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">密 码</span>
              </div>
              <label for="pwd"></label>
              <input
                type="password"
                class="form-control"
                id="pwd"
                name="pwd"
                placeholder="请输入密码"
              />
            </div>
            <button type="submit" class="btn btn-primary">登录</button>
          </form>
        </div>

        <!--页面二-->
        <div id="tab_register" class="tab-pane fade">
          <form action="" method="POST">
            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">用户名</span>
              </div>
              <label for="id"></label>
              <label for="regname"></label>
              <input
                type="text"
                class="form-control"
                id="regname"
                name="regname"
                placeholder="请输入用户名"
              />
            </div>

            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">密码</span>
              </div>
              <label for="name"></label>
              <label for="regpwd"></label>
              <input
                type="password"
                class="form-control"
                id="regpwd"
                name="regpwd"
                placeholder="请输入密码"
              />
            </div>
            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">确认密码</span>
              </div>
              <label for="name"></label>
              <label for="regpwds"></label>
              <input
                type="password"
                class="form-control"
                id="regpwds"
                name="regpwds"
                placeholder="请输入密码"
              />
            </div>

            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">邮箱</span>
              </div>
              <label for="email"></label>
              <input
                type="text"
                class="form-control"
                id="email"
                name="email"
                placeholder="请输入邮箱"
              />
            </div>
            <div class="input-group mb-3">
              <div class="input-group-prepend">
                <span class="input-group-text">身份</span>
              </div>
              <select class="form-control" name="identify">
                <option value="student">学生</option>
                <option value="teacher">教师</option>
              </select>
            </div>
            <button type="submit" class="btn btn-primary">提交</button>
          </form>
        </div>

        <!--页面三-->
        <div id="tab_modify" class="tab-pane fade">
          <form action="" method="POST"></form>
        </div>
      </div>
    </div>
  </body>
</html>
```