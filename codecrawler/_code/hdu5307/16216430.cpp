#include <cstdio>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;   //è¿é¢ç²¾åº¦å¡çæ¯è¾ç´§ï¼ç¨long double
const ld PI = acos(-1.0);
struct complex {
    ld r,i;
    complex(ld _r = 0,ld _i = 0) {
        r = _r; i = _i;
    }
    complex operator +(const complex &b) {
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b) {
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b)
    {
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
void change(complex y[],int len) {    //fftåçååº
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++) {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k) {
            j -= k;k /= 2;
        }
        if(j < k) j += k;
    }
}
void fft(complex y[],int len,int on) {   //on ä¸º1æ­£åæ¢ï¼-1ååæ¢
    change(y,len);
    for(int h = 2; h <= len; h <<= 1) {
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h) {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++) {
                complex u = y[k];complex t = w*y[k+h/2];
                y[k] = u+t;y[k+h/2] = u-t;w = w*wn;
            }
        }
    }
    if(on == -1) for(int i = 0;i < len;i++) y[i].r /= len;
}
const int maxn=100005;
complex a[maxn*4],b[maxn*4];
ll cou0[maxn],ans[maxn];int sum[maxn];

int main()
{
//    freopen("aa.txt","r",stdin);
    int T,i,n,tot,tot2,len;
    cou0[0]=0;
    for(i=1;i<maxn;i++) cou0[i]=cou0[i-1]+(ll)i*(i+1)/2;
    cin>>T;
    while(T--) {
        cin>>n;ll cou=0,ans0=0;
        for(i=1;i<=n;i++) scanf("%d",&sum[i]);
        for(i=1;i<=n;i++) {
            if(sum[i]==0) cou++;
            else {
                ans0+=cou0[cou];cou=0;
            }
        } ans0+=cou0[cou];sum[0]=0;
        printf("%I64d\n",ans0);
        for(i=1;i<=n;i++) sum[i]+=sum[i-1];
        tot=sum[n];tot2=tot*2;len=1;
        while(len<(tot2+5)) len<<=1;
        memset(a,0,sizeof(a));memset(b,0,sizeof(b));
        for(i=1;i<=n;i++) {
            a[sum[i]].r+=i;b[tot-sum[i-1]].r+=1;
        }
        fft(a,len,1);fft(b,len,1);
        for(i=0;i<len;i++) a[i]=a[i]*b[i];
        fft(a,len,-1);
        for(i=1;i<=tot;i++) ans[i]=ll(a[tot+i].r+0.5);
        memset(a,0,sizeof(a));memset(b,0,sizeof(b));
        for(i=1;i<=n;i++) {
            a[sum[i]].r+=1;b[tot-sum[i-1]].r+=i-1;
        }
        fft(a,len,1);fft(b,len,1);
        for(i=0;i<len;i++) a[i]=a[i]*b[i];
        fft(a,len,-1);
        for(i=1;i<=tot;i++) ans[i]-=ll(a[tot+i].r+0.5);
            for(i=1;i<=tot;i++) printf("%I64d\n",ans[i]);
    }
    return 0;
}
