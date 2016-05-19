#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define ld long double
struct Complex{
    ld real;
    ld imag;
    Complex (){}
    Complex(ld the){
        real = cos(the);
        imag = sin(the);
    }
    Complex(ld a,ld b){
        real = a;
        imag = b;
    }
};
Complex operator + (Complex a,Complex b){
    return Complex(a.real+b.real,a.imag+b.imag);
}
Complex operator - (Complex a,Complex b){
    return Complex(a.real-b.real,a.imag-b.imag);
}
Complex operator * (Complex a,Complex b){
    return Complex(a.real*b.real-a.imag*b.imag,a.imag*b.real+a.real*b.imag);
}

#define maxn 300000
ld pi2 = 2*acos(-1.0);
void fft(Complex* A,int len, int ref){
    //A[rev[k]] = ak ç³»æ°åéè½¬ç½®
    int bitn = log2(len);
    int i,j,k;
    for(i = 0;i < len; i++){
        k = 0;
        for( j = 0;j < bitn; j++){
            k = (k<<1);
            if(i&(1<<j))
                k |= 1;
        }
        if(k > i)
            swap(A[i],A[k]);
    }
    //fftè®¡ç®å¾å°ç¹å¼
    Complex wm,w,t,u;
    for(int m = 2,f=1; m <= len; m<<=1,f<<=1){
        wm = Complex(ref*pi2/m);
        for( k = 0;k < len; k += m){
            w = Complex(1.0,0);
            for( j = k; j < k+f; j++){
                t = w*A[j+f];
                u = A[j];
                A[j] = u+t;
                A[j+f] = u-t;
                w = w*wm;
            }
        }
    }
    if(ref == -1){
        for( i = 0;i < len; i++){
            A[i].real = A[i].real/len;
        }
    }
}

Complex a1[maxn];
Complex a2[maxn];

int num[maxn];
int sum[maxn];
ll  ans[maxn];
ll snum[maxn];
int main(){
    int t,n;
    //freopen("h.in","r",stdin);
    //freopen("hh.out","w",stdout);
    scanf("%d",&t);
    snum[0] = 0;
    for(ll i = 1; i <= 100000; i++)
        snum[i] = snum[i-1] + i*(i+1)/2;
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n; i++)
            scanf("%d",&num[i]);
        sum[0] = num[0];
        for(int i = 1;i < n; i++)
            sum[i] = sum[i-1] + num[i];
        ll p = 0 ,res = 0,lnum = 0;
        for(int i = 0;i < n; i++){
            if(num[i] == 0)
                p++;
            else {
                res += snum[p];
                p = 0;
            }
        }
        res += snum[p];
        printf("%I64d\n",res);

        int total = sum[n-1];
        int total2 = total*2;
        int len = 1;
        while(len <= total2) len*=2;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for(int i = 0; i < n; i++){
            a1[sum[i]].real += i+1;
            if(i != n-1)
            a2[total-sum[i]].real += 1;
        }
        a2[total].real += 1;
        fft(a1,len,1);
        fft(a2,len,1);

        for(int i = 0;i <= len; i++)
            a1[i] = a1[i]*a2[i];
        fft(a1,len,-1);
        for(int i = 0;i <= len; i++)
            ans[i] = (ll)(a1[i].real+0.5);

        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for(int i = 0;i < n; i++){
            a1[sum[i]].real += 1;
            if(i != n-1)
            a2[total-sum[i]].real += i+1;
        }
        fft(a1,len,1);
        fft(a2,len,1);

        for(int i = 0;i <= len; i++)
            a1[i] = a1[i]*a2[i];
        fft(a1,len,-1);
        for(int i = 0;i <= len; i++)
            ans[i] -= (ll)(a1[i].real+0.5);

        for(int i = total+1;i <= total2; i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
