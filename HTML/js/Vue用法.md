<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 20:01:27
-->

## Vue


### Vue 安装

```sh
# vue换源
npm install -g cnpm --registry=http://registry.npm.taobao.org

# 安装全局vue-cli脚手架
sudo cnpm install --global vue-cli

vue init webpack [project_name]

sudo npm run dev

# 项目内安装
npm i element-ui -S
```

```js
this.axios.get("http://127.0.0.1:5000/test").then((response) =>{
    const r = response.data;
    console.log(r.result);
});

this.axios.post("http://127.0.0.1:5000/login", {
        name: this.param.username, 
        pwd: this.param.password, 
    }).then((response) => {
    const r = response.data;
    console.log(r.result);
});
```


### HTTP


#### GET 请求

```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8" />
        <title>Title</title>
        <script src="https://cdn.staticfile.org/vue/2.4.2/vue.min.js"></script>
        <script src="https://cdn.staticfile.org/axios/0.18.0/axios.min.js"></script>
    </head>

    <body>
        <div id="app">
            <h1>GET请求获取数据</h1>
            <div v-for="i in info">{{ i.name }}, {{i.age}}</div>
        </div>
        <script type="text/javascript">
        new Vue({
            el: "#app", 
            data() {
                return {
                    info: null, 
                };
            }, 
            mounted() {
                axios.get("http://127.0.0.1:5000/getApi")
                    .then((response) => (this.info = response.data))
                    .catch(function (error) {
                    console.log(error);
                });
            }, 
        });
        </script>
    </body>
</html>
```



```json
data = [
  { name: "LI_LI", age: 18 }, 
  { name: "WAN_MIN", age: 20 }, 
  { name: "QIN_XI", age: 20 }, 
];
```

![](https://cdn.hurra.ltd/img/20200725123717.png)


#### POST 请求

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <script src="https://cdn.staticfile.org/vue/2.4.2/vue.min.js"></script>
    <script src="https://cdn.staticfile.org/axios/0.18.0/axios.min.js"></script>
</head>

<body>
    <div id="app">
        <h1>POST请求获取数据</h1>
        输入用户名
        <input type="text" name="name" id="name" v-model="name">
        <br>
        <button @click="submitName">提交</button>
    </div>
    
    <script type="text/javascript">
        const data = {'name': document.getElementById('name').value}
        var vm = new Vue({
            el: '#app', 
            data() {
                return {
                    name: '', 
                    info: ''
                }
            }, 
            methods: {
                submitName() {
                axios
                    .post('http://127.0.0.1:5000/postApi', {'name': this.name})
                    .then(function (response) {
                        this.info = response.data
                        alert(JSON.stringify(this.info))})
                    .catch(function (error) {
                        console.log(error)
                    })
                }, 
            }
        })
    </script>
</body>

</html>
```

```py
@app.route('/postApi', methods=['POST'])
def post_api():
    data = json.loads(request.get_data())
    return json.dumps(data)
```

![](https://cdn.hurra.ltd/img/20200725151620.png)

![](https://cdn.hurra.ltd/img/20200725151641.png)