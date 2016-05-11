#include<stdio.h>
#include<string.h>
void main()
{
	char a[20];
	char I[]="I";
	char L[]="Love";
	char* Y="You";
	char* E=" ";
	strcpy(a,I);
	strcat(a,E);
	strcat(a,L);
	strcat(a,E);
	strcat(a,Y);
	printf("%s\n",a);
}
