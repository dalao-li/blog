<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-17 17:59:27
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-07 16:51:54
-->

## Git 命令流程

![](https://cdn.hurra.ltd/img/20200720231600.png)


## 设置信息

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

## 建立公钥

```sh
# 这里可以设置不同公钥名来表示不同公钥
ssh-keygen -t rsa -C "邮箱"
```

公钥位置`.ssh/id_rsa.pub`

