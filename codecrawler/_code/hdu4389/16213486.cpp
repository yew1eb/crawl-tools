#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int bit[10];
int dp[10][82][82][82];
//d[l][i][j][k]è¡¨ç¤ºålä½åä¸ºiæ¨¡jçç»æä¸ºkçæ°çä¸ªæ°
void set()
{
    int i,j,k,l,x;
    for(i = 1; i<=81; i++)
        dp[0][0][i][0] = 1;
    for(l = 0; l<9; l++)
        for(i = 0; i<=l*9; i++)
            for(j = 1; j<=81; j++)
                for(k = 0; k<j; k++)
                    for(x = 0; x<=9; x++)
                        dp[l+1][i+x][j][(k*10+x)%j] += dp[l][i][j][k];
}

int solve(int n)
{
    if(!n)
        return 0;
    int ans,i,j,k,len;
    int sum,tem1,tem2,s,bit[10],r;
    len = sum = ans = 0;
    tem1 = tem2 = n;
    s = 1;
    while(tem1)
    {
        bit[++len] = tem1%10;
        tem1/=10;
        sum+=bit[len];//æ¯ä½æ°ä¹å
    }
    if(n%sum==0)//æ¬èº«è¦åçæ¯å¦æ´é¤
        ans++;
    for(i = 1; i<=len; i++)
    {
        sum-=bit[i];//å°è¯¥ä½æ¸0
        tem2/=10;
        s*=10;
        tem1 = tem2*s;
        for(j = 0; j<bit[i]; j++) //æä¸¾è¯¥ä½çç¶åµ
        {
            for(k = sum+j; k<=sum+j+9*(i-1); k++) //è¯¥ä½ä¸æ´é«ä½çåï¼èæ¯è¯¥ä½ä½çåæ©ä¼9*(i-1)ç§
            {
                if(!k)//åä¸º0çç¶åµä¸ç¬¦å
                    continue;
                r = tem1%k;//ç°å¨è¯¥æ°å¯¹åä½åè¿è¡åä½
                if(r)
                    r = k-r;//ä½æ°å¤§äº0ï¼é£ä¹k-ddå¾å°çæ°è¯å®è½è¢«tæ´é¤
                ans+=dp[i-1][k-sum-j][k][r];//å ä¸ä¸ªæ°
            }
            tem1+=s/10;//æ è®°ç°å¨ç®å°åªéï¼ä¾å¦1234ï¼ä¸å¼å§tæ¯1230ï¼ç¶å1231,1232,1233,1234ï¼æ¥ä¸æ¥1200ï¼å°±æ¯1210ï¼1220,1230
        }
    }
    return ans;
}

int main()
{
    int T,l,r,cas = 1;
    set();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&r);
        printf("Case %d: %d\n",cas++,solve(r)-solve(l-1));
    }

    return 0;
}
