#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std; 
int  s[101];
int tt[10001];
 
int g(int x , int  k)
{
    int mex[101];
    memset(mex,0,sizeof(mex));
    if(tt[x]!=-1) return tt[x]; //éåSä¸è´ï¼åæ¯ä¸ªæ°éçmexä¸æ ·ï¼æä»¥å¯ä»¥éå¤å©ç¨ 
    if(x-s[0]<0) return tt[x]=0; //s[0]ä¸ºéåä¸­æå°å¼ï¼x-s[0]<0,åxä¸å¯è½å°è¾¾å¶ä»ç¶æï¼ä¸å®ä¸ºP 
    for(int i=0;i<k && x-s[i]>=0;i++) //å¤æ­æ¡ä»¶ï¼å ä¸ºs[]æäºåºï¼å½x-s[i]<0å°±åæ­¢å¾ªç¯ã 
    { 
        mex[g(x-s[i] , k)]=1; //xçåç»§SGå½æ°ä¸­çæ²¡æåºç°çæå°éè´æ° 
    }
    for(int i=0;;i++) //éè¿xçåç»§SGå½æ°åºç°çéè´æ°å¾xçç»æ 
    if(!mex[i])  return tt[x]=i;
}

int main()
{
    int  k ;
    int n, t ,a , ans;
    while(scanf("%d",&k)!=EOF && k)
    {
        memset(tt,-1,sizeof(tt));
        tt[0]=0;
        for(int i=0;i<k;i++) scanf("%d",&s[i]);
        sort(s,s+k);
        scanf("%d",&t); 
        while(t--)
        {
            ans=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++) 
            {
                scanf("%d",&a);  
                ans^=g(a , k);
            }  
           // for(int i=0;i<=12; i++) cout<<i<<"   ";cout<<endl;
            //for(int i=0;i<=12;i++) cout<<tt[i]<<" ";cout<<endl;
            if(!ans)  printf("L"); //å¼æsumï¼=0ï¼è¯´æè¯¥ç¹ä¸ºå¿è´¥ç¹ï¼åªè½å°è¾¾å¿èç¹ã 
            else printf("W");
        }
        printf("\n");
    }
    return 0;
} 
/*
(0,1,1) çå¼æsum=0ï¼ä¸ºå¿è´¥ç¹.
På¿è´¥ç¹æ¯æååè¿ç³å¤´çäººè·èï¼å¿è´¥ç¹æ è®ºæä¹ç§»å¨é½åªè½å°è¾¾å¿èç¹ã 
*/ 
