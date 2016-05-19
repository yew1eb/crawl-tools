#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const LL maxn=20;
//æå±æ¬§å éå¾å®çï¼æ±ax+by=gcd(a,b)çä¸ç»è§£(x,y),d=gcd(a,b)
void gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}
LL china(LL n,LL a[],LL b[])
{
    LL m1,r1,m2,r2,flag=0,i,d,x,y,c,t;
    m1=a[0],r1=b[0];
    flag=0;
    for(i=1;i<n;i++)
    {
        m2=a[i],r2=b[i];
        if(flag)continue;
        gcd(m1,m2,d,x,y);//d=gcd(m1,m2);x*m1+y*m2=d;
        c=r2-r1;
        if(c%d)//å¯¹äºæ¹ç¨m1*x+m2*y=cï¼å¦æcä¸æ¯dçåæ°å°±æ æ´æ°è§£
        {
            flag=1;
            continue;
        }
        t=m2/d;//å¯¹äºæ¹ç¨m1x+m2y=c=r2-r1,è¥(x0,y0)æ¯ä¸ç»æ´æ°è§£,é£ä¹(x0+k*m2/d,y0-k*m1/d)ä¹æ¯ä¸ç»æ´æ°è§£(kä¸ºä»»ææ´æ°)
                //å¶ä¸­x0=x*c/d,y0=x*c/d;
        x=(c/d*x%t+t)%t;//ä¿è¯x0æ¯æ­£æ°ï¼å ä¸ºx+k*tæ¯è§£ï¼(x%t+t)%tä¹å¿å®æ¯æ­£æ°è§£(å¿å®å­å¨æä¸ªkä½¿å¾(x%t+t)%t=x+k*t)
        r1=m1*x+r1;//æ°æ±çr1å°±æ¯åiç»çè§£ï¼Mi=m1*x+M(i-1)=r2-m2*y(m1ä¸ºåiä¸ªmçæå°å¬åæ°);å¯¹m2åä½æ¶ï¼ä½æ°ä¸ºr2ï¼
                    //å¯¹ä»¥åçmåä½æ¶ï¼Mi%m=m1*x%m+M(i-1)%m=M(i-1)%m=r
        m1=m1*m2/d;
    }
    if(flag)return -1;
    if(n==1&&r1==0)return m1;//ç»æä¸è½ä¸º0
    return r1;
}

int main()
{
    LL T,i,n,tt=0;
    LL a[maxn],b[maxn];
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        cout<<"Case "<<++tt<<": "<<china(n,a,b)<<endl;
    }
    return 0;
}
/*
    ä¸­å½å©ä½å®ç(ä¸äºè´¨å½¢å¼)æ¨¡æ¿é¢ã
    æ³¨æåªæä¸ç»ä¸å©ä½æ°ä¸º0çæ¶åãç»æä¸è½ä¸º0
*/