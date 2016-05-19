/*åè®¾1--N-1ä¸ªç¯®å­éçéå¸ä¸æ ·é,weight=w*(1+n-1)*(n-1)/2
åå»å·²ç¥çééW,(weight-W)/då¾éå¸æ°éå³ç¯®å­ç¼å·*/
#include <stdio.h>

int main()
{
    int n,w,d,W,ans;
    while(scanf("%d %d %d %d",&n,&w,&d,&W)!=EOF)
    {
        ans=(w*n*(n-1)/2-W)/d;
        if(ans>0)
            printf("%d\n",ans);
        else
            printf("%d\n",n);
    }
    return 0;
}