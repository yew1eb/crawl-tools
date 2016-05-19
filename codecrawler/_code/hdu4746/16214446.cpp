#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;
const int N = 500100;

bool isp[N];
int p[N], cnt[N], mob[N];
int mob_sum[N][20];

#define mbs mob_sum

void Mobius()
{
    CLR(isp, 0);CLR(cnt, 0);
    int tot = 0;mob[1] = 1;
    for(int i = 2; i < N; i ++)
    {
        if(!isp[i])
        {
            p[tot ++] = i;
            mob[i] = -1;cnt[i] = 1;
        }
        for(int j = 0; j < tot && p[j] * i < N; j ++)
        {
            isp[p[j] * i] = true;
            cnt[i * p[j]] = cnt[i] + 1;
            if(i % p[j] == 0)
            {
                mob[p[j] * i] = 0;
                break;
            }
            else
            {
                mob[p[j] * i] = -mob[i];
            }
        }
    }
}

void init()
{
    Mobius();CLR(mbs, 0);
    for(int i = 1; i < N; i ++)//æ±åºåé¡¹çmbs[i][j]ï¼è¡¨ç¤ºçæ¯iä¸ºå¬å å­æ¶çæåµã
        for(int j = i; j < N; j += i)
        {
            mbs[j][cnt[i]] += mob[j / i];
        }//ä»¥ä¸æ¯æ±åç¼åã
    for(int i = 1; i < N; i ++)
        for(int j = 0; j < 19; j ++)
        {
            mbs[i][j] += mbs[i - 1][j];
        }
    for(int i = 0; i < N; i ++)
        for(int j = 1; j < 19; j ++)
        {
            mbs[i][j] += mbs[i][j - 1];
        }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int q, n, m, p;LL ans;
    init();scanf("%d", &q);
    while(q --)
    {
        scanf("%d%d%d", &n, &m, &p);
        if(p >= 19) {printf("%I64d\n", (LL)n * m); continue;}
        if(n > m) swap(n, m);
        ans = 0;
        for(int i = 1, j = 1; i < n; i = j + 1)
        {
            j = min(n / (n / i), m / (m / i));
            ans += (LL)(mbs[j][p] - mbs[i - 1][p]) * (n / i) * (m / i);
        }
        printf("%I64d\n", ans);
    }
}
