#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 400040
#define LL __int64
const double pi=atan(1.0)*4;
struct complex{//å¤æ°ï¼éè½½+ï¼-ï¼*
    double a,b;
    complex(double aa=0,double bb=0){a=aa;b=bb;}
    complex operator +(const complex &e){return complex(a+e.a,b+e.b);}
    complex operator -(const complex &e){return complex(a-e.a,b-e.b);}
    complex operator *(const complex &e){return complex(a*e.a-b*e.b,a*e.b+b*e.a);}
};
void change(complex y[],LL len)
{
    LL i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k)j+=k;
    }
}
//FFTå¿«éåéå¶åæ¢çæ¨¡æ¿ï¼ç¨ä»¥å°å¤é¡¹å¼ç³»æ°è½¬æ¢æåä½æ ¹ï¼ï¼ï¼åºè¯¥æ¯ï¼ï¼è¿æ ·å¾å°çä¸¤ä¸ªåºåéä¸ªç¸ä¹å°å¾å°±æ¯ç³»æ°
//åºåçå·ç§¯ï¼å³ä¸¤ä¸ªå¤é¡¹å¼ä¹ç§¯åçç³»æ°å¼
void fft(complex y[],LL len,LL on)
{
    change(y,len);
    LL i,j,k,h;
    for(h=2;h<=len;h<<=1)
    {
        complex wn(cos(-on*2*pi/h),sin(-on*2*pi/h));
        for(j=0;j<len;j+=h)
        {
            complex w(1,0);
            for(LL k=j;k<j+h/2;k++)
            {
                complex u=y[k];
                complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(i=0;i<len;i++)
            y[i].a/=len;
}
LL num[maxn],sum[maxn];
complex x[maxn];
LL a[maxn/4];
int main()
{
    LL T;
    scanf("%I64d",&T);
    while(T--)
    {
        LL n,i,j,k,maxa=-1;
        scanf("%I64d",&n);
        memset(num,0,sizeof(num));
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
            //å­å¨ä¸ªæ°ï¼ç¨ä»¥è¡¨ç¤ºå¤é¡¹å¼çç³»æ°ï¼å¶ä¸­æªç¥æ°çææ°è¡¨ç¤ºé¿åº¦ï¼è¿æ ·ä¸¤ä¸ªç¸åå¤é¡¹å¼ä¹ç§¯çç³»æ°è¡¨ç¤ºåä¸¤æ ¹æ¨æ£
            //å¶åæ¯å¯¹åºææ°çç»åä¸ªæ°(å¤é¡¹å¼ç¸ä¹ï¼ç³»æ°ç¸ä¹ï¼ææ°ç¸å )
            num[a[i]]++;
            maxa=max(maxa,a[i]);
        }
        sort(a,a+n);
        LL len1,len=1,ans=0;
        len1=maxa+1;
        //ä¸¤ä¸ªå¤é¡¹å¼é¿nï¼mï¼é£ä¹ä¹ç§¯é¿n+m-1ï¼
        //è¿éæ±ææ¥è¿ä¸å¤§äºn+m-1ç2^kï¼æ¹ä¾¿äºåæ å½¢å¼çè¿ç¨å§
        while(len<2*len1)len<<=1;
        for(i=0;i<len1;i++)
            x[i]=complex(num[i],0);
        for(i=len1;i<len;i++)
            x[i]=complex(0,0);
        fft(x,len,1);//FFTè½¬æ¢æåä½æ ¹å½¢å¼
        for(i=0;i<len;i++)
            x[i]=x[i]*x[i];//å·ç§¯
        fft(x,len,-1);//ç»æè½¬æ¢åæ¥
        for(i=0;i<len;i++)
            num[i]=(LL)(x[i].a+0.5);
        len=maxa*2;
        //å»æåå½¢åæ¨æ£
        for(i=0;i<n;i++)
            num[a[i]*2]--;
        //å»æä¸¤æ ¹æ¨æ£å·¦å³äº¤æ¢çéå¤
        for(i=1;i<=len;i++)
            num[i]/=2;
        sum[0]=0;
        for(i=1;i<=len;i++)
            sum[i]=sum[i-1]+num[i];
        for(i=0;i<n;i++)
        {
            //ä¸¤æ ¹æ¨æ£åå¤§äºa[i]çä¸ªæ°ï¼ä¸è§å½¢ä»»æä¸¤è¾¹ä¹åå¤§äºç¬¬ä¸è¾¹ï¼è¿éåçæ¯è¾å°ä¸¤è¾¹ï¼æä»¥è¦åå»å¤§äºa[i]çæ¨æ£
            ans+=sum[len]-sum[a[i]];
            //æ¨æ£ï¼ä¸æ ¹å°äºa[i],ä¸æ ¹å¤§äºa[i](è¿éçå¤§äºï¼å°äºåªæ¯è¯´å¨içååä½ç½®)
            ans-=(n-1-i)*i;
            //ææ ¹æ¨æ£åäºèªèº«ç
            ans-=n-1;
            //ä¸¤æ ¹æ¨æ£é½å¤§äºa[i]
            ans-=(n-1-i)*(n-2-i)/2;
        }
        LL t=n*(n-1)*(n-2)/6;
        printf("%.7lf\n",(double)ans/t);
    }
    return 0;
}