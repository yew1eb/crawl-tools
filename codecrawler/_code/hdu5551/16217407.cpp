#include<stdio.h> 
int casenum,casei;
int main()
{
    scanf("%d",&casenum);
    for(casei=1;casei<=casenum;casei++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",casei,2*n-1);
    }
}
/*
ãtrick&&åæ§½ã
åé¢è¦çACæ°ã
ä¸æ¹é¢ä¸è¦å¼æ³å¤©å¼ã
å¦å¤ä¸æ¹é¢è¦å¤§èã

ãé¢æã
ææç§ç±»çè¯ç½é½ä¸æ ·ï¼èä¸æ°éé½ä¸ºæ éä¸ªã
ç°å¨å¯ä»¥æä¸æ¡ç»³æå®ä»¬ä¸²æä¸ä¸ªä¸²ã
é®ä½ è³å°è¦å¤å°ä¸ªè¯ç½ï¼æè½ç¥éæ¯ä¸ªæ¯ä»ä¹æ å·ã

ãç±»åã
æ°´é¢ çæ³

ãåæã
å¦ä½ç¥éæ¹åçæ­£åï¼
è¿æ¯å»ä¾èµå¯¹ç§°æ§å§ã
äºæ¯ç­æ¡æ¯2n-1

*/