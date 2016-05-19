#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;
#define LL __int64
#define pi acos(-1.0)
LL mod;
const int INF=0x3f3f3f3f;
const double eqs=1e-9;
const int MAXN=1100000;
LL Mult(LL n, LL k)
{
        LL ans=0;
        while(k>0){
                if(k&1) ans=(ans+n)%mod;
                k>>=1;
                n=(n+n)%mod;
        }
        return ans;
}
LL qsm(LL n, LL k)
{
        LL ans=1;
        while(k>0){
                if(k&1) ans=Mult(ans,n)%mod;
                k>>=1;
                n=Mult(n,n)%mod;
        }
        return ans;
}
int main()
{
        LL n, ans;
        while(scanf("%I64d%I64d",&n,&mod)!=EOF){
                if(n==1){
                        printf("%I64d\n",1%mod);
                        continue ;
                }
                ans=qsm(2,n);
                printf("%I64d\n",(ans+mod-2)%mod);
        }
        return 0;
}
