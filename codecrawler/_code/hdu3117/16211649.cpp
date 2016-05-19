#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define maxn 2
const int mod=10000;
struct matrix{
    int f[4][4];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    memset(c.f,0,sizeof(c.f));
    int i,j,k;

    for(k=0;k<maxn;k++)
    {
        for(i=0;i<maxn;i++)
        {
            if(!a.f[i][k])continue;
            for(j=0;j<maxn;j++)
            {
                //cout<<mod<<endl;
                if(!b.f[k][j])continue;
                c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%mod;
            }
        }
    }
    return c;
}
matrix pow_mod(matrix a,int b)
{
    matrix s;
    int i,j;
    for(i=0;i<maxn;i++)
        for(j=0;j<maxn;j++)
        s.f[i][j]=(i==j?1:0);
    if(b<0)
    {
        s.f[0][0]=0;s.f[0][1]=1;
        s.f[1][0]=1;s.f[1][1]=-1;
        return s;
    }
    while(b)
    {

        if(b&1)
            s=mul(s,a);
        a=mul(a,a);
        b=b>>1;
    }
    return s;
}
int main()
{
    int F[40];
    F[0]=0;F[1]=1;
    for(int i=2;i<40;i++)
        F[i]=F[i-1]+F[i-2];
    int n;
    while(cin>>n)
    {
        if(n<40)
        {
            cout<<F[n]<<endl;
            continue;
        }
        double s,p;
        int ans;
        p=(sqrt(5.0)+1.0)/2.0;
        s=-0.5*log10(5.0)+1.0*n*log10(p);
        s=s-(int)s;
        ans=(int)(pow(10.0,s)*1000);
        cout<<ans<<"...";
        matrix e;
        e.f[0][0]=e.f[0][1]=e.f[1][0]=1;e.f[1][1]=0;
        e=pow_mod(e,n);
        printf("%04d\n",e.f[0][1]);//æ³¨æåå¯¼0
    }
    return 0;
}
/*
   ç±æ°é¢ç®çæ®æ ·ä¾å¯ç¥ï¼å½n<40æ¶ï¼æ°æ®é¿åº¦å°äº8ï¼ç¨ä¸ªæ°ç»ä¿æï¼å¯ç´æ¥è¾åºã

   f[n]=(1/â5) * [((1+â5)/2)^n-((1-â5)/2)^n](n=1,2,3.....)
   p=(sqrt(5.0)+1.0)/2.0;
   åå¯¹æ°log10(f[n])=-0.5*log10(5.0)+1.0*n*log10(p)+log10(1-((1-â5)/(1+â5))^n);
   å¶ä¸­å½nå¤å¤§æ¶ï¼log10(1-((1-â5)/(1+â5))^n)è¶äº0ï¼æä»¥å¯ä»¥çç¥

   ä»¤log10(f[n])=a+b,aä¸ºæ´æ°é¨åï¼bä¸ºå°æ°é¨å
   aæ¯æ°æ®çé¿åº¦ï¼(int)(10^b*1000)å°±æ¯å4ä½

   ååä½ç¨ç©éµæ¥æ±ï¼
    |f[n+1] f[n]|=|f[n] f[n-1]|*|1 1|
                                |1 0|
*/


