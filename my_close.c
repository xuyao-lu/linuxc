#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{
    int fd;
  /*  fd = open("1.c" , O_RDWR);

    if(fd == -1){
        perror("open file");
        exit(1);
    }


    fd = open("myhello",O_RDWR | O_CREAT,0777);
    if(fd == -1)
    {
        perror("open file");
        exit(1);
    }

    printf("fd = %d\n",fd);*/
    int ret = close(fd);
    printf("ret = %d\n",ret);
    if(ret == -1){
        perror("close file");
        exit(1);
    }
    return 0;
}

