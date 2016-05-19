#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#define LL __int64
using namespace std;
LL n;
LL sum;
LL maxs;
LL ans;
LL a[110000];
int main()
{
    int t;
    int k=1;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        ans=0;
        maxs=0;
        scanf("%I64d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
            if(maxs<a[i])
            {
                maxs=a[i];
            }
            sum+=a[i];
        }
        ans+=sum/2;
        if(sum%2!=0)
        {
            ans++;
        }
        ans=max(ans,maxs);
        printf("Case #%d: %I64d\n",k++,ans);
    }
    return 0;
}