<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-07 00:19:50
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 23:04:43
-->

## 一、安装Hexo


### 1.1 修改npm源

```sh
sudo npm install gitbook-cli -g --registry=http://registry.npm.taobao.org 
```


### 1.2 安装

```sh
# 新建目录
sudo npm install -g hexo-cli

# 初始化
hexo init

# 安装 hexo 依赖包
sudo npm install

# 阅读时间统计功能
sudo npm install hexo-wordcount --save

# 字数统计功能
sudo npm install hexo-wordcount --save
```
![](https://cdn.hurra.ltd/img/20211207224409.png)


### 1.3 启动

- 生成静态网站

```sh
hexo g
```

- 启动服务器

```sh
hexo s
```

```sh
hexo g && hexo s
```
![](https://cdn.hurra.ltd/img/20211207231056.png)

![](https://cdn.hurra.ltd/img/20211207231203.png)


### 1.4 修改主题

```sh
# 根目录下执行
git clone https://github.com/liuyib/hexo-theme-stun.git themes/stun

# 安装依赖 hexo-renderer-pug
sudo npm install --save hexo-renderer-pug
```


### 1.5 建立文章

```sh
hexo new [layout] <title>
```

| 参数 | 描述                                                 |
| ---- | ---------------------------------------------------- |
| -p   | --path	自定义新文章的路径                            |
| -r   | --replace	如果存在同名文章，将其替换                 |
| -s   | --slug	文章的 Slug，作为新文章的文件名和发布后的 URL |

```sh
hexo new page --path about/hello "Hello World"
```
创建 source/about/hello.md 文件，同时 Front Matter 中的 title 为 "Hello World"

![](https://cdn.hurra.ltd/img/20211207234206.png)


### 1.6 远程推送

- _config.yml修改
  
```xml
deploy:
  type: git
  repo: git@github.com:xxx/xxx.github.io.git
  branch: main
```

- 推送插件

```sh
sudo npm install hexo-deployer-git --save
```

- d 表示部署在远端

```sh
hexo g && hexo d
```

## 二、问题

### 2.1 Math渲染

- 更换Hexo的markdown渲染引擎

```sh
npm uninstall hexo-renderer-marked --save

npm install hexo-renderer-kramed --save
```

- 修改node_modules\kramed\lib\rules\inline.js文件

```sh
sudo vim node_modules\kramed\lib\rules\inline.js
```

```js
// escape: /^\\([\\`*{}\[\]()#$+\-.!_>])/,
escape: /^\\([`*\[\]()#$+\-.!_>])/,
...
//  em: /^\b_((?:__|[\s\S])+?)_\b|^\*((?:\*\*|[\s\S])+?)\*(?!\*)/,
  em: /^\*((?:\*\*|[\s\S])+?)\*(?!\*)/,
```

- 在主题中开启mathjax开关

主题的_config.yml

```yml
math:
  enable: true
  per_page: true
  engine: mathjax
```

- 在文章的Front-matter里打开mathjax开关

```m
---
...
mathjax: true
--
```

### 2.2 综合问题

- hexo not found 

```py
echo "export PATH=$PATH:/opt/node-v16.13.1-linux-x64/lib/node_modules/hexo-cli/bin" >> ~/.bashrc

source ~/.bashrc
```

- 1

![](https://cdn.hurra.ltd/img/20211207230441.png)


- 将nodejs升级到高于12.0.0的版本

- _config.xml中的 highlight->enable的值修改为false

![](https://cdn.hurra.ltd/img/20211207230948.png)

- 2

![](https://cdn.hurra.ltd/img/20211208001031.png)

```sh
sudo cnpm install --save hexo-renderer-jade hexo-generator-feed hexo-generator-sitemap hexo-browsersync hexo-generator-archive