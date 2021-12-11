<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-01 23:08:47
-->
## 安装 OpenCV

```py
pip install opencv-python
```

## 修改 numpy 版本

$Windows$ 只能安装 numpy 1.19.3，若直接使用 pip install 安装的是 1.19.4 版本，因此在安装时需要指定版本

```py
pip uninstall numpy

pip install numpy==1.19.3
```