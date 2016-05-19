#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define M 500005
#define N 19

//è¿ånä¸­æå¤å°ä¸ªxå å­
int cal(int n, int x)
{
    int res = 0;
    do
    {
        ++res;
        n /= x;
    }
    while (n % x == 0);
    return res;
}

//å¤æ³¨ï¼ååå éæ±è§£éè¦æ±åç¼å
//F[i][j]: è¡¨ç¤ºç´ å å­ä¸ªæ°<=jæ¡ä»¶ä¸çè«æ¯ä¹æ¯åç¼åï¼Î¼(1)+Î¼(2)+...+Î¼(i)
int F[M][N];
int num[M];        //num[i]: iä¸­å«æå¤å°ä¸ªç´ å å­
int h[M];        //h[i]: -1è¡¨ç¤ºå­å¨å¹³æ¹å å­ï¼å¦åè¡¨ç¤ºæå¤å°ç§ç´ å å­

//è«æ¯ä¹æ¯å½æ°çå®ä¹
int mob(int n)
{
    if (h[n] == -1) return 0;    //å­å¨å¹³æ¹å å­æ¶ï¼Î¼(n)=0
    if (h[n] & 1) return -1;    //å¥æ°ä¸ªä¸åç´ æ°ä¹ç§¯ï¼Î¼(n)=-1
    return 1;                    //å¶æ°ä¸ªä¸åç´ æ°ä¹ç§¯ï¼Î¼(n)=1
}

int main()
{
    int t, n, m, p, i, j;
    //ç­æ³ç®åºnum[]ä»¥åh[]
    for (i = 2; i < M; i++)
    {
        if (num[i]) continue;
        for (j = i; j < M; j+=i)
        {
            int tp = cal(j, i);
            num[j] += tp;
            if (tp > 1)      //jä¸­å«æå¤ä¸ªiï¼å¿ç¶å­å¨å¹³æ¹å å­
            {
                h[j] = -1;
            }
            else if (h[j] >= 0)
            {
                ++h[j];
            }
        }
    }
    //æä¸¾iä½ä¸ºå¬å å­ï¼å¯¹B(j)çè´¡ç®å¼ä¸ºï¼mob(j/i)
    for (i = 1; i < M; i++)
    {
        for (j = i; j < M; j+=i)
        {
            F[j][num[i]] += mob(j/i);
        }
    }
    //ä¸ºäºè¡¨ç¤ºç´ å å­æ°<=jçæä¹ï¼æ±jçåç¼å
    for (i = 1; i < M; i++)
    {
        for (j = 1; j < N; j++)
        {
            F[i][j] += F[i][j-1];
        }
    }
    //ä¸ºäºåç»å éæ±è§£ï¼æ±içåç¼å
    for (i = 1; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            F[i][j] += F[i-1][j];
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &p);
        LL ans = 0;
        if (p >= N)
        {
            ans = (LL)n*m;
        }
        else
        {
            if (n > m)
            {
                n ^= m;
                m ^= n;
                n ^= m;
            }
            for (i = 1; i <= n; i = j + 1)
            {
                j = min(n/(n/i), m/(m/i));
                ans += ((LL)F[j][p]-F[i-1][p])*(n/i)*(m/i);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
