//hdu 5401

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>

template<class Num>void read(Num &x)
{
    char c; int flag = 1;
    while((c = getchar()) < '0' || c > '9')
        if(c == '-') flag *= -1;
    x = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        x = (x<<3) + (x<<1) + (c-'0');
    x *= flag;
    return;
}
template<class Num>void write(Num x)
{
    if(!x) {putchar('0');return;}
    if(x < 0) putchar('-'), x = -x;
    static char s[20];int sl = 0;
    while(x) s[sl++] = x%10 + '0',x /= 10;
    while(sl) putchar(s[--sl]);
}

const int maxm = 65, Mod = 1e9 + 7;

int m, a[maxm], b[maxm];
long long c[maxm], d[maxm], l[maxm];
long long size[maxm];
std::map<std::pair<int,long long>,long long> memo;
std::map<std::pair<long long,long long>,long long> dist[maxm];

long long get_lence(int s,long long x,long long y)
{
    if(s == 0 || x == y) return 0;

    if(x > y) std::swap(x, y);

    if(x < size[a[s]] && y < size[a[s]])
        return get_lence(a[s], x, y);
    else if(x >= size[a[s]] && y >= size[a[s]])
        return get_lence(b[s], x - size[a[s]], y - size[a[s]]);
    else
    {
        std::pair<long long,long long> p = std::make_pair(x, y);
        if(dist[s].count(p)) return dist[s][p];
        dist[s][p] = (get_lence(a[s], c[s], x) + l[s] + get_lence(b[s], d[s], y - size[a[s]])) % Mod;
        return dist[s][p];
    }
}
long long count(int t,long long p)
{
    if(t == 0) return 0;
    std::pair<int,long long> s = std::make_pair(t, p);
    if(memo.count(s)) return memo[s];
    long long ret;
    if(p < size[a[t]])
        ret = (count(a[t], p) + count(b[t], d[t]) + (l[t] + get_lence(a[t], p, c[t])) * (size[b[t]] % Mod) % Mod) % Mod;
    else
        ret = (count(b[t], p - size[a[t]]) + count(a[t], c[t]) + (l[t] + get_lence(b[t], p - size[a[t]], d[t]))* (size[a[t]] % Mod) % Mod) % Mod;
    memo[s] = ret;
    return ret; 
}
void solve()
{
    static long long ans[maxm];
    for(int i = 1; i <= m; i++)
    {
        ans[i] = ans[a[i]] + ans[b[i]];
        ans[i] += (size[a[i]]%Mod)*(size[b[i]]%Mod)%Mod * l[i] % Mod;
        ans[i] += size[b[i]]%Mod * count(a[i], c[i]) % Mod;
        ans[i] += size[a[i]]%Mod * count(b[i], d[i]) % Mod;
        write(ans[i] %= Mod), puts("");
    }
}
bool init()
{
    if(scanf("%d",&m) == EOF) return false;

    for(int i = 1; i <= m; i++)
        dist[i].erase(dist[i].begin(), dist[i].end());
    memo.erase(memo.begin(), memo.end());
    size[0] = 1;
    for(int i = 1; i <= m; i++)
    {
        read(a[i]), read(b[i]), read(c[i]);
        read(d[i]), read(l[i]);
        size[i] = size[a[i]] + size[b[i]];
    }
    return true;
}
int main()
{   
    while(init()) solve();

    return 0;
}