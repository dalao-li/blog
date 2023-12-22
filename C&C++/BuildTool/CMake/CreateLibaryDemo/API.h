/*
 * @Description:
 * @Version: 1.0
 * @Author:
 * @Email:
 * @Date: 2023-12-03 00:22:13
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-03 00:23:30
 */

#include <iostream>

#define DLL_EXPORT extern "C" __declspec(dllexport)

DLL_EXPORT int add(int x, int y);

DLL_EXPORT void hello();