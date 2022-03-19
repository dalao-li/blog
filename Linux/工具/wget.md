<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-03 00:55:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-19 21:15:21
-->

## wget

- 下载到指定目录

```sh
# 会自动创建路径
wget -P 路径 URL
```

- 下载到指定目录指定文件名

```sh
# 若路径未创建会报错
wget URL -O 路径/文件名
```

- 设置代理

```sh
wget -e http_proxy=127.0.0.1:7890 google.com  
```