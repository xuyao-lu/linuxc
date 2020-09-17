#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int fd;

    
    //if ((fd = open("example_62.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR))==-1){
       if((fd=creat("example_62.c",S_IWUSR))==-1){
        //perror("open");
       printf("open:%s   with errno:%d\n",strerror(errno),errno);//strerror将错误符号转换为字符描述
        exit(1);
    }else{
        printf("create file success\n");
    }
    close(fd);
        return 0;
}

