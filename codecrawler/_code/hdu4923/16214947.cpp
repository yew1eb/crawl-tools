#include<cstdio>
const int N = 100010;
int sum[N], seg[N];
typedef __int64 LL;
bool Check_Biger(int a1, int b1, int a2, int b2)
{
    return (LL)(sum[b1] - sum[a1 - 1]) * (b2 - a2 + 1) >=
           (LL)(sum[b2] - sum[a2 - 1]) * (b1 - a1 + 1);
}
int main()
{
    int T, n, i, a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum[0] = 0; //sum[i]è¡¨ç¤ºä»A1å°Aiä¸å±æå¤å°ä¸ª1
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&a);
            sum[i] = sum[i-1] + a;
        }
        int length = 0, id;
        for(i = 1; i <= n; i++)
        {
            id = i;
            while(length > 0 && Check_Biger(seg[length], id-1, id, i))
            {  //å¦æåé¢ä¸æ®µçå¹³åå¼ä¸å°äºåé¢çå¹³åå¼ï¼ååå¹¶è¿ä¸¤æ®µ
                id = seg[length--];
            }
            seg[++length] = id;
        }
        seg[++length] = n + 1;
        double ans = 0;
        for(i = 1; i < length; i++)
        {
            int l = seg[i]; //å½åæ®µçå·¦ç«¯ç¹
            int r = seg[i+1] - 1; //å½åæ®µçå³ç«¯ç¹
            int len = r - l + 1; //å½åæ®µçé¿åº¦
            double x = (double(sum[r]) - sum[l-1]) / len; //å½åæ®µæ¯ä¸ä¸ªåç´ é½åè¿ä¸æ®µçå¹³åå¼
            ans += sum[r] - sum[l-1] + len * x * x - 2 * (sum[r] - sum[l-1]) * x;   //(Ai - x)^2
        }
        printf("%lf\n", ans);
    }
    return 0;
}