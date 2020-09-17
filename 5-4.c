#include <stdio.h>

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

    struct student s[3] = {
        {10000,"zhang",'m',21,"shanghai"},
        {10001,"li",'f',20,"beijing"},
        {10002,"liu",'m',22,"guangdong"}
    };

    struct student *p;

    for(p=s;p<s+3;p++)
    {
        printf("%d,%s,%c,%d,%s\n",p->number,p->name,p->sex,p->age,p->addr);
    }

    return 0;
}

