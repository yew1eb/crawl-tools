#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 200010;

int r[N], tx[N], ty[N], rs[N], ranks[N], sa[N], height[N], rmq[N][20]; //rsåºæ°æåº
char s[N];

bool cmp(int *r, int a, int b, int len)
{
    return (r[a] == r[b]) && (r[a + len] == r[b + len]);
}

void suffix(int n, int m) //nä¸ºé¿åº¦ï¼æå¤§å¼å°äºm
{
    int i, j, p, *x = tx, *y = ty, *t;
    for(i = 0; i < m; ++i)
        rs[i] = 0;
    for(i = 0; i < n; ++i) {
        x[i] = r[i];
        ++rs[x[i]];
    }
    for(i = 1; i < m; ++i)
        rs[i] += rs[i - 1];
    for(i = n - 1; i >= 0; --i)
        sa[--rs[x[i]]] = i;
    for(j = p = 1; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; ++i)
            y[p++] = i;
        for(i = 0; i < n; ++i) {
            if(sa[i] >= j)
                y[p++] = sa[i] - j;
        }
        for(i = 0; i < m; ++i)
            rs[i] = 0;
        for(i = 0; i < n; ++i)
            ++rs[x[y[i]]];
        for(i = 1; i < m; ++i)
            rs[i] += rs[i - 1];
        for(i = n - 1; i >= 0; --i)
            sa[--rs[x[y[i]]]] = y[i];
        t = x, x = y, y = t;
        for(i = 1, p = 1, x[sa[0]] = 0; i < n; ++i) {
            if(cmp(y, sa[i - 1], sa[i], j))
                x[sa[i]] = p - 1;
            else
                x[sa[i]] = p++;
        }
    }
    /**for(i = 0; i < n; ++i)
    printf("%s\n", s + sa[i]);*/
}

void calheight(int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; ++i)
        ranks[sa[i]] = i;
    for(i = 0; i < n; ++i) {
        if(k)
            --k;
        j = sa[ranks[i] - 1];
        while(r[i + k] == r[j + k])
            ++k;
        height[ranks[i]] = k;
    }
}

void initrmq(int n)
{
    int i, k;
    for(i = 2; i <= n; ++i)
        rmq[i][0] = height[i];
    for(k = 1; (1 << k) <= n; ++k) {
        for(i = 2; i + (1 << k) - 1 <= n; ++i) {
            rmq[i][k] = min(rmq[i][k - 1],
                rmq[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int Log[N];
void initlog()
{
Log[0] = -1;  
    for(int i=1;i<N;i++){  
        Log[i]=(i&(i-1))?Log[i-1]:Log[i-1] + 1 ;}
}

int lcp(int a, int b)
{
    a = ranks[a], b = ranks[b];
    if(a > b)
        swap(a, b);
    ++a;
    int k = (int) Log[b - a + 1] / Log[2];
    return min(rmq[a][k], rmq[b - (1 << k) + 1][k]);
}
//æ±ä¸¤ä¸ªä¸²çæé¿å¬å±å­ä¸²

int main()
{
    while( scanf("%s", s)!=EOF)
    {
        int i, l1, n, ans;
        l1 = strlen(s);
        s[l1] = 1;
        scanf("%s", s + l1 + 1);
        n = strlen(s);
        for(i = 0; i < n; ++i)
            r[i] = s[i];
        r[n] = 0;//ä¾¿äºæ¯è¾
        suffix(n + 1, 128);
        calheight(n);
        ans = 0;
        for(i = 2; i <= n; ++i) {
            if((height[i] > ans) &&
                ((sa[i - 1] < l1 && sa[i] > l1) ||
                (sa[i - 1] > l1 && sa[i] < l1)))
                ans = height[i];
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
