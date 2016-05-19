#include"stdio.h"
typedef __int64 int64;
int64 fun(int64 a,int64 b,int64 c)
{    
    if(a+b==c||a+c==b||b+c==a)return 1;
    if(a*b==c||a*c==b||b*c==a)return 1;
    if(a!=0)
    {
        if(c/a==b&&c%a==0||b/a==c&&b%a==0)return 1;
        if(c%a==b||b%a==c)return 1;
    }
    if(b!=0)
    {
        if(c/b==a&&c%b==0||a/b==c&&a%b==0)return 1;
        if(c%b==a||a%b==c)return 1;
    }
    if(c!=0)
    {
        if(a/c==b&&a%c==0||b/c==a&&b%c==0)return 1;
        if(a%c==b||b%c==a)return 1;
    }
    return 0;
}
int main()
{
    int64 a,b,c;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=-1)
    {
        if(fun(a,b,c)==1)printf("oh,lucky!\n");
        else printf("what a pity!\n");
    }
    return 0;
}        