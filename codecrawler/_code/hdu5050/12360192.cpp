#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#define inf 0x3fffffff
#define esp 1e-10

using namespace std;

struct node
{
    int val[1005];
    int len;
};

node x, ans;

int judge (int *a, node b)
{
    for (int i = b.len - 1; i >= 0; --i)
    {
        if (a[i] > b.val[i])
            return 1;
        if (a[i] < b.val[i])
            return -1;
    }
    return 0;
}

int Minus(int *a, int lena, node b)
{
    for (int i = 0; i < b.len; ++i)
        x.val[i] = a[i] - b.val[i];
    x.len = b.len;
    if (lena > b.len)
    {
        x.len = lena;
        x.val[x.len-1] = a[lena-1];
    }
    for (int i = 0; i < x.len-1; ++i)
    {
        while (x.val[i] < 0)
        {
            x.val[i+1] -= 1;
            x.val[i] += 2;
        }
    }
    while (x.val[x.len-1] == 0 && x.len > 0)
        x.len--;
    for(int i = 0; i < x.len; ++i)
        a[i] = x.val[i];
    return x.len;
}

node mod(node a, node b)
{
    for (;;)
    {
        if (a.len < b.len)
            return a;
        if (a.len == b.len && judge (a.val, b) < 0)
            return a;
        int x = a.len -b.len;
        if (judge(a.val+x, b) >= 0)
        {
            a.len = Minus(a.val+x, b.len, b) + x;
            while (a.val[a.len-1] == 0 && a.len > 0)
                a.len--;
        }
        else
            a.len = Minus(a.val+x-1, b.len+1, b) + x - 1;
    }
}

node gcd(node a, node b)
{
    for (;;)
    {
        if (b.len == 0) return a;
        x = mod(a, b);
        a = b;
        b = x;
    }
    //else return gcd(b, mod(a, b));
}

char aa[1005], bb[1005];
node a, b;

int main()
{
    //freopen ("test.txt", "r", stdin);
    int T;
    scanf ("%d", &T);
    for (int times = 1; times <= T; ++times)
    {
        getchar();
        scanf ("%s%s", aa, bb);
        int len = strlen(aa);
        a.len = strlen(aa);
        for (int i = 0; i < len; ++i)
            a.val[len-1-i] = aa[i] - '0';
        len = b.len = strlen(bb);
        for (int i = 0; i < len; ++i)
            b.val[len-1-i] = bb[i] - '0';
        ans = gcd(a, b);
        printf ("Case #%d: ", times);
        for (int i = ans.len-1; i >= 0; --i)
            printf ("%d", ans.val[i]);
        printf ("\n");
    }
    return 0;
}