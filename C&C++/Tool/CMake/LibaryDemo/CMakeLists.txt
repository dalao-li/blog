project(Hello)

set(SRC_LIST API.cpp)

add_library(API SHARED ${SRC_LIST})