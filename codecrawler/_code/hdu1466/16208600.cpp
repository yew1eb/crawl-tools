#include<stdio.h>
#include<string.h>
int dp[21][191];
int main()
{
    int i,j,k,n;
    memset(dp,0,sizeof(dp));
    for(i=0;i<21;i++){
        dp[i][0]=1;
    }                                //åå§åï¼ä¸å®æ0ä¸ªäº¤ç¹ï¼æä»¥dp[i][0]==1
    for(i=1;i<21;i++){
        for(j=0;j<i;j++){        //jæ¡å¹³è¡çº¿ï¼å©ä¸i-jæ¡èªç±çº¿
            for(k=0;k<191;k++){          //i-jæ¡èªç±çº¿æ¯å¦ækä¸ªäº¤ç¹çäº¤æ³ï¼æåiæ¡ç´çº¿å°±å¯ä»¥å¤ä¸ç§äº¤æ³
                if(dp[i-j][k]==1){
                    dp[i][(i-j)*j+k]=1;
                }
            }
        }
    }
    while(scanf("%d",&n)!=EOF){
        printf("0");
        for(i=1;i<191;i++){
            if(dp[n][i]==1){
                printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}