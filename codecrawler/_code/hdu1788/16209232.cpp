/*N % MI = MI - a  
åå¼ç­ä»·äº (N + a) % MI = 0 
æä»¥æ­¤é¢ä¸ºæ± M0 å° MI çæå°å¬åæ°    
(æ³¨æç²¾åº¦é®é¢,ç¨__int64) 
ä¸å¼å§ ææè¿é¢ç´æ¥å¥ä¸­å½å©ä½å®çå»åäº æ ·ä¾ä¹è¿äº ä½æ¯WA  ç¶åä¸ç´å°æäºè¿ç¹
å¶å®è¿ä¸ªé¢åä¸­å½å©ä½å®çä¸æ²¾è¾¹   æ¬è´¨å¶å®æ¯ä¸ä¸ªæ±æå°å¬åæ°
*/
#include<stdio.h>
__int64 gcd(__int64 a,__int64 b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    __int64 n,i,k,ans,num;
    while(scanf("%I64d %I64d",&n,&k)!=EOF)
    {
        ans=1;
        if(!n&&!k) break;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&num);
            ans=ans/gcd(ans,num)*num;
        }
        printf("%I64d\n",ans-k);
    }
    return 0;
}

