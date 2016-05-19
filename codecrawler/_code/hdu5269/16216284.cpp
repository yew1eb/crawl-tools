#include <iostream>
#include<algorithm>
#include <bitset>
#include<string>
#include<math.h>
#include<time.h>
#define LL long long
#define lowbit(x) ((x)&-(x))
#define mod 998244353

using namespace std;
int n,t;
LL arr[50008];
//LL bak[50008];
bool cmp(const LL &a,const LL &b)
{
    LL lba=lowbit(a);
    LL lbb=lowbit(b);
    return  lba==lbb?a<b:lba<lbb;
}


LL solve(int l,int r)
{
    //ç»åæåº [l,r)
    sort(arr+l,arr+r,cmp);


    if(arr[l]==arr[r-1])//å¦æç»åæåé½ç¸å
    {
        return 0;
    }
    LL ans=0;
    int bg=l,ed=l;
    while(bg<r)
    {

        LL val=lowbit(arr[bg]);
        while(ed<r&val==lowbit(arr[ed]))ed++;//æ¾å°ä¸ä¸ªç»ï¼[bg,ed)
        LL tmp=0;
        if(arr[bg]==0)//ç¹æ®å¤ç
        {

            for(int i=ed;i<r;i++)//ç¨0ååé¢å¤§äºè¯¥ç»çæ°xorï¼å¾åºä¸ä¸ª0ä¸åé¢æ°xoråçlowbitå¼
            {
                tmp=(tmp+lowbit(arr[i]^0))%mod;
            }
            //è¯¥ç»æå¤å°0ï¼ ä¹ä»¥2æ¯å ä¸ºè¦æ±ç¸äºxor
            tmp=tmp*2*(ed-bg)%mod;

        }
        else
        {
            //è¯¥ç»é¿åº¦*åè¾¹é¿åº¦*2*è¯¥ç»lowbit
            tmp=val*2*(r-ed);
            tmp%=mod;
            tmp=tmp*(ed-bg)%mod;

        }

        ans=(ans+tmp)%mod;

        for(int i=bg;i<ed;i++)
        {
            arr[i]-=val;
        }
        //åæ²»æ±è§£
        ans=(ans+solve(bg,ed))%mod;
        //è®¡ç®ä¸ä¸æ®µ
        bg=ed;
    }

    return ans%mod;
}
/*
//æ´åè§£æ³,æ³¨ææçè§£æ³ä¼ç ´åarrï¼è¯·å¡å¿ä¿è¯solve2å¨solveå
LL solve2()
{
    LL ret=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    {
        ret=(ret+lowbit(arr[i]^arr[j]))%mod;
    }
    return ret;
}
//çææµè¯æ°æ®
int makeDate()
{
    n=500;
    for(int i=0;i<n;i++)bak[i]=arr[i]=rand()%10000;
}*/
int main()
{
     srand(time(NULL));
    cin>>t;
    for(int ncase=1;ncase<=t;ncase++)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>arr[i];
        LL ans=solve(0,n);
        cout<<"Case #"<<ncase<<": "<<ans<<endl;
    }
    return 0;
}
