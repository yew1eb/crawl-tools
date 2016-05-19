#pragma warning(disable:4996)  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#include <string>  
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

int n;
int val[50005];
int ans[50005];
int wc[50005];

int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int y)
{
    while (x <= n)
    {
        ans[x] = ans[x] + y;
        x = x + lowbit(x);
    }
}

int sum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += ans[x];
        x = x - lowbit(x);
    }
    return res;
}

int cal(int x)
{
    int ri = n;
    int le = 1;
    int mid;

    while (le <= ri)
    {
        mid = (le + ri) >> 1;
        if (sum(mid) >= x)
        {
            ri = mid - 1;
        }
        else
        {
            le = mid + 1;
        }
    }
    return le;
}

void solve()
{
    int i;
    for (i = 1; i <= n; i++)
    {
        add(i, 1);
    }

    for (i = n; i >= 1; i--)
    {
        int pos = i - val[i] - 1;//åé¢æå¤å°æ¯å®å°çæ°
        wc[i] = cal(pos + 1);
        add(wc[i], -1);

    }
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
            printf("%d", wc[i]);
        else
            printf(" %d", wc[i]);
    }
    printf("\n");
}
int main()
{
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);

    int t;
    int i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(ans, 0, sizeof(ans));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", val + i);
        }
        for (i = n; i >= 1; i--)
        {
            val[i] = val[i] - val[i - 1];
        }
        solve();
    }
    //system("pause");
    return 0;
}