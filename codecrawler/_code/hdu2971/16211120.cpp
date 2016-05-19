#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
LL mod;
struct matrix{
    LL f[4][4];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    LL i,j,k;
    memset(c.f,0,sizeof(c.f));
    for(k=0;k<4;k++)
    {
        for(i=0;i<4;i++)
        {
            if(!a.f[i][k])continue;
            for(j=0;j<4;j++)
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
    for(LL i=0;i<4;i++)
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
        LL b,n;
        cin>>b>>n>>mod;
        matrix e;
        memset(e.f,0,sizeof(e.f));
        e.f[0][0]=e.f[1][0]=e.f[1][2]=e.f[2][1]=1;
        e.f[1][1]=4*b%mod*b%mod;e.f[1][3]=2*b%mod;
        e.f[3][1]=(-4*b)%mod;e.f[3][3]=-1;
        e=pow_mod(e,n-1);
        LL ans=0;
        ans=(ans+e.f[0][0]+b*b%mod*e.f[1][0]%mod+e.f[2][0]+b*e.f[3][0]%mod)%mod;
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}
/*
    
    æ±å¾æ¯s[n]=âa[i]^2(1<=i<=n)
    ä»¤b=a[2];
    f[n]=a[n]*a[n]=(2*b*a[n-1]-a[n-2])^2=4*b*b*f[n-1]+f[n-2]-4*b*a[n-1]*a[n-2];
    a[n-1]*a[n-2]=(2*b*a[n-2]-a[n-3])*a[n-2]=2*b*f[n-2]-a[n-2]*a[n-3];
    
    å¾åºç©éµ:(s[1]=1,f[2]=b*b,f[1]=1,a2*a1=b)
    
    |s[1] f[2] f[1] a2*a1|*|1 0     0 0  |^(n-1)=|s[n] f[n+1] f[n] a(n+1)*an|
                           |1 4*b^2 1 2*b|
                           |0 1     0 0  |
                           |0 -4*b  0 -1 | 
*/