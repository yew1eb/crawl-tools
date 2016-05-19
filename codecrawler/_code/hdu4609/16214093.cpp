#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 270050
#define ll long long
const double PI=acos(-1.0);
struct Vir
{
    double re,im;
    Vir(double _re=0.,double _im=0.):re(_re),im(_im){}
    Vir operator*(Vir &r) { return Vir(re*r.re-im*r.im,im*r.re+re*r.im);}
    Vir operator+(Vir &r) { return Vir(re+r.re,im+r.im);}
    Vir operator-(Vir &r) { return Vir(re-r.re,im-r.im);}
};
void bit_rev(Vir *p,int loglen,int len)
{
    for(int i=0;i<len;++i)
    {
        int t=i,k=0;
        for(int j=0;j<loglen;++j)
        {
            k<<=1;
            k=k|(t&1);
            t>>=1;
        }
        if(k<i)
        {
            Vir temp=p[k];
            p[k]=p[i];
            p[i]=temp;
        }
    }
}
void FFT(Vir *a,int loglen,int len,int on)
{
    bit_rev(a,loglen,len);
    for(int t=1,m=2;t<=loglen;++t,m<<=1)
    {
        Vir wn=Vir(cos(2.0*PI*on/m),sin(2.0*PI*on/m));
        for(int i=0;i<len;i+=m)
        {
            Vir w=Vir(1.,0);
            for(int j=0;j<m/2;++j)
            {
                Vir u=a[i+j];
                Vir v=w*a[i+j+m/2];
                a[i+j]=u+v;
                a[i+j+m/2]=u-v;
                w=w*wn;
            }
        }
    }
    if(on==-1)
    {
        for(int i=0;i<len;++i) a[i].re/=len;
    }
}

Vir pa[N],pb[N];
int a[N],n;
ll cnt[N];
int main ()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%d",a+i);
        sort(a,a+n);
        int len=1,loglen=0;
        while(len<=2*a[n-1]) len<<=1,loglen++;
        
        for(int i=0;i<=len;++i) pa[i].re=pa[i].im=0.0;
        for(int i=0;i<=a[n-1];++i) cnt[i]=0;
        for(int i=0;i<n;++i) cnt[a[i]]++;
        for(int i=0;i<=a[n-1];++i) pa[i].re=cnt[i];

        FFT(pa,loglen,len,1);
        for(int i=0;i<len;++i)
          pa[i]=pa[i]*pa[i];
        FFT(pa,loglen,len,-1);
        for(int i=0;i<len;++i) cnt[i]=pa[i].re+0.5;
        for(int i=0;i<n;++i) cnt[a[i]+a[i]]--;
        for(int i=0;i<len;++i) cnt[i]/=2;

        ll tot=(n+0LL)*(n-1)*(n-2)/6;
        ll ans=tot;
        for(int i=0,k=0;i<len;++i) if(cnt[i])
        {
            while(k<n&&a[k]<i) k++;
            if(k==n) break;
            ans-=cnt[i]*(n-k);
        }
        printf("%.7lf\n",ans*1.0/tot);
    }
    return 0;
}
