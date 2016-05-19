#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string a,b;
int dp[200][200];
int f[200];
void solve(int i,int j)
{
    if(dp[i][j]>=0)return;
    solve(i+1,j);
    if(b[i]==b[j]){
        dp[i][j]=dp[i+1][j];
        return;
    }
    dp[i][j]=dp[i+1][j]+1;
    for(int k=i+1;k<=j-1;k++)
    if(b[i]==b[k])
    {
        solve(i+1,k);
        solve(k+1,j);
        if(dp[i+1][k]+dp[k+1][j]<dp[i][j]||dp[i][j]==-1)
        dp[i][j]=dp[i+1][k]+dp[k+1][j];
    }
}
int main()
{
    while(cin>>a>>b)
    {
        int l=a.length();
        memset(dp,-1,sizeof(dp));
        memset(f,-1,sizeof(f));
        for(int i=0;i<l;i++)
        dp[i][i]=1;
        for(int i=0;i<l;i++)
         for(int j=i;j<l;j++)
         if(dp[i][j]==-1)
        solve(i,j);
        f[0]=a[0]==b[0]?0:1;
        for(int i=1;i<l;i++)
        {
            f[i]=dp[0][i];
            if(a[i]==b[i])
              f[i]=f[i-1];
            else
            for(int j=0;j<=i-1;j++)
            if(f[j]+dp[j+1][i]<f[i])
            f[i]=f[j]+dp[j+1][i];
        }
        cout<<f[l-1]<<endl;
    }
    return 0;
}