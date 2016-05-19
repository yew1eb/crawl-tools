#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#define N 80
using namespace std;

char num[62][N],dp[62][62][62][N];

void sum(char a[N],char b[N])
{
    int n=a[0],m=b[0],i,j,k;
    a[0]=k=max(n,m);    
    for(i=1;i<=k;i++)
    {
        a[i]+=b[i];
        if(a[i]>9)
        {
            a[i+1]++;            a[i]%=10;
            if(i+1>k)
            {
                k++;a[0]++;
            }
        }
    }
}
void cpy(char a[N],char b[N])
{
    int i;
    for(i=0;i<=b[0];i++)
    {
        a[i]=b[i];
    }
}
void add(int x,int y,int z)
{
    if(x-1>=0&&x-1>=y&&y>=z)
        sum(dp[x][y][z],dp[x-1][y][z]);
    if(y-1>=0&&x>=y-1&&y-1>=z)
        sum(dp[x][y][z],dp[x][y-1][z]);
    if(z-1>=0&&x>=y&&y>=z-1)
        sum(dp[x][y][z],dp[x][y][z-1]);
}
void fun()
{
    int i,j,k;
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=dp[0][0][0][1]=1;
    for(i=1;i<=60;i++)
        for(j=0;j<=i;j++)
            for(k=0;k<=j;k++)
            {
                add(i,j,k);
                if(i==j&&j==k)
                {
                    cpy(num[i],dp[i][j][k]);
                }
            }
}
int main()
{
    fun();
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=num[n][0];i>0;i--)
            printf("%d",num[n][i]);
        printf("\n\n");
    }
}