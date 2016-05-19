#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<cctype>
#include<queue>
#define LL long long
using namespace std;
const double eps=1e-10;
const double pi=acos(-1.0);
const int N=1e5+10;
const int mod=1e9+7;
int n;
int sum[15][15][110];
int a[15];
set<LL> vis;

void dfs(int x,int s)
{
    if(x>n)
    {
        int t=0;
        for(int len=1;len<=n;len++)
        {
            vis.clear();
            for(int i=1;i+len-1<=n;i++)
            {
                LL C=0;
                for(int j=0;j<len;j++)
                {
                    C=C*10+a[i+j];
                }
                vis.insert(C);
            }
            t+=(int)vis.size();
        }
        sum[n][s][t]++;
        return;
    }
    for(int i=1;i<=s;i++)
    {
        a[x]=i;
        dfs(x+1,s);
    }
    a[x]=s+1;
    dfs(x+1,s+1);
}
int main()
{
    for(n=1;n<=10;n++)
        dfs(1,0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int I[15];
        int ans=0;
        I[1]=k;
        for(int i=2;i<=n;i++)
            I[i]=(LL)I[i-1]*(k-i+1)%mod;
        for(int i=1;i<=k&&i<=n;i++)
        {
            int res=(LL)sum[n][i][m]*I[i]%mod;
            ans=(ans+res)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
