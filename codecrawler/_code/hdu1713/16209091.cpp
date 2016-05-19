#include"stdio.h"
#include"string.h"
__int64 GCD(__int64 x,__int64 y)
{
    __int64 a,b,t;
    a=x>y?x:y;
    b=x>y?y:x;
    do
    {
        t=a%b;
        a=b;
        b=t;
    }while(t);
    return a;
}
int main()
{
    int T;
    __int64 n1,t1,n2,t2;
    __int64 a,b,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d/%I64d%I64d/%I64d",&t1,&n1,&t2,&n2);

        while(t=GCD(n1,t1),t!=1)
        {
            n1/=t;
            t1/=t;
        }
        while(t=GCD(n2,t2),t!=1)
        {
            n2/=t;
            t2/=t;
        }

        a=t1*t2/GCD(t1,t2);
        b=GCD(n1,n2);
        while(t=GCD(a,b),t!=1)
        {
            a/=t;
            b/=t;
        }
        if(b==1)    printf("%I64d\n",a);
        else        printf("%I64d/%I64d\n",a,b);
    }
    return 0;
}