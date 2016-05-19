#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=47337;
bool vis[maxn];
int prim[maxn];
int a[maxn];
int judge(int m)
{
    a[0]=10%m;
    a[1]=98%m;
    for(int j=2;; j++)
    {
        a[j]=(a[j-1]*10-a[j-2]+m)%m;
        //int sign=0;
        if(a[j-1]==a[0]&&a[j]==a[1])
        return j-1;
    }
}
int pow_mod(int x,int mod)
{
    long long ans=1,cur=2;
    while(x)
    {
        if(x&1)
            ans=(ans*cur)%mod;
        cur=(cur*cur)%mod;
        x=(x>>1);
    }
    return ans;
}
int main()
{
    int t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        long long x;
        scanf("%I64d%d",&x,&m);
        int cmr=judge(m);
        int cwt=pow_mod(x,cmr);
        printf("Case #%d: ",ca++);
        printf("%d\n",(a[cwt]-1+m)%m);
    }
    return 0;
}
