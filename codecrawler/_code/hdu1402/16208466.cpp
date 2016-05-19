#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
struct comp
{
    double r,i;
    comp(double rt=0,double it=0)
    {
        r=rt;
        i=it;
    }
    comp operator +(const comp& b)
    {
        return comp(r+b.r,i+b.i);
    }
    comp operator -(const comp &b)
    {
        return comp(r-b.r,i-b.i);
    }
    comp operator *(const comp &b)
    {
        return comp(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};

void change(comp y[],int len)//äºè¿å¶è½¬ç½®--é·å¾·ç®æ³
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1;i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k)j += k;
    }
}

void fft(comp y[],int len,int on)
/* on=1 DFT æä¸ä¸ªå¤é¡¹å¼çç³»æ°åéè½¬åä¸ºç¹éè¡¨ç¤ºï¼
on=-1,IDFT æä¸ä¸ªç¹éè½¬åæå¤é¡¹å¼çç³»æ°åé*/
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        comp wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            comp w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                comp u = y[k];
                comp t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

void conv(comp f[],int len)//æ±fçå·ç§¯
{
    fft(f,len,1);
    for (int i=0; i<len; i++)
    f[i]=f[i]*f[i];
    fft(f,len,-1);
}
int n,m,len1,len2,len;
char a[50500],b[50500];
comp x[450500],y[450500];
int ans[450500];
int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%s",a))
    {
        scanf("%s",b);
        int l1=strlen(a);
        for (int i=0; i<l1; i++)
        x[l1-i-1]=comp(a[i]-'0',0);

        int l2=strlen(b);
        for (int i=0; i<l2; i++)
        y[l2-i-1]=comp(b[i]-'0',0);

        len=1;
        while(len<(l1+l2)*2) len<<=1;
        for (int i=l1; i<len; i++) x[i]=comp(0,0);
        for (int i=l2; i<len; i++) y[i]=comp(0,0);

        fft(x,len,1);
        fft(y,len,1);
        for (int i=0; i<len; i++)
        x[i]=x[i]*y[i];
        fft(x,len,-1);

        for (int i=0; i<len; i++)
        ans[i]=(int)(x[i].r+0.5);
        for (int i=0; i<len; i++)
        if (ans[i]>9)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }

        bool ok=false;
        for (int i=len-1; i>=0; i--)
        {
            if (ok) printf("%d",ans[i]);
            else if (ans[i])
            {
                ok=true;
                printf("%d",ans[i]);
            }
        }
        if (!ok) puts("0");
        else puts("");


    }
}
