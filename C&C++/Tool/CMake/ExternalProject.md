<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-12-12 23:58:17
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 16:06:37
-->

# ExternalProject

- 创建名为gflag-2.2.2.cmake的文件

在项目中创建名为Cmake的文件夹下创建名为gflag-2.2.2.cmake的文件

```js
include(ExternalProject)

set(GFLAG_ROOT          ${CMAKE_BINARY_DIR}/thirdparty/gflag-2.2.2)
set(GFLAG_LIB_DIR       ${GFLAG_ROOT}/lib)
set(GFLAG_INCLUDE_DIR   ${GFLAG_ROOT}/include)
 
set(GFLAG_URL           https://github.com/gflags/gflags/archive/v2.2.2.zip)
set(GFLAG_CONFIGURE     cd ${GFLAG_ROOT}/src/gflag-2.2.2 && cmake -D CMAKE_INSTALL_PREFIX=${GFLAG_ROOT} .)
set(GFLAG_MAKE          cd ${GFLAG_ROOT}/src/gflag-2.2.2 && make)
set(GFLAG_INSTALL       cd ${GFLAG_ROOT}/src/gflag-2.2.2 && make install)

ExternalProject_Add(gflag-2.2.2
    URL                   ${GFLAG_URL}
    DOWNLOAD_NAME         gflag-2.2.2.zip
    PREFIX                ${GFLAG_ROOT}
    CONFIGURE_COMMAND     ${GFLAG_CONFIGURE}
    BUILD_COMMAND         ${GFLAG_MAKE}
    INSTALL_COMMAND       ${GFLAG_INSTALL}
)
```

- 在项目根目录下的CMakeLists.txt中使用include调用这个cmake

include(cmake/gflag-2.2.2.cmake)
include(cmake/hwloc-1.11.cmake)
include(cmake/protobuf-2.6.1.cmake)
include(cmake/protobuf-2.6.1-compile.cmake)

## 参考

[CMake学习笔记05--ExternalProject_Add模块](https://blog.csdn.net/zym326975/article/details/106118063)