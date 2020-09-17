#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
int fd = open("hello_dup2.txt",O_RDWR|O_APPEND|O_CREAT,0666);

    if(fd<0){
        printf("open error!\n");
        exit(1);
    }
    if(write(fd,"hello fd\n",9)!=9){
        printf("write dup2 error\n");
    }

    int newfd = dup2(fd,STDOUT_FILENO);

    if(newfd!=STDOUT_FILENO){

        printf("error dup2!\n");
        exit(1);
    }

    close(fd);


    char c_buf[1024];
    int n=0;
    while((n=read(STDIN_FILENO,c_buf,1024))!=0){
        n = read(STDIN_FILENO,c_buf + n ,sizeof(c_buf) - 1 - n);

        if(n<0){

            printf("read error!\n");
            exit(1);
        }

        printf("%s",c_buf);
        fflush(stdout);
        sleep(1);
    }

    close(newfd);

    return 0;
}
