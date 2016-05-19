/*
 * Author: Gatevin
 * Created Time:  2015/9/26 18:55:50
 * File Name: Sakura_Chiyo.cpp
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

#define ws Ws
#define rank rrrank

const int maxn = 100200 + 1;//Mobiusç­å°maxn - 1
int prime[maxn], vis[maxn], mu[maxn];
int tot;
void Mobius(){
    mu[1] = 1;
    for( int i = 2 ; i < maxn ; i ++ ){
        if( !vis[i] )
            prime[++tot] = i, mu[i] = -1;
        for( int j = 1 ; j <= tot && i * prime[j] < maxn ; j ++ ){
            vis[i*prime[j]] = 1;
            if( i % prime[j] == 0 ){
                mu[i*prime[j]] = 0;
                break;
            }
            else
                mu[i*prime[j]] = - mu[i];
        }
    }
    return;
}

int wa[maxn], wb[maxn], wv[maxn], ws[maxn];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i++) ws[i] = 0;
    for(i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) ws[i] += ws[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p)
    {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) ws[i] = 0;
        for(i = 0; i < n; i++) ws[wv[i]]++;
        for(i = 1; i < m; i++) ws[i] += ws[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}

int rank[maxn], height[maxn];
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i++]] = k)
        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

int rank2[maxn], height2[maxn];
void calheight2(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rank2[sa[i]] = i;
    for(i = 0; i < n; height2[rank2[i++]] = k)
        for(k ? k-- : 0, j = sa[rank2[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

int dp[maxn][20];
void initRMQ(int n)
{
    for(int i = 1; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    return;
}

int dp2[maxn][20];
void initRMQ2(int n)
{
    for(int i = 1; i <= n; i++) dp2[i][0] = height2[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            dp2[i][j] = min(dp2[i][j - 1], dp2[i + (1 << (j - 1))][j - 1]);
    return;
}

int askRMQ(int a, int b)
{
    int ra = rank[a], rb = rank[b];
    if(ra > rb) swap(ra, rb);
    int k = 0;
    while((1 << (k + 1)) <= rb - ra) k++;
    return min(dp[ra + 1][k], dp[rb - (1 << k) + 1][k]);
}

int len;
int askRMQ2(int a, int b)
{
    a = len - a - 1;
    b = len - b - 1;
    int ra = rank2[a], rb = rank2[b];
    if(ra > rb) swap(ra, rb);
    int k = 0;
    while((1 << (k + 1)) <= rb - ra) k++;
    return min(dp2[ra + 1][k], dp2[rb - (1 << k) + 1][k]);
}

char in[maxn];
int s[maxn], sa[maxn];

int main()
{
    Mobius();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", in);
        len = strlen(in);
        for(int i = 0; i < len; i++)
            s[i] = in[i] - 'a' + 1;
        s[len] = 0;
        da(s, sa, len + 1, 28);
        calheight(s, sa, len);
        initRMQ(len);
        
        for(int i = 0; i < len; i++)
            s[i] = in[len - 1 - i] - 'a' + 1;
        s[len] = 0;
        da(s, sa, len + 1, 28);
        calheight2(s, sa, len);
        initRMQ2(len);
        
        
        lint ans = 0;
        for(int L = 1; L <= (len >> 1); L++)//æä¸¾å¾ªç¯èé¿åº¦
        {
            int n = len;
            int blocks = n / L + (n % L != 0);
            int now = 1;
            while(now < blocks)
            {
                if(now + 1 < blocks)
                {
                    int len2 = askRMQ2((now + 1)*L - 1, now*L - 1);//ç¨åç¼æ°ç»åååååæ¾å°åºé´[L, R]è¿ä¸ªä¸²ä¸­ä»»æé¿åº¦æ¯Lç2ä»¥ä¸åæ°çå­ä¸²é½ä¸åæ³
                    int len1 = askRMQ(now*L, (now + 1)*L);
                    int totlen = L + len2 + len1;
                    int cnt = totlen / L;
                    for(int i = 2; i <= cnt; i++)
                    {
                        ans += mu[i]*(totlen - L*i + 1);
                    }
                    //now = now + (len1 / L) + (len1 % L != 0) + 1;æ³¨æä¸è¦è·³ælen1 % L != 0çæ¶åä¸­é´é£ä¸ªæ²¡ç¨å®çæ®µ
                    //printf("find1 L = %d, ans = %I64d, totlen = %d, now = %d\n", L, ans, totlen, now);
                    now = now + (len1 / L) + 1;
                    
                }
                else
                {
                    if(n % L != 0) break;//æ³¨ææ«å°¾...åå¼å§è¿éæ²¡æ³¨æå°...å¯¹äºababababababä¸ä¸ªä¸ªæ°ç»äºåç°äºè¿ä¸ªéè¯¯
                    int totlen = (len - now*L) + askRMQ2(len - 1, now*L - 1);
                    int cnt = totlen / L;
                    //int num = totlen % L + 1;
                    for(int i = 2; i <= cnt; i++)
                        ans += mu[i]*(totlen - L*i + 1);
                    //printf("find2 L = %d, ans = %I64d, totlen = %d, now = %d\n", L, ans, totlen, now);
                    now = blocks;
                }
            }
        }
        printf("%I64d\n", (lint)len*(len + 1LL) / 2LL + ans);
    }
    return 0;
}
/*
5
aaccaa
abcabc
aaaaaa
abababababab

18
20
6
53

*/