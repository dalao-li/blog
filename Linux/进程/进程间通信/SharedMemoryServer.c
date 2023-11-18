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

    printf("copy data to shared memory\n");
    bzero(shmadd, 1024);
    strcpy(shmadd, "Hello World\n");

    return 0;
}