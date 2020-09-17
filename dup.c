#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){

    int fd = open("hello.txt",O_RDWR|O_CREAT|O_APPEND,0666);

    if(fd<0){
        printf("open error!\n");
        exit(1);
    }

    if (write(fd,"hello file\n",12)!=12){
        printf("wite fd error\n");
    }

    int newfd = dup(fd);
    if(newfd<0){
        printf("dup error!\n");
        exit(1);
    
    }

    printf("newfd = %d \t fd = %d\n",newfd,fd);
    close(fd);

    char c_buffer[100];
    int n=0;
    while((n = read(STDIN_FILENO,c_buffer , 1000))!=0){
        if (write(newfd,c_buffer,n)!=n){
            printf("write dup fd error!\n");
            return 0;
        }
    }
    return 0;
    

}
