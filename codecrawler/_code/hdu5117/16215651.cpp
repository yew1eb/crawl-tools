#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int Max=51;
int rem[Max][Max];
const long long INF=1000000007;
int dp[Max][Max][Max][8][2];

int n,m;
int main()
{
    int t;
    scanf("%d",&t);
    int kk=1;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(rem,0,sizeof rem);
        for(int i=0; i<m; i++)
        {
            int a;
            scanf("%d",&a);
            while(a--)
            {
                int k;
                scanf("%d",&k);
                k--;
                rem[i][k]=1;
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                {
                    dp[i][j][k][0][1]=1;
                    for(int h=1; h<8; h++)
                        dp[i][j][k][h][1]=0;
                }
        int now=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    for(int h=0; h<n; h++)
                    {
                        int tt=0;
                        if(rem[i][j])tt^=1;
                        if(rem[i][k])tt^=2;
                        if(rem[i][h])tt^=4;
                        for(int x=0; x<8; x++)
                            dp[j][k][h][x][now]=dp[j][k][h][x][now^1];
                        for(int x=0; x<8; x++)
                            dp[j][k][h][x^tt][now]=(dp[j][k][h][x^tt][now]+dp[j][k][h][x][now^1])%INF;
                    }
            now^=1;
        }
        long long ans=0;
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                for(int h=0; h<n; h++)
                    ans=(ans+dp[j][k][h][7][now^1])%INF;
        printf("Case #%d: %I64d\n",kk++,ans);
    }
    return 0;
}