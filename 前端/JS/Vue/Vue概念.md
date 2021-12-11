<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-04-25 17:42:44
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-06 20:40:47
-->

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

this.axios.post("http://127.0.0.1:5000/login"， {
    name: this.param.username，
    pwd: this.param.password，
  }).then((response) => {
    const r = response.data;
    console.log(r.result);
});
```