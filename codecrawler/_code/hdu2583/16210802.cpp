#include<stdio.h>
int ans[111][111];
int main()
{
    int n,k,i,j;
    for(i=0;i<=100;i++)
    {
        ans[i][0]=1;
        ans[0][i]=0;
    }
    for(i=1;i<=100;i++)
        for(j=1;j<=100;j++)
           {
               ans[i][j]=ans[i-1][j]*(j+1)+ans[i-1][j-1]*(i-j);
               ans[i][j]%=2009;
           }
    while(scanf("%d %d",&n,&k)!=EOF)
    {
             printf("%d\n",ans[n][k]);
    }
    return 0;
}
