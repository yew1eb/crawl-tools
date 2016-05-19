#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
LL t,e[1000];
LL mod;
LL euler_phi(LL n)//æ¬§æå½æ°
{
    LL m=sqrt(n+0.5);
    LL ans=n,i;
    for(i=2;i<=m;i++)
    {
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0)n=n/i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
void find(LL n)
{
    LL i;
    e[t++]=n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i==n)
                e[t++]=i;
            else
            {
                e[t++]=i;
                e[t++]=n/i;
            }
        }
    }
}
LL pows(LL a,LL b)
{
    LL s=1;
    while(b)
    {
        if(b&1)
            s=(s*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return s;
}
int main()
{
    LL n;
    while(cin>>n)
    {
        if(n%2==0||n==1)
            cout<<"2^? mod "<<n<<" = 1"<<endl;
        else
        {
            LL m,ans,i,s=2;
            /*for(i=2;;i++)//ç´æ¥æ´åçæ¹æ³
            {
                s=(s*2)%n;
                if(s==1)
                    break;
            }
            ans=i;*/
            m=euler_phi(n);
            t=0;
            find(m);
            sort(e,e+t);
            mod=n;
            for(i=0;i<t;i++)
            {
                if(pows(2,e[i])==1)
                {
                    ans=e[i];
                    break;
                }
            }
            cout<<"2^"<<ans<<" mod "<<n<<" = 1"<<endl;
        }
    }
    return 0;
}
/*
    è¿é¢æ°æ®å¾æ°´ï¼å¯ä»¥ç´æ¥æ´ååºæ¥ã
    æè¦è®²çä½¿ç¨å®çæ±è§£è¿éé¢ï¼
    æ¬é¢å¾å®¹æåç°nä¸ºå¶æ°æè0æ¶æ è§£ãæä»¥2ånå¿å®äºè´¨
    æ¬§æå®ç:a^(euler_phi(n))â¡1(mod n),(a,näºè´¨)
    å¶ä¸­euler_phiä¸ºæ¬§æå½æ°ï¼è®¡ç®ä¸è¶è¿nä¸ä¸näºè´¨çä¸ªæ°ãæ±æ³æ¯n*â(pi-1)/pi,piä¸ºnçè´¨å å­
    
    m=euler_phi(n);
    æä»¥a^m%mod=1,ä¸è¿mä¸ä¸å®æ¯æå°å¾ªç¯ï¼ä½mæ¯ä¸ä¸ªå¾ªç¯ï¼åæå°å¾ªç¯ä¸å®æ¶mçä¸ä¸ªå å­ï¼å èæ¾åºææmçå å­ï¼æ´å
    æç´¢ä¸å°±OKäº
*/