/*
 * @Description: Windows下操作串口
 * @Version: 1.0
 * @Author:
 * @Email:
 * @Date: 2023-11-23 21:39:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-06 16:27:13
 */
#include <iostream>
#include <windows.h>

int main()
{
    // 打开串口
    // --------------------------------------------------------------------------------------------------------
    HANDLE handle;
    handle = CreateFile("COM1", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (handle == INVALID_HANDLE_VALUE)
    {
        std::cerr << "无法打开串口" << std::endl;
        return 1;
    }
    // --------------------------------------------------------------------------------------------------------

    // 设置串口参数
    // --------------------------------------------------------------------------------------------------------
    DCB comParam = {0};
    comParam.DCBlength = sizeof(comParam);
    if (!GetCommState(handle, &comParam))
    {
        std::cerr << "获取串口状态失败" << std::endl;
        CloseHandle(handle);
        return 1;
    }
    // 波特率
    comParam.BaudRate = CBR_9600;
    // 数据位
    comParam.ByteSize = 8;
    // 停止位
    comParam.StopBits = ONESTOPBIT;
    // 校验位
    comParam.Parity = NOPARITY;
    if (!SetCommState(handle, &comParam))
    {
        std::cerr << "设置串口状态失败" << std::endl;
        CloseHandle(handle);
        return 1;
    }
    // --------------------------------------------------------------------------------------------------------

    // 设置超时
    // --------------------------------------------------------------------------------------------------------
    COMMTIMEOUTS comTime = {0};
    comTime.ReadIntervalTimeout = 50;
    comTime.ReadTotalTimeoutConstant = 50;
    comTime.ReadTotalTimeoutMultiplier = 10;
    comTime.WriteTotalTimeoutConstant = 50;
    comTime.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(handle, &comTime))
    {
        std::cerr << "设置超时失败" << std::endl;
        CloseHandle(handle);
        return 1;
    }
    // --------------------------------------------------------------------------------------------------------

    // 向串口发送数据
    // --------------------------------------------------------------------------------------------------------
    DWORD bytesWritten;
    char data[] = "Hello, Serial!";
    if (!WriteFile(handle, data, sizeof(data), &bytesWritten, NULL))
    {
        std::cerr << "写入数据失败" << std::endl;
        CloseHandle(handle);
        return 1;
    }
    // --------------------------------------------------------------------------------------------------------

    // 从串口读取数据
    // --------------------------------------------------------------------------------------------------------
    DWORD bytesRead;
    char buffer[100];
    if (!ReadFile(handle, buffer, sizeof(buffer), &bytesRead, NULL))
    {
        std::cerr << "读取数据失败" << std::endl;
        CloseHandle(handle);
        return 1;
    }
    std::cout << "接收到的数据：" << buffer << std::endl;
    // --------------------------------------------------------------------------------------------------------

    // 关闭串口
    // --------------------------------------------------------------------------------------------------------
    CloseHandle(handle);
    // --------------------------------------------------------------------------------------------------------
    return 0;
}
