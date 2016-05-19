#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define MOD 1000000007
using namespace std;
long long  dp[2][1<<11][21];
char a[200][50];
int main()
{
    int n,m,c,d,i,j,used,k,cnt;
    while(scanf("%d %d %d %d",&n,&m,&c,&d)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        dp[0][0][0]=1;
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                memset(dp[1-cnt%2],0,sizeof(dp[1-cnt%2]));
                for(used=0;used<1<<m;used++)
                {
                    for(k=0;k<=d;k++)
                    {
                        if((used>>j&1)||a[i][j]=='0')
                            dp[1-cnt%2][used&~(1<<j)][k]=(dp[1-cnt%2][used&~(1<<j)][k]+dp[cnt%2][used][k])%MOD;
                        else
                        {
                            if(k<d)
                                dp[1-cnt%2][used&~(1<<j)][k+1]=(dp[1-cnt%2][used&~(1<<j)][k+1]+dp[cnt%2][used][k])%MOD;
                            if(j+1<m&&!(used>>(j+1)&1)&&a[i][j+1]=='1')
                                dp[1-cnt%2][used|1<<(j+1)][k]=(dp[1-cnt%2][used|1<<(j+1)][k]+dp[cnt%2][used][k])%MOD;
                            if(i+1<n&&a[i+1][j]=='1')
                                dp[1-cnt%2][used|1<<j][k]=(dp[1-cnt%2][used|1<<j][k]+dp[cnt%2][used][k])%MOD;
                        }
                    }
                }
                cnt++;
            }
        }
        long long sum=0;
        for(i=c;i<=d;i++)
        {
            sum=(sum+dp[cnt%2][0][i])%MOD;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
