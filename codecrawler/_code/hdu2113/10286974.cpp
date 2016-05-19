#include<stdio.h>
int main()
{
    __int64 a;
    int p=1;
    while(scanf("%I64d",&a)!=EOF)
    {
        int s=0;
        while(a)
        {
            int d=a%10;
            if(d%2==0) s+=d;
            a/=10;
        }
        if(p) p=0;
        else puts("");
        printf("%d\n",s);
    }
    return 0;
}