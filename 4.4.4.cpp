#include<stdio.h>
#include<string.h>
int main()
{
	char *s1 = "compare";
	char *s2 = "computer";
	
	if(strncmp(s1,s2,sizeof(s2)) == 0)
		printf("compare = computer");
	else if(strncmp(s1,s2,sizeof(s2))>0)
		printf("compare > computer");
	else
		printf("compare < computer");
}
