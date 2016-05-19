///å¯¹äºæ¯ä¸ä¸ªa[i],ç¨dpæ¾åºa[i]å·¦è¾¹åå³è¾¹è¿ç»­å¤§äºèªå·±çæ°çé¿åº¦
///l[i]è¡¨ç¤ºæ¯a[i]å¤§çæ°è¿ç»­çæå·¦è¾¹çä½ç½®
///r[i]è¡¨ç¤ºæ¯a[i]å¤§çæ°è¿ç»­çæå³è¾¹çä½ç½®
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#define LL long long
using namespace std;
const int N=100010;
LL  a[N],l[N],r[N],maxn,s;
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
        l[1]=1;
        r[n]=n;
        for(int i=2;i<=n;i++)
        {
            int tt=i;
            while(tt>1&&a[i]<=a[tt-1]) tt=l[tt-1];///dpææ³
            l[i]=tt;
        }
        for(int i=n-1;i>=1;i--)
        {
            int tt=i;
            while(tt<n&&a[i]<=a[tt+1]) tt=r[tt+1];
            r[i]=tt;
        }
        maxn=0;
        for(int i=1;i<=n;i++)
        {
            s=(r[i]-l[i]+1)*a[i];
            if(s>maxn)
            maxn=s;
        }
        printf("%I64d\n",maxn);
    }
    return 0;
}
