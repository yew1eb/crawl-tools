#include<stdio.h>
int main()
{
    int a,b,c,l,r;
    int n;
    int i;
    int ma,ni,Max,Min;
    scanf("%d",&n);
    while(n--)
    {
        Max=-10000000;
        Min=10000000;
        scanf("%d%d%d%d%d",&a,&b,&c,&l,&r);
        for(i=l;i<=r;i++)
        {
            ma=a*i*i+b*i+c;
            if(ma>=Max)
                Max=ma;
             if(ma<=Min)
                Min=ma;
        }
        printf("%d %d\n",Max,Min);
    }
    return 0;
}
