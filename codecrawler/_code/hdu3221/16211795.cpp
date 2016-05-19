#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;
const int MAX = 2;
ll ai,bi,p;
ll mm;
typedef struct
{
long long m[MAX][MAX];
} Matrix;
Matrix P =
{
1,1,
1,0,
};
Matrix I =
{
1,0,
0,1,
};
Matrix matrixmul(Matrix a,Matrix b)
{
int i,j,k;
Matrix c;
for (i = 0 ; i < MAX; i++)
for (j = 0; j < MAX;j++)
{
c.m[i][j] = 0;
for (k = 0; k < MAX; k++)
c.m[i][j] += a.m[i][k] * b.m[k][j];
if(c.m[i][j]>mm)
c.m[i][j] =c.m[i][j]%mm+mm;
}
return c;
}
Matrix quickpow(long long n)
{
Matrix m = P, b = I;
while (n >= 1)
{
if (n & 1)
b = matrixmul(b,m);
n = n >> 1;
m = matrixmul(m,m);
}
return b;
}
__int64 eular(__int64 nn)
{
        __int64 ans=1,i;
        for(i=2;i*i<=nn;i++)
       {
           if(nn%i==0)
          {
              nn/=i;
              ans*=i-1;
              while(nn%i==0)
              {
                  nn/=i;
                  ans*=i;
              }
         }
      }
      if(nn>1)
      ans*=nn-1;
      return ans;
}
ll quickmod(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        b>>=1;
        a=(a*a)%p;
    }
    return res;
}
int main()
{
    int t;
    ll n;
    int count=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d%I64d",&ai,&bi,&p,&n);
        mm=eular(p);
        printf("Case #%d: ",count++);
        if(n==1) {printf("%I64d\n",ai%p);continue;}
        else if(n==2) {printf("%I64d\n",bi%p); continue;}
        else if(n==3) {printf("%I64d\n",ai*bi%p);continue;}
       // else if(n==4) {printf("%I64d\n",ai*ai*bi*bi*bi%p);continue;}
        if(p==1) {puts("0");continue;}
        Matrix g=quickpow(n-2);
        ll m1,m2,num1,num2;
        m1=g.m[1][0];
        m2=g.m[0][1]+g.m[1][1];
        if(m2>mm) m2=m2%mm+mm;
       // cout<<m1<<" "<<m2<<" "<<mm<<"*"<<endl;
        num1=quickmod(ai,m1);
        num2=quickmod(bi,m2);
        printf("%I64d\n",num1*num2%p);
    }
}
