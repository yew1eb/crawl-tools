#include<stdio.h>
int a[22][1010],f[22][1010];
int max(int x,int y,int z)
{
    if(x>=y&&x>=z)
        return x;
    else if(y>=x&&y>=z)
        return y;
    else if(z>=x&&z>=y)
        return z;
}
int main()
{
    int n,m,t,i,j,k,c;
    scanf("%d",&c);
    while(c-- && scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                f[i][j]=a[i][j];
            }
        for(i=0;i<=n;i++)
            f[i][0]=-1000;
        for(i=0;i<=m;i++)
            f[0][i]=-1000;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i==1&&j==1)
                    continue;
                t=-1000;
                for(k=2;k<=j;k++)
                {
                    if(j%k==0)
                        if(t<f[i][j/k])
                            t=f[i][j/k];
                }
                f[i][j]+=max(f[i-1][j],f[i][j-1],t);
            }
        }
        printf("%d\n",f[n][m]);
    }
    return 0;
}