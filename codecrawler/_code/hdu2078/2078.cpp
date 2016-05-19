#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int i,cas,n,m,ans;
    int a[45];
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        ans=(100-a[0])*(100-a[0]);
        printf("%d\n",ans);
    }
    return 0;
}