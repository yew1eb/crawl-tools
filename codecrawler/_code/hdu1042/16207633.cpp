#include <stdio.h>
#include <string.h>

int num[8000];       //ä»£è¡¨äºæç»ç»æçæå¤§é¿åº¦ä¸º8000*5(numä¸­æ¯ä½å®ä¹çä½æ°)

int main()
{
    int n;
    int i,j,t,y;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        memset(num,0,sizeof(num));
        num[1]=1;
        t=1;
        for(i=2;i<=n;i++)                //æ ¸å¿é¨åï¼numæ°ç»çææä½æ°è¡¨ç¤ºå½åè®¡ç®åºçç»æ
        {
            y=0;
            for(j=1;j<=t;j++)
            {
                num[j]=num[j]*i+y;
                y=num[j]/100000;
                num[j]%=100000;
            }
            while(y)                     //æä½è¿ä½
            {
                num[++t]=y%100000;
                y/=100000;
            }
        }
        printf("%d",num[t]);
        for(i=t-1;i>=1;i--)
            printf("%05d",num[i]);        //æ ¼å¼åè¾åºï¼æ¯ä¸ä¸ªnumä»£è¡¨äºç»æä¸­ç5ä½æ°
        printf("\n");
    }
    return 0;
}