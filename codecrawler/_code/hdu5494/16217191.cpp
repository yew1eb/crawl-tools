#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int a[1010],b[1010];
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf ("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int sum1=0;
        int sum2=0;
        for (int i=1;i<=m;i++)
            sum1+=a[i];
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b+1,b+n+1);
        for (int i=n;i>n-m;i--)
            sum2+=b[i];
        if (sum1>sum2)
            printf ("YES\n");
        else
            printf ("NO\n");
    }
    return 0;
}
