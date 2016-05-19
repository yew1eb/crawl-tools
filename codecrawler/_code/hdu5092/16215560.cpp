#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int min1(int x,int y)
{
    if(x<y)
        return x;
    return y;
}
int min2(int x,int y,int z)
{
    int min;
    min=min1(x,y);
    min=min1(min,z);
    return min;
}
int main()
{
    int a[105][105],i,j,n,m,T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d %d",&m,&n);
        memset(a,0,sizeof(a));
        for(i=0;i<=m;i++)
            a[i][0]=a[i][n+1]=0x7ffffff;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        }
        for(i=m;i>=1;i--)
        {
            for(j=1;j<=n;j++)
            {
                if(j==1)
                    a[i][j]+=min1(a[i+1][j],a[i+1][j+1]);
                else if(j==n)
                    a[i][j]+=min1(a[i+1][j],a[i+1][j-1]);
                else
                    a[i][j]+=min2(a[i+1][j],a[i+1][j+1],a[i+1][j-1]);
            }
        }
        printf("Case %d\n",cas);
        int x,min=0x7fffffff,y;
        for(i=1;i<n;i++)
        {
            if(min>=a[1][i])
            {
                min=a[1][i];
                x=i;
            }
        }
        printf("%d",x);
        for(i=2;i<=m;i++)
        {
            min=0x7ffffff;
            for(j=x-1;j<=x+1;j++)
            {
                if(a[i][j]<=min)
                {
                    y=j;
                    min=a[i][j];
                }
            }
            x=y;
            printf(" %d",x);
        }
        printf("\n");
    }
    return 0;
}