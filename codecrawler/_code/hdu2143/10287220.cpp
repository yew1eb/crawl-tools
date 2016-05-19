#include<iostream>
#include<cstdio>
using namespace std;
__int64 a,b,c;
int fuhe()
{
    if(a*b==c||a*c==b||b*c==a||a+b==c||a+c==b||b+c==a)return 1;
    if(a!=0)
        if(b%a==c||c%a==b)
            return 1;
    if(b!=0)
        if(a%b==c||c%b==a)
            return 1;
    if(c!=0)
        if(a%c==b||b%c==a)
            return 1;
    return 0;
}
int main()
{
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
    {
        if(fuhe())
            printf("oh,lucky!\n");
        else
            printf("what a pity!\n");
    }
    return 0;
}