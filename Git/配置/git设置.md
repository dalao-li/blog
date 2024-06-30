<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-03-17 17:59:27
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-23 15:24:58
-->

# git设置

## 配置

```sh
# 配置用户名
git config --global user.name "用户名"

# 配置邮箱
git config --global user.email "邮箱"

# 配置编辑器
git config --global core.editor "code -w"

# 防止中文乱码
git config --global core.quotepath false
```

## 创建公钥

```sh
ssh-keygen -t rsa -C "邮箱"
```

公钥位置`.ssh/id_rsa.pub`

## .git优化

```sh
git gc --prune=now

git rev-list --objects --all | grep "$(git verify-pack -v .git/objects/pack/*.idx | sort -k 3 -n | tail -5 | awk '{print$1}')"
```
