#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200000;
int tot, v[maxn], l[maxn], r[maxn], d[maxn], f[maxn];
int findset(int x)
{return f[x]==x?x:f[x]=findset(f[x]);}
int Merge(int x, int y)
{
    if(!x) return y;
    if(!y) return x;
    if(v[x] < v[y]) swap(x, y);  //´ó¶¥¶Ñ
    r[x] = Merge(r[x], y); //µÝ¹éºÏ²¢ÓÒ×ÓÊ÷ºÍY
    f[r[x]] = x;  //¸üÐÂTÓÒ×ÓÊ÷µÄ¸ù
    if(d[l[x]] < d[r[x]]) //Î¬»¤¶ÑÐÔÖÊ
        swap(l[x], r[x]);
    d[x] = d[ r[x] ] + 1;
    return x;
}
int Init(int x)
{
    tot++;
    v[tot] = x;
    f[tot] = tot;
    l[tot] = r[tot] = d[tot] = 0;
}
int Insert(int x, int y)
{
    return Merge(x, Init(y));
}
int Top(int x)
{
    return v[x];
}
int Pop(int x)
{
    int L = l[x], R = r[x];
    f[L] = L;
    f[R] = R;
    v[x] /= 2;
    r[x] = l[x] = d[x] = 0;
    return Merge(L, R);
}
void solve(int x, int y)
{
    int left = Pop(x), right = Pop(y);
    left = Merge(left, x);
    right = Merge(right, y);
    left = Merge(left, right);
    printf("%d\n", Top(left));
}
int main()
{
    int n, m, i, x, y;
    while(~scanf("%d", &n))
    {
        tot = 0;
        for(i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            Init(x);
        }
        scanf("%d", &m);
        for(i=1; i<=m; ++i)
        {
            scanf("%d%d", &x, &y);
            int fx = findset(x), fy = findset(y);
            if(fx==fy)
            {
                printf("-1\n");
            }
            else
            {
                solve(fx, fy);
            }
        }
    }
    return 0;
}
/*
5
20
16
10
10
4
5
2 3
3 4

8
5
5
-1
10
*/
