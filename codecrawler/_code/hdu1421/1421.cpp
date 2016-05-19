#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;
const int maxn=2000+10;
const int inf=10000000;

int f[maxn];
int dp[3][maxn];

int main() {
    int n,k;
    while(cin>>n>>k) {
        for(int i=1; i<=n; ++i)
            cin>>f[i];
        sort(f+1,f+n+1);
        memset(dp,0,sizeof(dp));
        for(int i=2; i<=n; ++i) {
            for(int j=1; j<=k&&j*2<=i; ++j) {
                int c=(f[i-1]-f[i])*(f[i-1]-f[i]);
                if(j*2==i)
                    dp[i%3][j]=dp[(i-2)%3][j-1]+c;
                else
                    dp[i%3][j]=min(dp[(i-1)%3][j],dp[(i-2)%3][j-1]+c);
            }
        }
        cout<<dp[n%3][k]<<endl;
    }
    return 0;
}