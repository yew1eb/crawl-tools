#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>

#define eps 1e-8
#define op operator
#define MOD  10009
#define MAXN  100100

#define FOR(i,a,b)  for(int i=a;i<=b;i++)
#define FOV(i,a,b)  for(int i=a;i>=b;i--)
#define REP(i,a,b)  for(int i=a;i<b;i++)
#define REV(i,a,b)  for(int i=a-1;i>=b;i--)
#define MEM(a,x)    memset(a,x,sizeof a)
#define ll __int64

using namespace std;

ll a[10000];

int main()
{
//freopen("o.txt","w",stdout);
    ll x,k;
    int cs=1;
    while(scanf("%I64d%I64d",&x,&k)!=EOF)
    {
        if(x==0&&k==0)  break;
        a[1]=x;
        ll ans=1;
        int i;
        for(i=2;i<=k;i++)
        {

            x=x-x/i;
            if(x<(i+1))   break;
        }
//        if(i<k)
            printf("Case #%d: %I64d\n",cs++,x*k);

    }
    return 0;
}
