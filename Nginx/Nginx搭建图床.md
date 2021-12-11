<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-05 01:12:34
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-06 18:15:51
-->
编辑/etc/nginx/nginx.conf

```sh
server {
    location ~ .*\.(gif|jpg|jpeg|png|jfif)$ { 
        root         图片存放路径
        autoindex    on
    location / {
        ...
    }
}
```

