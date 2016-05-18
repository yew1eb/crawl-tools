#include <iostream>
#include <cstdio>
#define _int64 long long

using namespace std;

int main()
{
    //freopen("1.txt","r",stdin);
    int h,t;
    _int64 n,m,k;
    for (h=scanf("%d",&t);h<=t;h++)
    {
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        _int64 ans=n*m*k,now=1,cnt=0,u=0;
        for (cnt=0,now=1;now<n;) cnt++,now<<=1; u+=cnt;
        for (cnt=0,now=1;now<m;) cnt++,now<<=1; u+=cnt;
        for (cnt=0,now=1;now<k;) cnt++,now<<=1; u+=cnt;
        printf("Case #%d: %I64d %I64d\n",h,ans-1,u);
    }
    return 0;
}