#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <assert.h>

#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define eps 1e-8
#define M_PI 3.141592653589793

typedef long long ll;
const ll mod=1000000007;
const int inf=0x7fffffff;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll dp[1210],c[1210],v[2110];
using namespace std;
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&c[i],&v[i]);
            c[i]=c[i-1]+c[i];
        }
        for(int i=0;i<=n;i++){
          dp[i]=inf;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                dp[i]=min(dp[i],dp[j]+(c[i]-c[j]+10)*v[i]);
            }
        }
        cout<<dp[n]<<endl;
    }
}

