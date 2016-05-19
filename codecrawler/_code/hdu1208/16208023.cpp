#include"stdio.h"
#include"string.h"
typedef __int64 int64;
#define min(x,y) x>y?y:x;
int64 dp[35][35];
char map[35][35];
int main()
{
    int i,j,n,t;
    while(scanf("%d",&n)!=-1,n!=-1)
    {
        getchar();
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            gets(map[i]);
        dp[0][0]=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(map[i][j]-'0')///è¿éè¦å¤æ­ä¸ä¸å¦åä¼å¤å 
                {
                    t=map[i][j]-'0'+i;    
                    if(t<n)
                        dp[t][j]+=dp[i][j];
                    
                    t=map[i][j]-'0'+j;
                    if(t<n)
                        dp[i][t]+=dp[i][j];
                }
            }
        }
        printf("%I64d\n",dp[n-1][n-1]);
    }
    return 0;
}