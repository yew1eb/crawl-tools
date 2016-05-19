#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int dp[21][192];
    int n,i,j,r;
    for(i=0;i<21;i++)//iæ¡ç´çº¿
    {
        for(j=0;j<192;j++)//jä¸ªäº¤ç¹
        {
            if(j==0) dp[i][j]=1;//ä¸0æ¡çº¿å¹³è¡
            else dp[i][j]=0;
        }
    }
    for(i=0;i<21;i++)
    {
        for(r=0;r<i;r++)
        {
            for(j=0;j<192;j++)
            {
                if(dp[r][j]==1)
                    dp[i][(i-r)*r+j]=1;
            }
        }
    }
    while(~scanf("%d",&n))
    {
        for(i=0;i<n*(n-1)/2;i++)
        {
            if(dp[n][i])
            cout<<i<<" ";

        }
        cout<<i<<endl;
        
    }
    return 0;
}