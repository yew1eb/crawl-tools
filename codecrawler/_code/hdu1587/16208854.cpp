#include"stdio.h"
int main()
{
    int ans;
    int m,n;
    int x,min;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        min=111111111;
        while(n--)
        {
            scanf("%d",&x);
            if(x<min)    min=x;
        }


        ans=m/min;


        printf("%d\n",ans);
    }
    return 0;
}