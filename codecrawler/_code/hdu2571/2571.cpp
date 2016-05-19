#include<iostream>
#include<cstdio>
using namespace std;

int a[25][1005];
int dp[25][1005];

int main()
{
    int tes;
    cin>>tes;
    while(tes--)
    {
        int n,m;
        cin>>n>>m;
        int i,j,k;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);

        for(i=0;i<m;i++)
            dp[0][i]=-105;
        for(i=0;i<n;i++)
            dp[i][0]=-105;
        dp[0][1]=dp[1][0]=0;

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    //（x+1,y），(x,y+1)
                for(k=2;k<=m;k++)
                {
                    if(j%k==0)
                        dp[i][j]=max(dp[i][j],dp[i][j/k]);   //(x,y*k)
                }
                dp[i][j]+=a[i][j];
            }

        cout<<dp[n][m]<<endl;
    }
    return 0;
}

/*
1
3 8
9 10 10 10 10 -10 10 10
10 -11 -1 0 2 11 10 -20
-11 -11 10 11 2 10 -10 -10
*/