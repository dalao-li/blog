/*
 * @Description:
 * @Version: 1.0
 * @Author:
 * @Email:
 * @Date: 2023-11-18 00:34:58
 * @LastEditors:
 * @LastEditTime: 2023-11-18 00:35:21
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void)
{
    key_t key = ftok("./", 0xFF);
    if (key == -1)
    {
        perror("ftok error");
    }

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if (shmid < 0)
    {
        perror("shmget error");
    }

    char *shmadd = shmat(shmid, NULL, 0);
    if (shmadd < 0)
    {
        perror("shmat error");
    }
    printf("data = [%s]\n", shmadd);

    int ret = shmdt(shmadd);
    if (ret < 0)
    {
        perror("shmdt error");
    }
    else
    {
        printf("deleted shared meomry\n");
    }

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}