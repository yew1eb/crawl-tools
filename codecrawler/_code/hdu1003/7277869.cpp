#include<stdio.h>
#define INF 9999999
int main()
{
    int i, b, n, m;
    int st, ed;
    int max;
    int sum ,x;
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&m);
        sum=0;max=-INF;
        for(i=b=1;i<=m;i++)
        {
            scanf("%d",&x);
            sum+=x;
            if(sum>max)
            {
                max=sum;
                st=b;
                ed=i;
            }
            if(sum<0)
            {
                sum=0;
                b=i+1;
            }
        }
        if(j!=1)printf("\n");
        printf("Case %d:\n%d %d %d\n",j,max,st,ed);
    }
    
    return 0;
}