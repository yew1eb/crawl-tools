#include <iostream>
#include <cstdio>
using namespace std;

#define N 5005

int sum[N << 2]; //è®°å½åºé´çº¿æ®µåçç¹æ°

void pushUp(int rt)
{
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt)
{
    sum[rt] = 0;  //åå§æ¶ï¼ä»»æçº¿æ®µåçæ°é½ä¸º0
    if (l == r) return;
    int m = (l + r) >> 1;
    build (l, m, rt << 1);
    build (m + 1, r, rt << 1 | 1);
}

void update(int p, int l, int r, int rt)
{
    if (l == r) {
       sum[rt]++; return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p, l, m, rt << 1);
    else update(p, m + 1, r, rt << 1 | 1);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
    if (l >= L && r <= R) return sum[rt];

    int m = (l + r) >> 1, ans = 0;
    if (m >= L) ans += query(L, R, l, m, rt << 1);
    if (m < R) ans += query(L, R, m + 1, r, rt << 1 | 1);
    return ans;
}

int main()
{
    int n, i, seq[N];

    while (scanf ("%d", &n) != EOF)
    {
        build (0, n - 1, 1);
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            scanf ("%d", &seq[i]);
            sum += query(seq[i], n - 1, 0, n - 1, 1);
            /*
              queryæ±åºåºé´[seq[i], n - 1]ä¸­çç¹æ°ï¼å ä¸ºè¿ä¸ªåº
              é´åçç¹é½æ¯seq[i]åæå¥ä¸æ¯seq[i]å¤§ï¼æä»¥ï¼è¿ä¸ª
              åºé´åçç¹çä¸ªæ°å°±ç­äºseq[i]çéåºæ°, æè¿äºç¹ç
              éåºæ°å¨å èµ·æ¥ï¼å°±å¾å°æ´ä¸ªåºåçéåºæ°sumã
            */
            update(seq[i], 0, n - 1, 1);
            //æå¥seq[i], æ´æ°çº¿æ®µåçç¹æ°ã
        }
        int ans = sum;
        for (i = 0; i < n; i++)
        {
            /*
              å ä¸ºåºåä¸º[0, n-1]ï¼è¥æåé¢ä¸ä¸ªæ°ä¸ºxï¼åºåä¸­æ¯x
              å°çæ°ä¸º[0, x-1], å±xä¸ªï¼æ¯xå¤§çæ°ä¸º[x+1, n-1],
              å±n-x-1ä¸ªï¼å°xç§»å°æåï¼æ¯xå°çæ°çéåºæ°åå1ï¼
              xçåé¢æ¯xå¤§çæ°æn-x-1ä¸ªï¼xçéåºæ°å¢å n-x-1ã
              æä»¥æ°åºåçéåºæ°ä¸ºååºåçéåºæ°å ä¸n-2*x-1ã
            */
            sum = sum + n - 2 * seq[i] - 1;
            if (sum < ans) ans = sum;
        }
        printf ("%d\n", ans);
    }
    return 0;
}