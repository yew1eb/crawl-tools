/*
 * Author: Gatevin
 * Created Time:  2015/11/28 19:01:07
 * File Name: Yukinoshita_Yukino.cpp
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

/*
 * ç¨dp[i][j][a][b]è¡¨ç¤ºå½åè¿è¡äºiæ¬¡åæ¢, *åºç°å¨jä½ç½®, ç¬¬aä½ç½®ä¸ç¬¬bä½ç½®ä¸çæ°å¯è½ä¹ç§¯çå
 * åå§ådp[0][center][a][b] = s[a]*s[b], centeræ¯*å¼å§çä½ç½®, å½aæèbä¸centerç¸åæ¶è§ä¸º0
 * è½¬ç§»æ¶, èèdp[i][j][a][b]:
 * å½j, a, bäºä¸ç¸åæ¶
 * dp[i][j][a][b] =     dp[i - 1][j][a][b]*C[n - 3][2] //åj, a, bä»¥å¤çä½ç½®äº¤æ¢
 *                  +   dp[i - 1][j][a][b]             //åä½ç½®a, bäº¤æ¢
 *                  + âdp[i - 1][j][a][x]             //åä½ç½®x, bäº¤æ¢, x != b && x != a && x != j
 *                  + âdp[i - 1][j][x][b]             //åä½ç½®x, aäº¤æ¢, x != a && x != b && x != j
 *                  + âdp[i - 1][k][a][b]             //åä½ç½®k, jäº¤æ¢, k != j && k != a && k != b
 *                  +   dp[i - 1][a][j][b]             //åä½ç½®a, jäº¤æ¢
 *                  +   dp[i - 1][b][a][j]             //åä½ç½®b, jäº¤æ¢
 * å½j == aæ¶
 * dp[i][j][j][b] =     dp[i - 1][j][j][b]*C[n - 2][2] //åä½ç½®j, bä»¥å¤çä½ç½®äº¤æ¢
 *                  + âdp[i - 1][j][j][x]             //åä½ç½®xä¸bäº¤æ¢ x != b && x != j
 *                  + âdp[i - 1][x][x][b]             //åä½ç½®xä¸jäº¤æ¢ x != b && x != j
 *                  +   dp[i - 1][b][b][j]             //åä½ç½®bä¸jäº¤æ¢ b != j
 * å½j == bæ¶åj == aç±»ä¼¼åªæ¯bæ¢æaèå·²
 * å¨æ±åºdp[K][1~n][1~n][1~n]ä¹åæ ¹æ®ä¹å·çä½ç½®å¤æ­åçæ§å°±å¯ä»¥è®¡ç®æåçç­æ¡
 * ç¶åç±äºç´æ¥è®¡ç®æ¶O(Kn^4), èèå°å¯ä»¥ä½¿ç¨åç¼åç»´æ¤, æ¶é´å¤æåº¦éä½å°O(Kn^3)
 */

const lint mod = 1e9 + 7;
const int MOD = 1e9 + 7;
char s[100];
int K, n;
int dp[55][55][55][55];
int sum[55][55][55][3];//sumæåä¸ç»´ç0, 1, 2åå«è¡¨ç¤ºä¸ç§ä¸åçåç¼å
int S[55][55][2];//Sæåä¸ç»´ç2ä¹æ¯åç¼å
//åæ¬sumåSæ°ç»é½æ¯è¦åå¤ä¸ç»´55ç, ç±äºåå­éå¶ä»¥åé£ä¸ç»´åªéè¦ä½¿ç¨nå°±çå»äº

lint C[55][55];
lint ten[55];

void Add(int& x, int val)
{
    x += val;
    if(x >= MOD) x -= MOD;
}

int Mod(int x)
{
    if(x >= MOD) return x - MOD;
    return x;
}

