/*
 * @Description:
 * @Version: 1.0
 * @Author:
 * @Email:
 * @Date: 2023-11-23 21:39:07
 * @LastEditors:
 * @LastEditTime: 2023-11-23 21:39:15
 */
#include <iostream>
#include <windows.h>

int main()
{
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};

    // 打开串口
    hSerial = CreateFile("COM1", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE)
    {
        std::cerr << "无法打开串口" << std::endl;
        return 1;
    }

    // 设置串口参数
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams))
    {
        std::cerr << "获取串口状态失败" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }
    dcbSerialParams.BaudRate = CBR_9600;   // 波特率
    dcbSerialParams.ByteSize = 8;          // 数据位
    dcbSerialParams.StopBits = ONESTOPBIT; // 停止位
    dcbSerialParams.Parity = NOPARITY;     // 校验位
    if (!SetCommState(hSerial, &dcbSerialParams))
    {
        std::cerr << "设置串口状态失败" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    // 设置超时
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(hSerial, &timeouts))
    {
        std::cerr << "设置超时失败" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    // 向串口发送数据
    DWORD bytesWritten;
    char data[] = "Hello, Serial!";
    if (!WriteFile(hSerial, data, sizeof(data), &bytesWritten, NULL))
    {
        std::cerr << "写入数据失败" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }

    // 从串口读取数据
    DWORD bytesRead;
    char buffer[100];
    if (!ReadFile(hSerial, buffer, sizeof(buffer), &bytesRead, NULL))
    {
        std::cerr << "读取数据失败" << std::endl;
        CloseHandle(hSerial);
        return 1;
    }
    std::cout << "接收到的数据：" << buffer << std::endl;

    // 关闭串口
    CloseHandle(hSerial);

    return 0;
}
