#include <stdio.h>
#define INF 0xfffffff
#define N 500005
int p[N], b[N], d[N];
int  n;
int lower_bound(int num, int m)
{
    int mid, low = 1, high = m;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(num>=b[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int LIS()
{
    int i, k, ans;
    for(i=1; i<=n; i++) b[i] = INF;
    for(i=1; i<=n; i++)
    {
        k = lower_bound(p[i],n);
        d[i] = k;
        b[k] = p[i];
    }
    ans = 0;
    for(i=1; i<=n; i++)
        if(d[i]>ans) ans = d[i];
    return ans;
}
int main()
{
    int a, b;
    int nCases = 1;
    while(scanf("%d", &n) != EOF)
    {
        for(int i=1; i<=n; ++i)
        {
            scanf("%d %d", &a, &b);
            p[a] = b;
        }
        int ans = LIS();
        printf("Case %d:\nMy king, at most %d road", nCases++, ans);
        if(ans != 1) printf("s");
        printf(" can be built.\n\n");
    }
    return 0;
}
