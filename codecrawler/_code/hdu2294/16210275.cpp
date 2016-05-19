#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
const LL mod=1234567891;
LL n;
struct matrix{
    LL f[31][31];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    LL i,j,k;
    memset(c.f,0,sizeof(c.f));
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(!a.f[i][k])continue;
            for(j=0;j<n;j++)
            {
                if(!b.f[k][j])continue;
                c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[k][j])%mod;
            }
        }
    }
    return c;
}
matrix pow_mod(matrix a,LL b)
{
    matrix s;
    memset(s.f,0,sizeof(s.f));
    for(LL i=0;i<n;i++)
        s.f[i][i]=1;
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
    LL T;
    cin>>T;
    while(T--)
    {
        LL i,j,m;
        cin>>m>>n;
        matrix e;
        n++;
        memset(e.f,0,sizeof(e.f));
        for(i=0;i<n-1;i++)
        {
            e.f[i][i]=i+1;
            e.f[i][i+1]=n-i-2;
        }
        e.f[n-1][n-1]=e.f[n-2][n-1]=1;
        /*for(LL i=0;i<n;i++)
        {
            for(LL j=0;j<n;j++)
                cout<<e.f[i][j]<<" ";
            cout<<endl;
        }*/
        e=pow_mod(e,m);

        cout<<(n-1)*e.f[0][n-1]%mod<<endl;
    }
    return 0;
}
/*
    é¢æï¼æ±ç±kç§çç ç»æçé¿åº¦ä¸º1~nçé¡¹é¾çæ¹æ¡æ°åï¼æ³¨ï¼æ¯ç§æ¹æ¡å¿é¡»ç¨å°kç§çç 
    dp[i][j]è¡¨ç¤ºé¿åº¦ä¸ºiä¸ç±jç§çç ç»æçæ¹æ¡æ°ï¼
    dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1]*(k-j+1)
    ans[n]=ans[n-1]+dp[n][k];
    ç©éµï¼
    |dp[1][1] dp[1][2] ...dp[1][k] ans[0]|*|1 k-1 0   0|^n=|dp[n+1][1] dp[n+1][2] ...dp[n+1][] ans[n]|
                                           |0 2   k-2 0|
                                           |   ...     |
                                           |0 0   k   1|
                                           |0 0   0   1|
*/
