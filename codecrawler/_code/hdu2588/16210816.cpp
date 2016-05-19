#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000;
int e[maxn];
int euler_phi(int n)
{
    int m=(int)sqrt(n+0.5);
    int ans=n,i;
    for(i=2;i<=m;i++)
    {
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
int main()
{
    int T,n,m;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        int i,j,k,t=0,num,ans=0;
        num=(int)sqrt(n+0.5);
        for(i=1;i<num;i++)
        {
            if(n%i==0)
            {
                if(i>=m)e[t++]=n/i;
                if(n/i>=m)e[t++]=i;
            }
        }
        if(num*num==n&&num>=m)e[t++]=num;
        for(i=0;i<t;i++)
            ans+=euler_phi(e[i]);
        cout<<ans<<endl;
    }
    return 0;
}
/*
    é¢æï¼æ±æå¤å°x(1<=x<=n),ä½¿å¾gcd(x,n)>=m;
    åæ±nçææå¤§äºç­äºmçå å­,ei
    ç­æ¡ans=âphi[n/ei];phi[i]ä¸ºæ¬§æå½æ°ï¼ä¸ºä¸å¤§äºiä¸ä¸iäºè´¨çæ­£æ´æ°ä¸ªæ°
    why?
    å¯¹äºä¸ä¸ªä¸eiäºè´¨ä¸å°äºç­äºn/eiçæ­£æ´æ°pæ¥è¯´ï¼p*ei<=n,gcd(p*ei,n)=ei;
åphi[n/ei]å°±æ¯1~nä¸­çä¸næå¤§å¬çº¦æ°æ¯eiçä¸ªæ°ãènä¸1~nçæå¤§å¬çº¦æ°å¿å®æ¯nçå å­ã
æä»¥ç¬¦ågcd(x,n)>=mçxä¸ºnææå¤§äºç­äºmå å­çåæ°ï¼ç¨phiå³å¯é¿åéå¤ã
*/
