#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Mod 1000000007
long long s[100100];
void init()
{
    int i;
    for(i=0;i<100;i++)
        s[i]=1;
    for(i=100;i<100100;i++)
    {
        if(i<314)
            s[i]=s[i-100]%Mod;
        else
            s[i]=(s[i-100]+s[i-314])%Mod;
    }
}
int main()
{
    int cas,n,i,len;
    char ch[20];
    init();
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s",ch);
        n=0;
        i=0;
        if(ch[0]=='-')
        {
            printf("0\n");
            continue;
        }
        len=strlen(ch);
        while(ch[i]!='.'&&i<len)
            n=n*10+ch[i++]-'0';
        if(i+1<len)
            n=n*10+ch[i+1]-'0';
        else
            n=n*10;
        if(i+2<len)
            n=n*10+ch[i+2]-'0';
        else
            n=n*10;
        printf("%lld\n",s[n]);
    }
    return 0;
}
