#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[1000];
int main()
{
    int n;
    char *p,*_p;
    scanf("%d",&n);
    getchar();
    while(n-->0)
    {
        gets(s);
        p=s;
        while(*p!='\0')
        {
            if(*p=='('&&*(p+1)==')'||(*p=='['&&*(p+1)==']'))
            {
                *p='\0';
                _p=p+2;
                p=s;
                strcat(p,_p);
            }
            else
                p++;
        }
        if(s[0]=='\0')
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}