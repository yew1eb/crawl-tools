#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

#define sqr(x) ((x)*(x))
#define LL long long 
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define eps 1e-10
#define mod 1000000007
using namespace std;
int bitc(int x)//è®¡ç®LCSé¿åº¦
{
    int ans=0;
    while (x)
    {
        ans+=x%2;
        x/=2;
    }
    return ans;
}
int dp[2][(1<<16)+10];
int to[(1<<16)+10][4];
int bt[20];
int go[20];
int ma[20];
int t[20];
char l[5]="ACGT";
char s[100];
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        n=strlen(s);
        scanf("%d",&m);
        for (int i=0;i<(1<<(n+1));i++)
        {
            bt[0]=0;
            // printf("%d   ",i );
            for (int j = 1; j <= n; ++j)
            {
                if ((1<<(j-1))&i) bt[j]=bt[j-1]+1;
                else bt[j]=bt[j-1];
            }
            for (int p = 0; p < 4; ++p)
            {
                go[0]=0;
                for (int j = 1; j <= n; ++j)
                {
                    if (l[p]==s[j-1]) go[j]=bt[j-1]+1;
                    else go[j]=max(go[j-1],bt[j]);
                }
                int tmp=0;
                for (int j = 1; j <= n; ++j)
                if (go[j]-go[j-1])
                {
                    tmp|=1<<(j-1);
                }
                to[i][p]=tmp;
                // printf("%d|",tmp );
            }
            // puts("");
        }
        memset(dp[0],0,sizeof dp[0]);
        dp[0][0]=1;
        for (int i=1;i<=m;i++)
        {
            memset(dp[i&1],0,sizeof dp[i&1]);
            for (int j=0;j<(1<<(n+1));j++)
            {
                if (dp[i&1^1][j]==0) continue;
                for (int p=0;p<4;p++)
                {
                    dp[i&1][to[j][p]]+=dp[i&1^1][j];
                    dp[i&1][to[j][p]]%=mod;
                }
            }

            // for (int j=0;j<(1<<(n+1));j++)
            //     printf("%d ",dp[i&1][j]);
            // puts("");
        }
        memset(t,0,sizeof t);
        for (int j=0;j<(1<<(n+1));j++)
            {
                t[bitc(j)]+=dp[m&1][j];
                t[bitc(j)]%=mod;
            }
        for (int i=0;i<=n;i++)
            printf("%d\n",t[i]);
    }
    return 0;
}
/*
1
GTC
10 


1
22783
528340
497452
*/