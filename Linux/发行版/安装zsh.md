<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao_li
 * @Email: dalao_li@163.com
 * @Date: 2023-04-29 00:38:12
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-29 01:05:56
-->

# zsh

## 安装

```sh
sh -c "$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"
```

## 插件

- 安装

```sh
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
```

- 修改配置文件 `~/.zshrc`

```sh
# 末尾追加
plugins=(git z extract zsh-syntax-highlighting zsh-autosuggestions)
source $ZSH_CUSTOM/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source $ZSH_CUSTOM/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
```

- 配置生效

```sh
source ~/.zshrc
```

## 设置默认shell

```sh
sudo chsh -s $(which zsh)
```

注销当前用户重新登录
