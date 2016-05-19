#include<iostream>
#include<cmath>
using namespace std;
__int64 modular(__int64 b,__int64 n,__int64 m)//求同余幕
{
    __int64 x=1,power=b%m;
    __int64 temp=n;
    int a[65];
    int k=0,i;
    while(temp>0)
    {
        a[k++]=temp%2;
        temp/=2;
    }
    for(i=0;i<k;i++)
    {
        //printf("%d\n",a[i]);
        if(a[i]==1)
            x=(x*power)%m;
        power=(power*power)%m;
    }
    return x;
}
__int64 extgcd(__int64 a ,__int64 b,__int64 &x,__int64 &y)//扩展欧几里算法
{
    if(b==0)
    {
        x=1;y=0;return a;
    }
    __int64 d=extgcd(b,a%b,x,y);
    __int64 t=x; x=y; y=t-a/b*y;
    return d;
}
__int64 modeq(__int64 a,__int64 b,__int64 n)//求线性方程
{
    __int64 e,i,d,x,y;
    d=extgcd(a,n,x,y);
    //printf("%I64d %I64d %I64d %I64d\n",b,d,x,y);
    if(b%d>0)printf("No answer!\n");
    else
    {
        e=(x*(b/d))%n;
        i=0;
        while(((e+i*(n/d))%n)<0)
        {
            i++;
        }
        return (e+i*(n/d))%n;
    }
    return -1;
}
int main()
{
    __int64 p,q,e,l,d,n,m,c;

    //m=modular(2,644,645);
    //printf("%I64d\n",m);
    while(scanf("%I64d %I64d %I64d %I64d",&p,&q,&e,&l)!=EOF)
    {
        n=p*q;
        d=modeq(e,1,(p-1)*(q-1));
        //printf("%I64d\n",d);
        for(int i=0;i<l;i++)
        {
            scanf("%I64d",&c);
            m=modular(c,d,n);
            printf(i<l-1?"%c":"%c\n",m);
        }
    }
    return 0;
}