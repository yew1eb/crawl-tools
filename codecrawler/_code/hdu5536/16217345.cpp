#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int a[MAXN];

inline int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        //input
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            scanf("%d", &a[i]);

        //sort
        sort(a, a + n);

        //main
        int maxValue = a[n-1] + a[n-2]; //æ¾å°æå¤§å¼
        int maxLimit = maxValue;
        int ans = 0;

        //maxLimit = å°äºç­äºmaxValueçæå¤§ç2çnæ¬¡æ¹
        //ä¾:è¥maxValueçäºè¿å¶è¡¨ç¤ºä¸º11111,åmaxLimitä¸º10000
        //æ¾ç¶æç»çç­æ¡ä¸å®å±äº[maxLimit, maxLimit << 1)
        while (maxLimit - lowbit(maxLimit) > 0) maxLimit -= lowbit(maxLimit); 

        //ç¬¬ä¸ç§æåµ
        //a[i]+a[j]å±äº[maxLimit, maxLimit << 1),ä½a[k]ä¸å±äºè¯¥èå´
        for (int i = n - 1; i > 0; i--)
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] + a[j] < maxLimit) break;
            int sum = a[i] + a[j];
            int now = maxLimit, kl, kr, num = 0;
            //æ¾å°sumçç¬¬ä¸ä¸ª0çä½ç½®,è¯¥ä½ç½®æ»¡è¶³ä»¥ä¸æ¡ä»¶:
            //1.è®¾è¿ä¸ªä½ç½®ä¸ºpos,å³(1<<pos) & sum = 0
            //2.å­å¨a[k],(k != i && k != j),a[k]çäºè¿å¶çé¦ä½ä¹å¨posè¿ä¸ä½
            while (num == 0 && now)
            {
                while (now && (now & sum)) now >>= 1;
                kl = lower_bound(a, a + n, now) - a;
                kr = lower_bound(a, a + n, now << 1) - a;
                for (int k = kl; k < kr; k++)
                {
                    if (k != i && k != j)
                    {
                        num++;
                        break;
                    }
                }
                now >>= 1;
            }
            //ä¸å­å¨ä¸è¿°ä½ç½®çæåµ
            if (num == 0)
            {
                //æ¾å°æå°çä½ç½®ä¸k != i && k != j
                int x = 0;
                if (x == j) x++;
                if (x == i) x++;
                //å¦ææå°å¼ä¸º0
                if (a[x] == 0)
                {
                    if (sum > ans) ans = sum;
                }
                else
                {
                    //minLimit = å°äºç­äºa[x]çæå¤§ç2çnæ¬¡æ¹
                    //åæä¸¾çèå´ä¸å®å¨[minLimit, minLimit << 1)ä¹é´
                    int minLimit = a[x];
                    while (minLimit - lowbit(minLimit) > 0) minLimit -= lowbit(minLimit);
                    minLimit <<= 1;
                    for (int k = x; k < n && a[k] < minLimit; k++)
                    {
                        if (k != i && k != j && (sum ^ a[k]) > ans) ans = sum ^ a[k];
                    }
                }
            }
            else
            {
                //æä¸¾å¯»æ¾ç­æ¡
                for (int k = kl; k < kr; k++)
                {
                    if (k != i && k != j && (sum ^ a[k]) > ans) ans = sum ^ a[k];
                }
            }
        }
        
        //å¦å¤ä¸ç§æåµ
        //å³a[k]å±äº[maxLimit, maxLimit << 1),ä½a[i]+a[j]ä¸å±äºè¯¥èå´
        for (int k = n - 1; k >= 0; k--)
        {
            if (a[k] < maxLimit) break;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (k != i && k != j && (a[k] ^ (a[i] + a[j])) > ans) ans = a[k] ^ (a[i] + a[j]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}