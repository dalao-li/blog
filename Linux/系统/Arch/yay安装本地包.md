<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-17 01:47:56
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-07 18:47:58
-->


## yay 安装本地包

- 下载配置文件

`yay -G 包名`

- 修改PKGBUILD

修改PKGBUILD中的source为本地地址，此处需为http地址(可用`python -m http.server`)

原内容

```sh
source=("microsoft-edge-stable_${pkgver}-${pkgrel}_amd64.deb::https://packages.microsoft.com/repos/edge/pool/main/m/microsoft-edge-stable/microsoft-edge-stable_${pkgver}-${pkgrel}_amd64.deb")
```

替换为其他URL

```sh
source=("microsoft-edge-stable_${pkgver}-${pkgrel}_amd64.deb::http://localhost:8000/microsoft-edge-stable_96.0.1054.62-1_amd64.deb")
```

- 修改sha256sums

修改sha256sums与本地文件或网络文件一致

- 编译

```sh
makepkg
```

- 安装

生成xxx.pkg.tar.xz

`sudo pacman -U xxx.pkg.tar.xz`