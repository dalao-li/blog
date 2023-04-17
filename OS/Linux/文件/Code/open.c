/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-07-03 18:42:03
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 18:42:12
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
    char block[1024];
    int in;
    int out;
    int nread;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    while ((nread = read(in, block, sizeof(block))) > 0)
    {
        write(out, block, nread);
    }
    return 0;
}