#include<stdio.h>
#include<string.h>
int main()
{
	char d[20]="hello ";
	char *s="world";
	strcat(d,s);
	puts(d);
	
	strncat(d,s,sizeof(s));
	printf("\n");
	puts(d);
}
