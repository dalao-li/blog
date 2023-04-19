<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-19 12:03:09
-->

# Bootstrap表单

## 效果

![](https://cdn.hurra.ltd/img/20200526231712.png)

![](https://cdn.hurra.ltd/img/20200526231734.png)

![](https://cdn.hurra.ltd/img/20200526231855.png)

- 项目结构

![](https://cdn.hurra.ltd/img/20200526233425.png)

## head 部分

注意依赖文件的路径需根据自己实际下载文件路径进行修改, 网上教程中的代码无法直接使用往往就是因为依赖库没处理好

```html
<head>
  <title></title>
  <link rel="stylesheet" href="vendor/bootstrap/css/bootstrap.css" />
  <link rel="stylesheet" href="dist/css/bootstrapValidator.css" />
  <script
    type="text/javascript"
    src="vendor/jquery/jquery-1.10.2.min.js"
  ></script>
  <script
    type="text/javascript"
    src="vendor/bootstrap/js/bootstrap.min.js"
  ></script>
  <script type="text/javascript" src="dist/js/bootstrapValidator.js"></script>
  <style>
    .container {
      width: 500px;
      height: 1000px;
    }
  </style>
</head>
```

## body 部分

```html
<body>
  <div class="container">
    <div class="row">
      <!-- form: -->
      <section>
        <div class="col-lg-8 col-lg-offset-2">
          <div class="page-header">
            <h2>注册</h2>
          </div>

          <form
            id="defaultForm"
            method="post"
            class="form-horizontal"
            action=""
          >
            <div class="form-group">
              <label class="col-lg-3 control-label">用户名</label>
              <div class="col-lg-5">
                <input
                  type="text"
                  class="form-control"
                  name="username"
                  placeholder="5-15位字母或数字"
                />
              </div>
            </div>

            <div class="form-group">
              <label class="col-lg-3 control-label">邮箱</label>
              <div class="col-lg-5">
                <input
                  type="text"
                  class="form-control"
                  name="email"
                  placeholder="输入邮箱"
                />
              </div>
            </div>

            <div class="form-group">
              <label class="col-lg-3 control-label">密码</label>
              <div class="col-lg-5">
                <input
                  type="password"
                  class="form-control"
                  name="password"
                  placeholder="5-15位字母或数字"
                />
              </div>
            </div>

            <div class="form-group">
              <label class="col-lg-3 control-label">确认密码</label>
              <div class="col-lg-5">
                <input
                  type="password"
                  class="form-control"
                  name="confirmPassword"
                  placeholder="再次输入密码"
                />
              </div>
            </div>

            <div class="form-group">
              <label
                class="col-lg-3 control-label"
                id="captchaOperation"
              ></label>
              <div class="col-lg-2">
                <input
                  type="text"
                  class="form-control"
                  name="captcha"
                  placeholder="输入两数字之和"
                />
              </div>
            </div>
            <div class="form-group">
              <div class="col-lg-5 col-lg-offset-3">
                <div class="checkbox">
                  <input type="checkbox" name="acceptTerms" /> 同意协议
                </div>
              </div>
            </div>
            <div class="form-group">
              <div class="col-lg-9 col-lg-offset-3">
                <button
                  type="submit"
                  class="btn btn-primary"
                  name="signup"
                  value="Sign up"
                >
                  确认注册
                </button>
                <button type="button" class="btn btn-info" id="resetBtn">
                  重置表格
                </button>
              </div>
            </div>
          </form>
        </div>
      </section>
      <!-- :form -->
    </div>
  </div>
</body>
```

## JS 部分

```javascript
<script type="text/javascript">
        $(document).ready(function () {

            //产生随机数
            function randomNumber(min, max) {
                return Math.floor(Math.random() * (max - min + 1) + min);
            };

            //验证码
            $('#captchaOperation').html([randomNumber(1, 50), '+', randomNumber(1, 50), '='].join(' '));

            $('#defaultForm').bootstrapValidator({
                message: 'This value is not valid', 
                feedbackIcons: {
                    valid: 'glyphicon glyphicon-ok', 
                    invalid: 'glyphicon glyphicon-remove', 
                    validating: 'glyphicon glyphicon-refresh'
                }, 
                fields: {
                    username: {
                        message: 'The username is not valid', 
                        validators: {
                            notEmpty: {
                                message: '用户名不能为空'
                            }, 
                            stringLength: {
                                min: 5, 
                                max: 15, 
                                message: '用户名的长度应在5-15位字符'
                            }, 
                            regexp: {
                                regexp: /^[a-zA-Z0-9_\.]+$/, 
                                message: '用户名仅能由字母数字与下划线组成'
                            }, 
                            different: {
                                field: 'password', 
                                message: '用户名与密码不能相同'
                            }
                        }
                    }, 
                    email: {
                        validators: {
                            notEmpty: {
                                message: '邮箱不能为空'
                            }, 
                            emailAddress: {
                                message: '邮箱格式不正确'
                            }
                        }
                    }, 
                    password: {
                        validators: {
                            notEmpty: {
                                message: '密码不能为空'
                            }, 
                            identical: {
                                field: 'confirmPassword', 
                                message: '两次密码不相同'
                            }, 
                            different: {
                                field: 'username', 
                                message: '密码与用户名不能相同'
                            }
                        }
                    }, 
                    confirmPassword: {
                        validators: {
                            notEmpty: {
                                message: '确认密码不能为空'
                            }, 
                            identical: {
                                field: 'password', 
                                message: '两次密码不相同'
                            }, 
                            different: {
                                field: 'username', 
                                message: '密码与用户名不能相同'
                            }
                        }
                    }, 
                    captcha: {
                        validators: {
                            callback: {
                                message: '验证码错误', 
                                callback: function (value, validator) {
                                    var items = $('#captchaOperation').html().split(' '), 
                                        sum = parseInt(items[0]) + parseInt(items[2]);
                                    return value == sum;
                                }
                            }
                        }
                    }, 
                    acceptTerms: {
                        validators: {
                            notEmpty: {
                                message: '必须同意协议'
                            }
                        }
                    }, 
                }
            });

            $('#resetBtn').click(function () {
                $('#defaultForm').data('bootstrapValidator').resetForm(true);
            });
        });
    </script>
```
