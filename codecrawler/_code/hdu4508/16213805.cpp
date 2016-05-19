#include <bits/stdc++.h>
const int maxn = 100010;
using namespace std ;
int n ,a[maxn],b[maxn],dp[maxn],m; 
int main()
{
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i < n ; i++)
        {
            cin>>a[i]>>b[i];
        }
        cin>>m;
        for(int i = 0 ; i<n;i++)
        {
            for(int j=b[i];j<=m;j++)
            {
                dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0 ;
}