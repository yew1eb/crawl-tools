#include<stdio.h>
#include<string.h>
int i,j,m,n,k,dp[210][2110],dir[4][2]={1,0,0,1,1,2,2,1};
int max(int a,int b,int c,int d)
{
    a=a>b?a:b;
    a=a>c?a:c;
    return a>d?a:d;
}
int judge(int x,int y)
{
    return x>=0&&y>=0&&dp[x][y]>0;
}
void f()
{
    int a[4],l,x,y,maxc;
    for(i=1;i<n;i++)
    {
        for(j=0;j<=m*i;j++)
        {
            for(l=0;l<4;l++)
            {
                x=i-dir[l][0];
                y=j-dir[l][1];
                a[l]=judge(x,y)?dp[x][y]-k:-1;
                //if(judge(x,y))printf("x==%d,y==%d\n",x,y);
            }
            maxc=max(a[0],a[1],a[2],a[3]);
            dp[i][j]=maxc>0?dp[i][j]+maxc:-1;
        }
    }
}
int main()
{
    //freopen("2.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            for(j=0;j<=m*i;j++)
            {
                scanf("%d",&dp[i][j]);
            }
            //for(;j<m*i+5&&j<m*(n-1);j++)//*
                //dp[i][j]=-1;
        }
        f();
        for(j=-1,i=0;i<=m*(n-1);i++)
        {
            if(j<0)j=j>dp[n-1][i]?j:dp[n-1][i];
            else if(dp[n-1][i]>0)j=j<dp[n-1][i]?j:dp[n-1][i];
        }
        if(j==-1)printf("what a pity mouse!!\n");
        else printf("%d\n",j);
    }
    return 0;
}
