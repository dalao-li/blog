<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-12-07 14:13:56
 * @LastEditors: 
 * @LastEditTime: 2023-12-07 14:14:09
-->

# Django跨域

```py
pip install django-cors-headers
```

## 修改settings.py

```py
INSTALLED_APPS = [
    ...
    'corsheaders',
    ...
]

...

MIDDLEWARE = [
    ...
    'corsheaders.middleware.CorsMiddleware',
    'django.middleware.common.CommonMiddleware',
    ...
]
