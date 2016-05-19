/*

ç¬¬ä¸ä¸ªåºé´ï¼[1,2,...,b/k]  ç¬¬äºä¸ªåºé´ï¼[b/k+1,b/k+2,...,d/k]
è¯»ç¬¬ä¸ä¸ªåºé´æä»¬åªè¦å©ç¨æ¬§æå½æ°é·å®¶æ²¡ä¸ªæ°çè´¨å æ°çä¸ªæ°å³å¯ï¼ç¬¬äºä¸ªåºé´æä»¬ä»»åxï¼
è¦æ±[1,2,...,b/k]ä¸­ææä¸xäºè´¨çæ°çä¸ªæ°ï¼è¿éæä»¬ç¨å°å®¹æ¥åçï¼åå°xè´¨å æ°åè§£ï¼
æ±å¾[1,2,...,b/k] éææè½è¢«xçè´¨å æ°æ´é¤çæ°çä¸ªæ°ï¼ç¶åç¨b/kåå»å³å¯ã 
*/ 
#include<iostream>
#include<string.h>
#define size 100010
using namespace std;
struct Num
{
   int count;
   int prime[20];
}N[size];
__int64 elur[size];

void Elur()
{
    elur[1]=1;
    for(int i=0;i<size;i++) N[i].count=0;
    for(int i=2;i<size;i++)
    {
        if(!elur[i])    //é¦åæ±ç´ æ° 
        {
            for(int j=i;j<size;j+=i)
            {
                if(!elur[j]) elur[j]=j;
                elur[j]=elur[j]*(i-1)/i; //æ¬§æå½æ°å¬å¼ 
                N[j].prime[N[j].count]=i;
                N[j].count++;
            }
        }
        elur[i]+=elur[i-1];  //elur[i]è¡¨ç¤ºåiä¸ªæ°çè´¨å æ°çç´¯å ã
    }  
}

__int64 Inclusion_exclusion(int index , int b , int n)
{  //indexè¡¨ç¤ºæ­¤å»ç®å°åªä¸ªè´¨å æ°ï¼bè¡¨ç¤ºå¨1~bä¸­è®¡ç®è¢«è´¨å æ°æ´é¤çä¸ªæ°ï¼æç¬¬äºä¸ªåºé´çåªä¸ä¸ªæ°ã 
    __int64 r=0 , t;
    for(int i=index;i<N[n].count;i++)  //xä¸yçæå¤§å¬çº¦æ°ä¸ºk*p(pä¸ºè´¨æ°) 
    {
        t=b/N[n].prime[i];  
        r+=t-Inclusion_exclusion(i+1,t , n);  //å ä¸ºé²æ­¢ææ°è¢«éå¤è®¡ç®ï¼æä»¥æ ¹æ®å®¹æ¥å®ç 
    }
    return r;
} 
int main()
{
    int a , b, c, d , k;
    int t ,tt=0;
    Elur();
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",++tt);
            continue;
        }
        if(b>d)
        {
           b^=d;
           d^=b;
           b^=d;
        }
        b=b/k;
        d=d/k;
        ans=elur[b];
        for(int i=b+1;i<=d;i++)
        {
            ans+=b-Inclusion_exclusion(0,b,i);
        } 
        printf("Case %d: %I64d\n",++tt,ans);
    } 
    return 0;
}
