#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;

const LL MOD=1000000007;

LL a[550];
LL A[550];
LL C[550][550];
LL dp[55][550];

void Init()
{
    for(int i=0; i<550; i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1; j<i; j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    A[0]=1;
    for(int i=1; i<550; i++)
        A[i]=(A[i-1]*i)%MOD;
}

int main()
{
    Init();
    int T,n,tt=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        memset(dp,0,sizeof(dp));
        dp[1][a[1]-1]=1;
        LL sum=a[1];
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<sum; j++)        //对每一种空位
                for(int k=1; k<=a[i]; k++)  //将a[i]个元素分成k组
                    for(int u=0; u<=j && u<=k; u++) //将u组放到前j个空位中
                        dp[i][j-u+a[i]-1-(k-1)]=(dp[i][j-u+a[i]-k]+(((dp[i-1][j]*C[j][u])%MOD*C[sum+1-j][k-u])%MOD*C[a[i]-1][k-1])%MOD)%MOD;
            sum+=a[i];
        }
        printf("Case %d: ",tt++);
        LL ans=dp[n][0];
        for(int i=1; i<=n; i++)    //对每一组，进行全排列
            ans=(ans*A[a[i]])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
