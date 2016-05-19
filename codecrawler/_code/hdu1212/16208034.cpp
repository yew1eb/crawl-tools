#include <stdio.h>
#include <string.h>

int mod(char *n1,int n2)
{
    int tmp=0;
    int len=strlen(n1);
    for(int i=0; i<len; i++)
    {
        tmp=tmp*10+n1[i]-'0';
        tmp=tmp%n2;
    }
    return tmp;
}

int main()
{
    char s[100000];
    int n;
    while(~scanf("%s%d%*c",s,&n))
    {
        printf("%d\n",mod(s,n));
    }

    return 0;
}
