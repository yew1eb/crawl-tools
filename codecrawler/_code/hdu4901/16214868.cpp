#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
__int64 a0[1111][1111],a1[1111][1111],b1[1111][1111],b0[1111][1111],s[1111];

int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(a0,0,sizeof(a0));
        memset(a1,0,sizeof(a1));
        memset(b0,0,sizeof(b0));
        memset(b1,0,sizeof(b1));
        scanf("%d",&n);
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&s[i]);
            a1[i][s[i]] = b1[i][s[i]] = 1;
        }
        for(i = 2; i<=n; i++)
            for(j = 0; j<=1024; j++)
            {
                if(a1[i-1][j] || a0[i-1][j])
                {
                    a1[i][j^s[i]] = (a1[i][j^s[i]]+a1[i-1][j]+a0[i-1][j])%mod;
                    a0[i][j] = (a0[i][j]+a1[i-1][j]+a0[i-1][j])%mod;
                }
            }
        for(i = n-1; i>=1; i--)
            for(j = 0; j<=1024; j++)
            {
                if(b1[i+1][j] || b0[i+1][j])
                {
                    b0[i][j] = (b0[i][j]+b1[i+1][j]+b0[i+1][j])%mod;
                    b1[i][j&s[i]] = (b1[i][j&s[i]]+b1[i+1][j]+b0[i+1][j])%mod;
                }
            }
        __int64 sum = 0;
        for(i = 1; i<=n; i++)
            for(j = 0; j<=1024; j++)
            {
                if(a1[i][j] && b0[i][j])
                    sum = (sum+(a1[i][j]*b0[i][j])%mod)%mod;
            }
        printf("%I64d\n",sum%mod);
    }

    return 0;
}
