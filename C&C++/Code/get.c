#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// 服务器IP地址
#define IP "182.92.241.193"
// 服务器端口
#define PORT 80

// 发送get请求函数
void get()
{
    // 创建套接字fd
    // AF_INET代表IPv4
    // SOCK_STREAM是有保障的(即能保证数据正确传送到对方)面向连接的SOCKET, 多用于资料(如文件)传送
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (!fd)
    {
        printf("创建网络连接失败, 本线程即将终止---socket error!\n");
        return;
    }
    // 处理网络通信地址的结构体sockaddr_in
    struct sockaddr_in address;
    // 初始化sockaddr_in结构体
    // bzero()函数: 将内存(字符串)前n个字节清零
    bzero(&address, sizeof(address));
    // 设置地址家族
    address.sin_family = AF_INET;
    // 设置端口
    // htons()作用是将端口号由主机字节序转换为网络字节序的整数值
    address.sin_port = htons(PORT);
    // inet_pton()将点分十进制的ip地址转化为用于网络传输的数值格式
    // AF_INET代表IPv4
    if (!inet_pton(AF_INET, IP, &address.sin_addr))
    {
        printf("创建网络连接失败, 本线程即将终止--inet_pton error!\n");
        return;
    }
    // 建立和HTTP服务器的TCP链接
    if (connect(fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("连接到服务器失败, connect error!\n");
        return;
    }

    printf("与远端建立了连接\n");
    char str1[4096], str2[4096], buf[4096];
    // 开始请求的拼接头部
    memset(str2, 0, 4096);
    // 输入要发送的数据
    strcat(str2, "0123456789abcd");
    char *str = (char *)malloc(128);
    sprintf(str, "%lu", strlen(str2));
    memset(str1, 0, 4096);
    // 使用的是GET方法, http 协议版本字段, 用是的http/1.1 版本
    strcat(str1, "GET /html/html_editors.html HTTP/1.1\n");
    // 定义了目标所在的主机
    strcat(str1, "Host: www.phpxuexi.net\n");
    // 表明请求的数据类型
    strcat(str1, "Content-Type: text/html\n");
    // 表明请求实体的长度
    strcat(str1, "Content-Length: ");
    strcat(str1, str);
    strcat(str1, "\n\n");
    strcat(str1, str2);
    strcat(str1, "\r\n\r\n");
    // 拼接头部结束
    printf("%s\n", str1);

    int ret = write(fd, str1, strlen(str1));
    if (!ret)
    {
        printf("发送失败!错误代码是%d, 错误信息是'%s'\n", errno, strerror(errno));
        return;
    }
    printf("消息发送成功, 共发送了%d个字节!\n\n", ret);
    // 文件描述符
    fd_set t_set1;
    // 将指定的文件描述符集清空
    FD_ZERO(&t_set1);
    // 用于在文件描述符集合中增加一个新的文件描述符
    FD_SET(fd, &t_set1);
    // 设置时间周期的结构体
    struct timeval tv;

    while (1)
    {
        // 休眠两秒
        sleep(2);
        // 设置秒
        tv.tv_sec = 0;
        // 设置毫秒
        tv.tv_usec = 0;
        printf("--------------->1");
        // select()用来等待文件描述词状态的改变
        int h = select(fd + 1, &t_set1, NULL, NULL, &tv);
        printf("--------------->2");
        // 若小于0说明线程被终止
        if (h < 0)
        {
            close(fd);
            printf("在读取数据报文时SELECT检测到异常, 该异常导致线程终止!\n");
            return;
        }
        // 清空buf数组
        memset(buf, 0, 4096);
        // 若从远端读取不到数据则终止
        if (read(fd, buf, 4095) == 0)
        {
            close(fd);
            printf("读取数据报文时发现远端关闭, 该线程终止!\n");
            return;
        }
        printf("%s\n", buf);
    }
}

int main(void)
{
    get();
    return 0;
}
