#include <stdio.h>

__int64 funA(int a,int b)
{
    __int64 sa = 1,sb = 1;
    int i;
    for(i = 1;i<=a;i++)
    sa*=i;
    for(i = 1;i<=b;i++)
    sb*=i;
    return sa/sb;
}

int funB(int a)
{
    int s = 1,i;
    for(i = 1;i<=a;i++)
    s*=i;
    return s;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        char c[2];
        scanf("%s%d%d",c,&n,&m);
        if(c[0] == 'A')
        printf("%I64d\n",funA(n,n-m));
        else
        printf("%d\n",funA(n,n-m)/funB(m));
    }
    return 0;
}
