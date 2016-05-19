#include<stdio.h>
int dp[110][110][2];//d[i][j][k]è¡¨ç¤ºé¿åº¦ä¸ºiçä¸²,æå¼ä¸ºjæ¶,ä»¥k=(1 or 0)ä¸ºå°¾æ¶çæ¹æ³æ° 
int main(){
    int t,l,p,cas;
    dp[1][0][0]=dp[1][0][1]=1;
    for(int i=2;i<=100;i++){
        dp[i][0][0]=dp[i-1][0][0]+dp[i-1][0][1];
        dp[i][0][1]=dp[i-1][0][0];
        for(int j=1;j<i;j++){
            dp[i][j][0]=dp[i-1][j][1]+dp[i-1][j][0];
            dp[i][j][1]=dp[i-1][j-1][1]+dp[i-1][j][0];
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&cas,&l,&p);
        printf("%d %d\n",cas,dp[l][p][0]+dp[l][p][1]);
        
    }
    return 0;
}