void init()
{
    C[0][0] = 1;
    for(int i = 1; i <= 50; i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if(C[i][j] >= mod) C[i][j] -= mod;
        }
    }
    
    ten[0] = 1;
    for(int i = 1; i < 55; i++)
        ten[i] = ten[i - 1]*10LL % mod;
}

int main()
{
    int T;
    scanf("%d", &T);
    init();
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &K);
        scanf("%s", s + 1);
        n = strlen(s + 1);
        if(n == 1 && s[1] == '*')//s = "*"
        {
            printf("Case #%d: 0\n", cas);
            continue;
        }
        //memset(dp, 0, sizeof(dp));
        //memset(sum, 0, sizeof(sum));
        for(int i = 0; i <= n; i++)
        {
            memset(dp[i], 0, sizeof(dp[i]));
            memset(sum[i], 0, sizeof(sum[i]));
            memset(S[i], 0, sizeof(S[i]));
        }
        
        int center = -1;
        for(int i = 1; i <= n; i++)
            if(s[i] == '*')
            {
                center = i;
                s[i] = '0';
                break;
            }
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
            {
                dp[0][center][i][j] += (s[i] - '0')*(s[j] - '0');
                dp[0][center][j][i] += (s[i] - '0')*(s[j] - '0');
            }
        for(int j = 1; j <= n; j++)
            for(int a = 1; a <= n; a++)
                for(int b = 1; b <= n; b++)
                    //sum[0][j][a][b][2] = sum[0][j][a][b - 1][2] + dp[0][j][a][b];
                    sum[0][j][a][2] += dp[0][j][a][b];
        
        for(int j = 1; j <= n; j++)
            for(int b = 1; b <= n; b++)
                for(int a = 1; a <= n; a++)
                    //sum[0][j][a][b][1] = sum[0][j][a - 1][b][1] + dp[0][j][a][b];
                    sum[0][j][b][1] += dp[0][j][a][b];
        
        for(int a = 1; a <= n; a++)
            for(int b = 1; b <= n; b++)
                for(int j = 1; j <= n; j++)
                    //sum[0][j][a][b][0] = sum[0][j - 1][a][b][0] + dp[0][j][a][b];
                    sum[0][a][b][0] += dp[0][j][a][b];
        
        for(int b = 1; b <= n; b++)
            for(int j = 1; j <= n; j++)
                //sum[0][j][j][b][3] = sum[0][j - 1][j - 1][b][3] + dp[0][j][j][b];
                S[0][b][0] = S[0][b][0] + dp[0][j][j][b];
        for(int a = 1; a <= n; a++)
            for(int j = 1; j <= n; j++)
                //sum[0][j][a][j][4] = sum[0][j - 1][a][j - 1][4] + dp[0][j][a][j];
                S[0][a][1] = S[0][a][1] + dp[0][j][a][j];
        
        
        for(int i = 1; i <= K; i++)
            for(int j = 1; j <= n; j++)
            {
                for(int a = 1; a <= n; a++)
                    for(int b = 1; b <= n; b++)
                    {
                        if(j != a && j != b && a != b)
                        {
                            Add(dp[i][j][a][b], (int)(dp[i - 1][j][a][b]*C[n - 3][2] % mod));
                            Add(dp[i][j][a][b], dp[i - 1][j][a][b]);
                            
                            //Add(dp[i][j][a][b], dp[i - 1][j][a][x]);//x != j, a, b
                            Add(dp[i][j][a][b], (int)(((lint)sum[i - 1][j][a][2] - dp[i - 1][j][a][a] - dp[i - 1][j][a][b] - dp[i - 1][j][a][j] + 3LL*mod) % mod));
                            
                            //Add(dp[i][j][a][b], dp[i - 1][j][x][b]);//x != j, a, b
                            Add(dp[i][j][a][b], (int)(((lint)sum[i - 1][j][b][1] - dp[i - 1][j][j][b] - dp[i - 1][j][a][b] - dp[i - 1][j][b][b] + 3*mod) % mod));
                            
                            //Add(dp[i][j][a][b], dp[i - 1][k][a][b]);//k != j, a, b
                            Add(dp[i][j][a][b], (int)(((lint)sum[i - 1][a][b][0] - dp[i - 1][j][a][b] - dp[i - 1][a][a][b] - dp[i - 1][b][a][b] + 3*mod) % mod));
                            
                            Add(dp[i][j][a][b], dp[i - 1][a][j][b]);
                            Add(dp[i][j][a][b], dp[i - 1][b][j][a]);
                        }
                        if(j == a && a != b)
                        {
                            Add(dp[i][j][j][b], (int)(dp[i - 1][j][j][b]*C[n - 2][2] % mod));
                            
                            //Add(dp[i][j][j][b], dp[i - 1][j][j][x]); // x != b && x != j
                            Add(dp[i][j][j][b], (int)(((lint)sum[i - 1][j][j][2] - dp[i - 1][j][j][b] - dp[i - 1][j][j][j] + 2*mod) % mod));
                            
                            //Add(dp[i][j][j][b], dp[i - 1][x][x][b]); // x != b && x != j
                            Add(dp[i][j][j][b], (int)(((lint)S[i - 1][b][0] - dp[i - 1][b][b][b] - dp[i - 1][j][j][b] + 2*mod) % mod));
                            
                            Add(dp[i][j][j][b], dp[i - 1][b][b][j]);
                        }
                        if(j == b && a != b)
                        {
                            Add(dp[i][j][a][j], (int)(dp[i - 1][j][a][j]*C[n - 2][2] % mod));
                            
                            //Add(dp[i][j][a][j], dp[i - 1][j][x][j]); // x != b && x != j
                            Add(dp[i][j][a][j], (int)(((lint)sum[i - 1][j][j][1] - dp[i - 1][j][b][j] - dp[i - 1][j][j][j] + 2*mod) % mod));
                            
                            //Add(dp[i][j][a][j], dp[i - 1][x][a][x]); // x != b && x != j
                            Add(dp[i][j][a][j], (int)(((lint)S[i - 1][a][1] - dp[i - 1][b][a][b] - dp[i - 1][j][a][j] + 2*mod) % mod));
                            
                            Add(dp[i][j][a][j], dp[i - 1][a][j][a]);
                        }
                        /*
                        sum[i][j][a][b][2] = Mod(sum[i][j][a][b - 1][2] + dp[i][j][a][b]);
                        sum[i][j][a][b][1] = Mod(sum[i][j][a - 1][b][1] + dp[i][j][a][b]);
                        sum[i][j][a][b][0] = Mod(sum[i][j - 1][a][b][0] + dp[i][j][a][b]);
                        */
                        sum[i][j][a][2] = Mod(sum[i][j][a][2] + dp[i][j][a][b]);
                        sum[i][j][b][1] = Mod(sum[i][j][b][1] + dp[i][j][a][b]);
                        sum[i][a][b][0] = Mod(sum[i][a][b][0] + dp[i][j][a][b]);
                        if(j == a) //sum[i][j][j][b][3] = Mod(sum[i][j - 1][j - 1][b][3] + dp[i][j][j][b]);
                            S[i][b][0] = Mod(S[i][b][0] + dp[i][j][j][b]);
                        if(j == b) //sum[i][j][a][j][4] = Mod(sum[i][j - 1][a][j - 1][4] + dp[i][j][a][j]);
                            S[i][a][1] = Mod(S[i][a][1] + dp[i][j][a][j]);
                    }
            }
        int ans = 0;
        for(int cen = 1; cen <= n; cen++)
            for(int a = 1; a < cen; a++)
                for(int b = cen + 1; b <= n; b++)
                {
                    Add(ans, (int)(dp[K][cen][a][b]*ten[cen - a - 1 + n - b] % mod));
                }
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}
