/*
* 题意：给出一个带权值的矩阵，从左上角走
* 到右下角，问怎样走才能使总权值最大； 
* 行走的要求 ：如果当前格子是（x,y），
* 下一步可以是（x+1,y），(x,y+1)或者(x,y*k) 其中k>1。 
*  
* 思路：DP，状态转移方程:
* sum[i][j]=max{sum[i-1][j],sum[i][k]}+v[i][j];
* 其中1<=k<=j-1,且k是j的因子或k=j-1，即向右走一格    
*
*/

#include<stdio.h>
#define MIN -10000000
int num[22][1002],n,m;
int dp[22][1002];
void initi()
{
    for(int i=0;i<=m;i++)
        dp[0][i]=MIN;
    for(int i=0;i<=n;i++)
        dp[i][0]=MIN;
}
int getMax(int x,int y)
{
    int Max=dp[x][y-1];
    if(dp[x-1][y]>Max)
        Max=dp[x-1][y];
    if(x==1&&y==1)
        return 0;
    for(int i=1;i<y;i++)
    {
        if(y%i==0)
            if(dp[x][i]>Max)
                Max=dp[x][i];
    }
    return Max;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j;
        scanf("%d%d",&n,&m);
        initi();
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&num[i][j]);
        dp[1][1]=num[1][1];
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                    dp[i][j]=num[i][j]+getMax(i,j);
        printf("%d\n",dp[n][m]);    
    }
    return 0;
}