#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define ll long long
#define pii pair<ll,ll>
#define inf (1ll<<50)
#define eps 1e-8
#define pb push_back
using namespace std;
const int maxn=110005;
int n,m;
int d[maxn];
int sum[maxn];
ll C(int a)
{
    if(a<3)
        return 0;
    return (ll)a*(a-1)*(a-2)/6;
}
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    int l,r;
    while(t--) {
        memset(sum,0,sizeof(sum));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        for(int i=1;i<=m;i++) {
            scanf("%d%d",&l,&r);
            sum[l]++;
            sum[r+1]--;
        }
        sum[0]=0;
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+sum[i];
        ll a=0;
        for(int i=1;i<=n;i++) {
            a+=C(sum[i])*d[i];
        }
        ll b=C(m);
        if(a==0 || b==0) {
            printf("0\n");
        }
        else {
            if(a%b==0)
                printf("%I64d\n",a/b);
            else {
                ll g=gcd(a,b);
                printf("%I64d/%I64d\n",a/g,b/g);
            }
        }
    }
    return 0;
}