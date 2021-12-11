<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-24 15:25:28
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-07 16:02:32
-->

## Readis操作

```sh
# 建立键
SET key redis

# 删除键
DEL key

# 检查给定key是否存在
EXISTS key

# 以秒为给定key设置过期时间
EXPIRE key seconds

# 以秒返回给定$key$的剩余生存时间
TTL key
```

## 安全操作

```sh
# 设置密码
CONFIG set requirepass "密码"

# 查看密码
CONFIG get requirepass
```

