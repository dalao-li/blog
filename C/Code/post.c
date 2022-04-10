/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-10 22:17:03
 */
#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// IP地址
#define IPSTR "61.147.124.120"
#define PORT 80

void post() {
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if (!socket_fd) {
        printf("创建网络连接失败,本线程即将终止---socket error!\n");
        return;
    }
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (!inet_pton(AF_INET,IPSTR,&server_addr.sin_addr)) {
        printf("创建网络连接失败,本线程即将终止--inet_pton error!\n");
        return;
    }
    if (connect(socket_fd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
        printf("连接到服务器失败,connect error!\n");
        return;
    }
    printf("与远端建立了连接\n");
    char str1[4096],str2[4096],buf[4096];
    memset(str2,0,4096);
    // 发送的数据
    strcat(str2,"qqCode=0123456789");
    char *str = (char *) malloc(128);
    sprintf(str,"%lu",strlen(str2));
    memset(str1,0,4096);
    // POST方法
    strcat(str1,"POST /webservices/qqOnlineWebService.asmx/qqCheckOnline HTTP/1.1\n");
    strcat(str1,"Host: www.webxml.com.cn\n");
    strcat(str1,"Content-Type: application/x-www-form-urlencoded\n");
    strcat(str1,"Content-Length: ");
    strcat(str1,str);
    strcat(str1,"\n\n");
    // str2的值为post的数据
    strcat(str1,str2);
    strcat(str1,"\r\n\r\n");
    printf("%s\n",str1);

    int ret = write(socket_fd,str1,strlen(str1));
    if (!ret) {
        printf("发送失败!错误代码是%d,错误信息是'%s'\n",errno,strerror(errno));
        return;
    }
    printf("消息发送成功,共发送了%d个字节!\n\n",ret);
    // 描述符集t_set1
    fd_set t_set1;
    FD_ZERO(&t_set1);
    FD_SET(socket_fd,&t_set1);
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    while (1) {
        sleep(2);
        printf("--------------->1--------------->2\n");
        if (select(socket_fd + 1,&t_set1,NULL,NULL,&tv) == -1) {
            close(socket_fd);
            printf("在读取数据报文时SELECT检测到异常,该异常导致线程终止！\n");
            return;
        }
        // 判断描述符socket_fd是否在给定的描述符集t_set1中,通常配合select函数使用
        if (FD_ISSET(socket_fd,&t_set1)) {
            memset(buf,0,4096);
            if (read(socket_fd,buf,4095) == 0) {
                close(socket_fd);
                printf("读取数据报文时发现远端关闭,该线程终止!\n");
                return;
            }
            printf("%s\n",buf);
        }
    }
}

int main(void) {
    post();
    return 0;
}