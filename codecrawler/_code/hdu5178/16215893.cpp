#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define LL __int64
int x[100005];
int main()
{
    int T,n,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        int i;
        LL ans=0;
        for(i=0;i<n;++i) scanf("%d",&x[i]);
        sort(x,x+n);
        for(i=0;i<n;++i)
        {
           int pos=upper_bound(x+i,x+n,x[i]+k)-x;
           --pos;
           ans+=(LL)(pos-i);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}