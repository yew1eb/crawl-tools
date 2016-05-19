#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define ll long long
#define db double
#define PB push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;

const int N = 100005;

int head[N], nxt[N << 1], to[N << 1], nedge;
bool on[N];
int c[N], num[N], sz[N];

void init(int n)
{
    for(int i = 1; i <= n; i++) head[i] = -1, on[i] = false, sz[i] = 0;
    nedge = 0;
}

void addedge(int u, int v)
{
    to[nedge] = v, nxt[nedge] = head[u], head[u] = nedge++;
}

bool oncir;
int st, lc;
void dfs(int k, int fa)
{
    on[k] = true;
    for(int i = head[k]; i >= 0; i = nxt[i])
    {
        if(to[i] != fa)
        {
            if(on[to[i]])
            {
                c[++lc] = k;
                oncir = true;
                st = to[i];
                return;
            }
            else
            {
                dfs(to[i], k);
                if(oncir) break;
            }
        }
    }
    if(oncir) c[++lc] = k;
    on[k] = oncir;
    if(k == st) oncir = false;
}

int cnt[N];

int calc(int k)
{
    for(int i = 0; i < k; i++) cnt[i] = 0;
    int s(0);
    for(int i = 0; i < lc; i++)
    {
        s += num[c[i]];
        s %= k;
        cnt[s]++;
    }
    int p(0);
    int res(cnt[p]);
    for(int i = lc; i > 1; i--)
    {
        p = ((p - num[c[i]]) % k + k) % k;
        res = max(res, cnt[p]);
    }
    return res;
}

void getK(int k, int fa)
{
    num[k] = 1;
    for(int i = head[k]; i >= 0; i = nxt[i])
    {
        if(to[i] != fa && !on[to[i]])
        {
            getK(to[i], k);
            num[k] += num[to[i]];
        }
    }
    if(fa) sz[num[k]]++;
}

void sum()
{
    for(int i = 1; i <= lc; i++)
    {
        getK(c[i], 0);
    }
}

int gets(int k,int n)
{
    int res(0);
    for(int i=k;i<=n;i+=k)
        res+=sz[i];
    return res;
}

int main()
{
#ifdef PKWV
    freopen("in.in", "r", stdin);
//    freopen("1003.k.out","w",stdout);
#endif // PKWV
    int n;
    while(scanf("%d", &n) + 1)
    {
        init(n);
        for(int i = 1; i <= n; i++)
        {
            int v;
            scanf("%d", &v);
            addedge(i, v), addedge(v, i);
        }
        oncir = false, lc = 0;
        dfs(1, 0);
        sum();
        int ans(0);
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                if(gets(i,n) + calc(i) == n / i) 
                {
                    ans++;
                }
                if(i != n / i)
                {
                    if(gets(n / i,n) + calc(n / i) == i) 
                    {
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
