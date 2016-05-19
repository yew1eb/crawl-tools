#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 0x7fffffff
#define maxn 100070
#define MOD 1000000007
map<int,int>mp;
map<int,int>::iterator it;
ll a[maxn],cishu[maxn];
ll kuaisumi(ll a,ll b,int c)
{
  ll ans = 1;
  a=a%c;
  while(b>0)
  {
      if(b%2==1)
      ans=(ans*a)%c;
      b=b/2;
      a=(a*a)%c;
  }
  return ans;
}
ll mul(ll x){
    return kuaisumi(2,x,MOD);
}

int main()
{
    ll m,i,j,T;
    ll n;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        memset(cishu,0,sizeof(cishu));
        mp.clear();
        ll ans=0;
        for(i=1;i<=n;i++){
            if(!mp.count(a[i])){
                ans=(ans+a[i]*mul(n-1))%MOD;
            }
            else{
                ans=(ans+ a[i]*( mul(i-1)-mp[a[i] ])%MOD*mul(n-i)%MOD  )%MOD;
            }
            mp[a[i] ]=(mp[a[i] ]+mul(i-1) )%MOD;

        }
        printf("%lld\n",(ans+MOD)%MOD);

    }
    return 0;
}
