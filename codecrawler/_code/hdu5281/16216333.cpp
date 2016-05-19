#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=100000+5;
typedef long long LL;
LL a[maxn],b[maxn];
bool cmp(LL a, LL b)
{
    return a>b;
}
int main()
{
    int T;
    scanf("%d",&T);
    int m,n;
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
            scanf("%lld",&a[i]);
        sort(a,a+m,cmp);
        for(int i=0; i<n; i++)
            scanf("%lld",&b[i]);
        sort(b,b+n);
        //int minn=n<m?n:m;
        int minn=min(m,n);
        LL sum=0;
        for(int i=0; i<minn; i++)
        {
            if(a[i]>=b[i])
                sum+=a[i]-b[i];
            else
                break;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
