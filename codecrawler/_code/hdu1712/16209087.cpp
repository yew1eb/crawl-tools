#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max(a,b) a>b? a:b
#define NN 10010
int mat[105][105];
int dp[NN];
int n,m;
int main()
{
    int i,j,v;
    while(scanf("%d%d",&n,&m),n+m){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        for(i=1;i<=n;i++){            //åç»
            for(v = m ;v >= 1;v--){    //èåå®¹é
                for(j = 1 ;j<=m;j++){//ä¸åæ¶é´çè¯¾ç¨
                    if(v>=j)
                        dp[v] = Max(dp[v] ,dp[v-j]+mat[i][j]);
                }
            }
        }
        printf("%d\n",dp[m]);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}

