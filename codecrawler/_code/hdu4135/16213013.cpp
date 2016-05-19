#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long 
#define maxn 70

LL prime[maxn];
LL make_ans(LL num,int m)//1å°numä¸­çæææ°ä¸mä¸ªè´¨å å­ä¸äºè´¨çä¸ªæ° æ³¨ææ¯ä¸äºè´¨å¦
{
    LL ans=0,tmp,i,j,flag;
    for(i=1;i<(LL)(1<<m);i++)
    { //ç¨äºè¿å¶æ¥1,0æ¥è¡¨ç¤ºç¬¬å ä¸ªç´ å å­æ¯å¦è¢«ç¨å°,å¦m=3ï¼ä¸ä¸ªå å­æ¯2,3,5ï¼åi=3æ¶äºè¿å¶æ¯011ï¼è¡¨ç¤ºç¬¬2ã3ä¸ªå å­è¢«ç¨å° 
        tmp=1,flag=0;
        for(j=0;j<m;j++) 
            if(i&((LL)(1<<j)))//å¤æ­ç¬¬å ä¸ªå å­ç®åè¢«ç¨å°
                flag++,tmp*=prime[j];
        if(flag&1)//å®¹æ¥åçï¼å¥å å¶å 
            ans+=num/tmp;
        else
            ans-=num/tmp;
    }
    return ans;
}

int main()
{
    int T,t=0,m;
    LL n,a,b,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&n);
        m=0;
        for(i=2;i*i<=n;i++) //å¯¹nè¿è¡ç´ å å­åè§£ 
            if(n&&n%i==0)
            {
                prime[m++]=i;
                while(n&&n%i==0)
                    n/=i;
            }    
        if(n>1)
            prime[m++]=n;
        printf("Case #%d: %I64d\n",++t,(b-make_ans(b,m))-(a-1-make_ans(a-1,m)));
    }
    return 0;
}