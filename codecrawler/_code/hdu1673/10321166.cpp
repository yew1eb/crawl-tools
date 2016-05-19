#include<stdio.h>
int main()
{
    int t,n,i,max,min,m;
    scanf("%d",&t);
    while(t--)
    {
        min=200;max=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            if(m<min)
                min=m;
            if(m>max)
                max=m;
        }
        printf("%d\n",(max-min)*2);
    }
    return 0;
}