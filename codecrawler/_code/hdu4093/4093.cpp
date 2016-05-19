#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<complex>
#define pi acos(-1.0)
using namespace std;
int n,k;
typedef complex<double> cp;
#define maxn 13100
int arr[maxn];
int fftlen;//FFT鏁扮粍闀垮害
#define PI pi
struct cparr
{
    cp v[65536];
    void operator=(const cparr &a)
    {
        memcpy(v, a.v, sizeof(cp) * fftlen);
    }
};
const cp I(0,1);
cparr f[6];//FFT鏁扮粍
cparr g[7];//缁撴灉FFT鏁扮粍
void fft(cp a[],int n, double theta )
{
    for(int m=n; m>=2; m>>=1)
    {
        int mh = m >> 1;
        for(int i=0; i<mh; i++)
        {
            cp w = exp(i*theta*I);
            for(int j=i; j<n; j+=m)
            {
                int k = j + mh;
                cp x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    for(int j=1; j<n-1; j++)
    {
        for(int k=n>>1; k>(i^=k); k>>=1);
        if(j<i)
            swap(a[i],a[j]);
    }
}

void mul(cparr &a,cparr &b)
{
    for(int i=0; i<fftlen; i++)
        a.v[i]*=b.v[i];
}
#define ndiv p
int p;
void gao()
{
    switch(k)
    {
    case 1:
        g[0] = f[1];
        p = 1;
        break;
    case 2:
        g[0] = f[2];
        g[1] = f[1];
        mul(g[1], f[1]);
        p = 2;
        break;
    case 3:
        g[0] = f[3];
        g[1] = f[2];
        mul(g[1],f[1]);
        g[2] = f[1];
        mul(g[2],f[1]);
        mul(g[2],f[1]);
        p = 3;
        break;
    case 4:
        g[0] = f[4];
        g[1] = f[3];
        mul(g[1],f[1]);
        g[2] = f[2];
        mul(g[2],f[2]);
        g[3] = f[2];
        mul(g[3],f[1]);
        mul(g[3],f[1]);
        g[4] = f[1];
        mul(g[4],f[1]);
        mul(g[4],g[4]);
        p = 5;
        break;
    case 5:
        g[0] = f[5];
        g[1] = f[4];
        mul(g[1], f[1]);
        g[2] = f[3];
        mul(g[2],f[2]);
        g[3] = f[3];
        mul(g[3],f[1]);
        mul(g[3],f[1]);
        g[4] = f[2];
        mul(g[4],f[2]);
        mul(g[4],f[1]);
        g[5] = f[2];
        mul(g[5],f[1]);
        mul(g[5],f[1]);
        mul(g[5],f[1]);
        g[6] = f[1];
        mul(g[6],f[1]);
        mul(g[6],g[6]);
        mul(g[6],f[1]);
        p = 7;
        break;
    }
}

const int factor[6]= {1,1,2,6,24,120};
const double ce[6][10] =
{
    {0.000000},
    {1.000000},
    {-1.000000, 1.000000},
    {2.000000, -3.000000, 1.000000},
    {-6.000000, 8.000000, 3.000000, -6.000000, 1.000000},
    {24.000000, -30.000000, -20.000000, 20.000000, 15.000000, -10.000000, 1.000000}
};
int main()
{
    int tcase;
    scanf("%d",&tcase);
    for(int ti=1; ti<=tcase; ti++)
    {
        scanf("%d%d",&n,&k);
        fftlen=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            while(fftlen<=arr[i]*k)fftlen<<=1;
        }
        for(int i=1; i<=k; i++)
            for(int j=0; j<fftlen; j++)
                f[i].v[j]=0;
        //鍒濆鍖朏FT鏁扮粍
        for(int i=1; i<=k; i++)
        {
            for(int j=0; j<n; j++)
                f[i].v[arr[j]*i]+=1;
            fft(f[i].v,fftlen,2 * PI / fftlen);
        }
        gao();
        for(int i=0; i<ndiv; i++)
            fft(g[i].v,fftlen,-2 * PI / fftlen);
        printf("Case #%d:\n",ti);
        for(int i=0; i<fftlen; i++)
        {
            double tmp=0;
            for(int j=0; j<ndiv; j++)
                tmp+=g[j].v[i].real()*ce[k][j];
            tmp/=factor[k]*fftlen;
            if(tmp>0.5)
                printf("%d: %.0f\n",i,tmp);
        }
        printf("\n");
    }
    return 0;
}