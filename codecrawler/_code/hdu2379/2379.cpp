#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int LEN=52;
const int N=7;

__int64 dp[N][LEN];
int cnt[11];

int main()
{
    int t,m,n,q,i,k,j,l;
    scanf("%d",&t);
    string a;
    while (t--)
    {
        scanf("%d%d%d",&m,&n,&q);
        while (m--)
        {
            cin>>a;
            cnt[a.length()]++;
        }
        memset(dp,0,sizeof(dp));
        for (i=1;i<=10;i++)
        {
            dp[1][i]=cnt[i];
            dp[i][i]=cnt[1];
        }
		for (i=0;i<5;i++)
        {
            for (k=0;k<=10;k++)
            {
                for (j=0;j<=LEN-k;j++)
                {
                    dp[i+1][j+k]+=dp[i][j]*cnt[k];
                }
            }
        }
        while (q--)
        {
            scanf("%d",&l);
            printf("%I64d\n",dp[n][l]);
        }
    }
    return 0;
}