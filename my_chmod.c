#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char **argv)
{
    int mode;
    int mode_u;
    int mode_g;
    int mode_o;
    char *file;
    
    //检查参数个数对合法性,即文件执行/数据/文件名
    if(argc<3){

        printf("%s <mode num> <target file>\n",argv[0]);
        exit(0);
    }

    //获取命令行参数
    mode = atoi(argv[1]);//将输入的数字转换为整形数

    if(mode>777||mode<0){
        printf("mode num error!\n");
        exit(0);
    }
    //计算各个组的文件权限
    mode_u = mode/100;
    mode_g = (mode-(mode_u*100))/10;
    mode_o = mode-(mode_u*100) - (mode_g*10);
    mode = (mode_u*8*8)+(mode_g*8)+mode_o;
    file = argv[2];//将文件名写入

    if(chmod(file,mode)==-1){
        perror("chmod error");
        exit(1);
    }


    return 0;
}

