#include <stdio.h>
#include <string.h>

int main()
{
    struct student
    {
        int number;
        char name[20];
        char sex;
        int age;
        char addr[30];
    };

    struct student s[3] = {{10000,"zhang",'m',21,"shanghai"},
        {10001,"li",'f',20,"beijing"}};
    s[2].number = 10002;
    s[2].sex = 'm';
    s[2].age = 22;
    strcpy(s[2].name,"liu");
    strcpy(s[2].addr,"guangdong");

    printf("%d,%s,%c,%d,%s\n",s[0].number,s[0].name,s[0].sex,s[0].age,s[0].addr);
    printf("%d,%s,%c,%d,%s\n",s[1].number,s[1].name,s[1].sex,s[1].age,s[1].addr);
    printf("%d,%s,%c,%d,%s\n",s[2].number,s[2].name,s[2].sex,s[2].age,s[2].addr);

    return 0;
}

