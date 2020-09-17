#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//自定义错误处理函数
int my_err(const char *err_string,int line)
{
    fprintf(stderr,"line:%d ",line);
    perror(err_string);
    exit(1);
    return 0;
}

int main()
{ 
    int ret;
    int access_mode;
    int fd;

    if((fd=open("example_64.c",O_CREAT|O_TRUNC|O_RDWR,S_IRWXU))==-1)
    {
        my_err("open",__LINE__);
    }

    //设置文件打开方式
    if((ret=fcntl(fd,F_SETFL,O_APPEND))<0)
    {
        my_err("fcntl",__LINE__);
    }

    //获取文件打开方式
    if((ret=fcntl(fd,F_GETFL,0))<0)
    {
        my_err("fcntl",__LINE__);
    }
    access_mode=ret&O_ACCMODE;
    //O_ACCMODE取得文件打开方式的掩码，值为3。做与运算是为了取得ret的最后两位的值

    if(access_mode==O_RDONLY)
    {
        printf("example_3 access mode:read only");
    }
    else if(access_mode==O_WRONLY)
    {
        printf("example_3 access mode:write only");
    }
    else if(access_mode==O_RDWR)
    {
        printf("example_3 access mode:read*write");
    }

    if(ret&O_APPEND)
    {
        printf(",append");
    }
    if(ret&O_NONBLOCK)
    {
        printf(",nonblock");
    }
    if(ret&O_SYNC)
    {
        printf(",sync");
    }
    printf("\n");

    return 0;
}
