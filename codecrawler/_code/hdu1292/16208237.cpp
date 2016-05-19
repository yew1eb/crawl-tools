#include <iostream>
#include <cstring>
using namespace std;
long long dp[30][30];
int main(int argc, char *argv[])
{
    int t,n,i,j;long long ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        dp[1][1]=1;
        for(i=2;i<=n;i++)
        for(j=1;j<=n;j++)
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
        for(ans=0,i=1;i<=n;i++)
        ans+=dp[n][i];
        cout<<ans<<endl;
    }
    return 0;
}