#include<stdio.h>
#define N 100
int a,b;
int get(char num[])
{
    int i = -1;
    if (!strcmp (num, "zero"))
		i = 0 ;
	else if (!strcmp (num, "one"))
		i = 1 ;
	else if (!strcmp (num, "two"))
		i = 2 ;
	else if (!strcmp (num, "three"))
		i = 3 ;
	else if (!strcmp (num, "four"))
		i = 4 ;
	else if (!strcmp (num, "five"))
		i = 5 ;
	else if (!strcmp (num, "six"))
		i = 6 ;
	else if (!strcmp (num, "seven"))
		i = 7 ;
	else if (!strcmp (num, "eight"))
		i = 8 ;
	else if (!strcmp (num, "nine"))
		i = 9 ;
	return i ;
}
void ch(char *s)
{
    int i,j;
    char num[N];
    a=b=0;
    i=0;
    while(1)
    {
        while(*(s+i)==' ')
            i++;
        sscanf(s+i,"%s",num);
        i += strlen(num);
        if((j=get(num))==-1)
            break;
        a=a*10+j;
    }
    while(1)
    {
        while(*(s+i)==' ')
            i++;
        sscanf(s+i,"%s",num);
        i += strlen(num);
        if((j=get(num))==-1)
            break;
        b=b*10+j;
    }
}
int main()
{
    char s[N];
    while(gets(s))
    {
        ch(s);
        if(a==0&&b==0)
            break;
        printf("%d\n",a+b);
    }
}