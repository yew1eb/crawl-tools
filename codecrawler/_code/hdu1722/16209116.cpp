#include"stdio.h"
int GCD(int a,int b)
{
    int t;
    if(a<b)    {t=a;a=b;b=t;}
    do
    {
        t=a%b;
        a=b;
        b=t;
    }
    while(t);
    return a;
}
int main()
{
    int p,q;
    while(scanf("%d%d",&p,&q)!=-1)
        printf("%d\n",p+q-GCD(p,q));
    return 0;
}