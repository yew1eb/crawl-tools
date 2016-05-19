#include<stdio.h>
#include<string.h>
#define MAX 100
char str[MAX];
int func()
{
    int i,len=strlen(str);
    int ans=0;
    for(i=0;i<len;i++)
        if(str[i]<0) ans++;
    return ans/2;
}
int main()
{
    int T;
    scanf("%d%c",&T);
    while(T--)
    {
        memset(str,0,sizeof(str));
        gets(str);
        printf("%d\n",func());
    }
    return 0;
}