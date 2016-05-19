#include<stdio.h>
int a[10],b[10];
bool check()
{
    for(int i=0;i<4;i++)
    {
        int j;
        for(j=0;j<4;j++)if(a[(i+j)%4]!=b[j])break;
        if(j==4)return 1;
    }
    return 0;
}
int main()
{
    int casenum,casei;
    scanf("%d",&casenum);
    for(int casei=1;casei<=casenum;casei++)
    {
        for(int i=0;i<=1;i++)scanf("%d",&a[i]);
        for(int i=3;i>=2;i--)scanf("%d",&a[i]);
        for(int i=0;i<=1;i++)scanf("%d",&b[i]);
        for(int i=3;i>=2;i--)scanf("%d",&b[i]);
        printf("Case #%d: %s\n",casei,check()?"POSSIBLE":"IMPOSSIBLE");
    }
    return 0;
}
/*
ãé¢æã
ç»ä½ ä¸¤ä¸ª2*2çç©å½¢ï¼æ¯ä¸ªæ ¼å­ä»£è¡¨ä¸ä¸ªæ°ã
é®ä½ è¿ä¸¤ä¸ªç©å½¢æ¯å¦å¯ä»¥éè¿ä¸ä¸ªåæè½¬å¾å°å¦å¤ä¸ä¸ª

ãç±»åã
æè½¬æ³oræ´åifæ³

ãåæã
è¿é¢å¯ä»¥ç¨æ°ç»æè½¬åã
å¶å®ç¨ifå¤å®ä¹å¹¶ä¸éº»ç¦ã
ä½æ¯è¦æ¯ä¸ºäºä»£ç æ¸æ°åº¦ï¼è¿æ¯æ°ç»æè½¬æ´å¥½

*/