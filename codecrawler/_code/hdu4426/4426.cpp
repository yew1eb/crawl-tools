/*
 * Author: Gatevin
 * Created Time:  2015/3/26 19:01:01
 * File Name: Chitoge_Kirisaki.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
typedef unsigned long long ulint;
#define maxn 100100
#define rank rrank
const ulint seed = 50009;
const lint mod = 777777777LL;
set <ulint> S;
ulint H[maxn], xp[maxn];
lint W[maxn], xp2[maxn], w[30], K, cnt[maxn];
char in[maxn], in_new[maxn << 1];
int s[maxn], sa[maxn], R[maxn << 1];
vector<pair<lint, lint> > result;

void inithash(int n)//对于原字符串的hash判断回文串种类
{
    H[0] = in[0] – 'a' + 1;
    for(int i = 1; i < n; i++)
        H[i] = H[i - 1]*seed + (ulint)(in[i] – 'a' + 1);
    return;
}

ulint askhash(int l, int r)
{
    if(l == 0) return H[r];
    return H[r] – H[l - 1]*xp[r - l + 1];
}

void initWeight(int n)
{
    W[0] = w[in[0] – 'a'];
    for(int i = 1; i < n; i++)
        W[i] = (W[i - 1]*26LL + w[in[i] – 'a']) % mod;
    return;
}

lint askWeight(int l, int r)
{
    if(l == 0) return W[r];
    return (W[r] – W[l - 1]*xp2[r - l + 1] % mod + mod) % mod;
}

int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i++) Ws[i] = 0;
    for(i = 0; i < n; i++) Ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for(i = n – 1; i >= 0; i–) sa[--Ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for(p = 0, i = n – j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] – j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) Ws[i] = 0;
        for(i = 0; i < n; i++) Ws[wv[i]]++;
        for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
        for(i = n – 1; i >= 0; i–) sa[--Ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p – 1 : p++;
    }
    return;
}

int rank[maxn], height[maxn];
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i++]] = k)
        for(k ? k– : 0, j = sa[rank[i] – 1]; r[i + k] == r[j + k]; k++);
    return;
}

int dp[maxn][20];
void initRMQ(int n)
{
    for(int i = 1; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) – 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    return;
}

int askRMQ(int a, int b)
{
    //int ra = rank[a], rb = rank[b];
    int ra = a, rb = b;
    if(ra > rb) swap(ra, rb);
    int k = 0;
    while((1 << (k + 1)) <= rb – ra + 1) k++;
    return min(dp[ra][k], dp[rb - (1 << k) + 1][k]);
}

lint calCnt(int l, int r, int n)
{
    int rl = rank[l];
    int L = rl + 1, R = n, mid;
    lint lmost = rl, rmost = rl;
    while(L <= R)//向左和向右都二分一次找到左右界
    {
        mid = (L + R) >> 1;
        if(askRMQ(rl + 1, mid) >= (r – l + 1))
        {
            rmost = mid;
            L = mid + 1;
        }
        else
            R = mid – 1;
    }
    L = 1; R = rl – 1;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        if(askRMQ(mid + 1, rl) >= (r – l + 1))
        {
            lmost = mid;
            R = mid – 1;
        }
        else
            L = mid + 1;
    }
    return rmost – lmost + 1;
}

vector <pair<int, int> > pal;

void Manacher(char *s, int *R, int n)
{
    S.clear();
    int p = 0, mx = 0;
    R[0] = 1;
    for(int i = 1; i < n; i++)//第n个字符不要算..没注意这里WA了好几次….
    {
        if(mx > i) R[i] = min(R[2*p - i], mx – i);
        else R[i] = 1;
        while(s[i - R[i]] == s[i + R[i]])
            R[i]++;
        if(i + R[i] > mx)
        {
            for(int j = mx; j < i + R[i]; j++)//每一次mx的位移都可能是一个新的回文串
            {
                int l = 2*i – j, r = j;
                l >>= 1;
                r = (r & 1) ? r >> 1 : (r >> 1) – 1;//对应的回文串的原位置[l, r]
                if(l > r) continue;
                ulint hashvalue = askhash(l, r);//hash判断这个回文串是否出现过
                set<ulint> :: iterator it = S.find(hashvalue);
                if(it == S.end())
                {
                    S.insert(hashvalue);
                    pal.push_back(make_pair(l, r));
                }
            }
            mx = i + R[i], p = i;
        }
    }
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    xp[0] = 1, xp2[0] = 1;
    for(int i = 1; i < maxn; i++)
        xp[i] = xp[i - 1]*seed, xp2[i] = xp2[i - 1]*26LL % mod;
    while(T–)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        scanf("%s", in);
        in_new[0] = '@';
        s[0] = in[0] – 'a' + 1;
        for(int i = 0; i < n; i++)
            in_new[2*i + 1] = in[i], in_new[2*i + 2] = '#', s[i] = in[i] – 'a' + 1;
        in_new[2*n] = '$';
        s[n] = 0;
        da(s, sa, n + 1, 28);
        calheight(s, sa, n);
        initRMQ(n);
        pal.clear();
        inithash(n);
        Manacher(in_new, R, 2*n);
        for(int i = pal.size() – 1; i >= 0; i–)//后缀数组二分查找每种回文串的数量
            cnt[i] = calCnt(pal[i].first, pal[i].second, n);
        while(m–)
        {
            scanf("%I64d", &K);
            for(int i = 0; i < 26; i++)
                scanf("%I64d", w + i);
            initWeight(n);
            result.clear();
            for(int i = pal.size() – 1; i >= 0; i–)//对第i种回文串类似hash的方法求出权值
            {
                lint weight = askWeight(pal[i].first, (pal[i].first + pal[i].second) >> 1);
                result.push_back(make_pair(weight, cnt[i]));
            }
            sort(result.begin(), result.end());
            int now = 0;
            while(K > result[now].second)
                K -= result[now].second, now++;
            printf("%I64d\n", result[now].first);
        }
        printf("\n");
    }
    return 0;
}
