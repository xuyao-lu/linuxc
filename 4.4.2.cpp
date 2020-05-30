#include<stdio.h>
#include<string.h>

int main()
{
	char dest[20];
	char *src = "world"; 
	
	strcpy(dest,src);
	strncpy(dest,src,sizeof(src) );
	
	puts(dest);
	puts(dest);
 } 
