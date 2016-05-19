#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const int mod=2;
int n;
struct matrix{
    int f[101][101];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    memset(c.f,0,sizeof(c.f));
    int i,j,k;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(!a.f[i][k])continue;
            for(j=0;j<n;j++)
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
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        s.f[i][j]=(i==j?1:0);
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
    int m;
    while(cin>>m)
    {
        char s[101];
        int i,j,k,a[101];
        cin>>s;
        n=strlen(s);
        for(i=0;i<n;i++)
            a[i]=s[i]-'0';
        matrix e;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            if(i==j||j==i+1)e.f[i][j]=1;
            else e.f[i][j]=0;
        e.f[n-1][0]=1;
        e=pow_mod(e,m);
        int c[101];
        memset(c,0,sizeof(c));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                c[i]=(c[i]+a[j]*e.f[j][i])%mod;
        for(i=0;i<n;i++)
            cout<<c[i];
        cout<<endl;
    }
    return 0;
}
/*
    ç©éµ 
    å¯¹äºa0a1a2a3
    |b0b1b2b3|=|a0a1a2a3|*|1 1 0 0|^m
                          |0 1 1 0|
                          |0 0 1 1|
                          |1 0 0 1| 
*/


