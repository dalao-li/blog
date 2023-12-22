project(Hello)

set(SRC_LIST API.cpp)

# 生成动态库
add_library(API SHARED ${SRC_LIST})