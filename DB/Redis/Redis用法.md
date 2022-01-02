<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-24 15:25:28
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-02 20:59:31
-->

## Readis操作

- 建立键
  
```sh
SET key redis
```

- 删除键
  
```sh
DEL key
```

- 检查给定key是否存在

```sh
EXISTS key
```

- 以秒为给定key设置过期时间

```sh
EXPIRE key seconds
```

- 以秒返回给定key的剩余生存时间
```sh
TTL key
```

## 安全操作

- 设置密码

```sh
CONFIG set requirepass "密码"
```

- 查看密码
```sh
CONFIG get requirepass
```

