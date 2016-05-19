//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ls(rt) rt*2
#define rs(rt) rt*2+1
#define ll long long
#define ull unsigned long long
#define rep(i,s,e) for(int i=s;i<e;i++)
#define repe(i,s,e) for(int i=s;i<=e;i++)
#define CL(a,b) memset(a,b,sizeof(a))
#define IN(s) freopen(s,"r",stdin)
#define OUT(s) freopen(s,"w",stdout)
const ll ll_INF = ((ull)(-1))>>1;
const double EPS = 1e-8;
const double pi = acos(-1.0);
const int INF = 100000000;

int main()
{
    int ncase;
    ll ans;
    scanf("%d",&ncase);
    int ic=0;
    while(ncase--)
    {
        ans=0;
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        for(ll i=l;i<=r;i++)
            ans+=i*i*i;
        printf("Case #%d: %I64d\n",++ic,ans);
    }
    return 0;
}
