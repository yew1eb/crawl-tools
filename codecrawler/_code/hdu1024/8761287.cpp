/*
×´Ì¬dp[i][j]ÓÐÇ°j¸öÊý£¬×é³Éi×éµÄºÍµÄ×î´óÖµ¡£¾ö²ß£º
µÚj¸öÊý£¬ÊÇÔÚµÚ°üº¬ÔÚµÚi×éÀïÃæ£¬»¹ÊÇ×Ô¼º¶ÀÁ¢³É×é¡£
·½³Ì dp[i][j]=Max(dp[i][j-1]+a[j] , max( dp[i-1][k] ) + a[j] ) 0<k<j
¿Õ¼ä¸´ÔÓ¶È£¬mÎ´Öª£¬n<=1000000£¬  ¼ÌÐø¹ö¶¯Êý×é¡£
Ê±¼ä¸´ÔÓ¶È n^3. n<=1000000.  ÏÔÈ»»á³¬Ê±£¬¼ÌÐøÓÅ»¯¡£
max( dp[i-1][k] ) ¾ÍÊÇÉÏÒ»×é 0....j-1 µÄ×î´óÖµ¡£
ÎÒÃÇ¿ÉÒÔÔÚÃ¿´Î¼ÆËãdp[i][j]µÄÊ±ºò¼ÇÂ¼ÏÂÇ°j¸öµÄ×î´óÖµ
ÓÃÊý×é±£´æÏÂÀ´  ÏÂ´Î¼ÆËãµÄÊ±ºò¿ÉÒÔÓÃ£¬ÕâÑùÊ±¼ä¸´ÔÓ¶ÈÎª n^2.
*/

#include <stdio.h>
#include <string.h>
#define INF 0x7fffffff
#define MAXN 1000000
#define max(a,b) ((a)>(b)?(a):(b))
int dp[MAXN + 10];
int upper[MAXN + 10];
int a[MAXN + 10];

int main()
{
    int n, m;
    int i, j, maxx;
    while (~scanf("%d%d", &m, &n)) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        memset(dp,0,(n+1)*sizeof(dp[0]));
        memset(upper,0,(n+1)*sizeof(upper[0]));
        for (i = 1; i <= m; i++) {
            maxx = -INF;
            for (j = i; j <= n; j++) {
                dp[j] = max(dp[j - 1] + a[j], upper[j - 1] + a[j]);
                upper[j - 1] = maxx;
                maxx = max(maxx, dp[j]);
            }
        }
        printf("%d\n", maxx);
    }
    return 0;
}
