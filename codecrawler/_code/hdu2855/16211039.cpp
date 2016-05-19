#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL __int64
int mod;
struct matrix{
    int f[2][2];
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    int i,j,k;
    memset(c.f,0,sizeof(c.f));
    for(k=0;k<2;k++)
    {
        for(i=0;i<2;i++)
        {
            if(!a.f[i][k])continue;
            for(j=0;j<2;j++)
            {
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
    memset(s.f,0,sizeof(s.f));
    for(int i=0;i<2;i++)
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
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n>>mod;
        if(n==0){cout<<0<<endl;continue;}
        n=n*2;
        matrix e;
        e.f[0][0]=e.f[0][1]=e.f[1][0]=1;e.f[1][1]=0;
        e=pow_mod(e,n);
        cout<<e.f[0][1]<<endl;
    }
    return 0;
}
/*
    ç©éµ:
    ææ³¢é£å¥æ°å
    f[n]=f[n-1]+f[n-2];
    |f[n+1] f[n]|=|f[n] f[n-1]|*|1 1|
                                |1 0|
     æ¹æ³ï¼
     éé¡¹å¬å¼ï¼f[n]=(1/sqrt(5))*(((1+sqrt(5))/2)^n-((1-sqrt(5))/2)^n)
     äºé¡¹å¼ï¼(1+a)^n=â(C(n,k)*a^k)(0<=k<=n)
     
     âC(n,k)*f[k]
     =(1/sqrt(5))*âC(n,k)*(((1+sqrt(5))/2)^k-((1-sqrt(5))/2)^k)
     =(1/sqrt(5))*(âC(n,k)*((1+sqrt(5))/2)^k-âC(n,k)*((1-sqrt(5))/2)^k)
     =(1/sqrt(5))*((3+sqrt(5))/2)^n-((3-sqrt(5))/2)^n)
     =(1/sqrt(5))*((1+sqrt(5))/2)^(2*n)-((1-sqrt(5))/2)^(2*n))
     =f[2*n]
    
     è¿å¯åå¼ä¸ã
     åg[n]=âC(n,k)*f[k];
     g[n]=[2*n]=f[2*n-1]+f[2*n-2]=2*f[2*n-2]+f[2*n-3]=3*f[2*n-2]-f[2*n-2]+f[2*n-3]
                =3*f[2*n-2]-f[2*n-4]=3*g[n-1]-g[n-2];
    ç©éµï¼
        |g[n+1] g[n]|=|g[n] g[n-1]|*| 3 1|(g[0]=0,g[1]=3)
                                    |-1 0|
    ç»æ:0 1 3 8 21 55...å¦æä½ æç»´å¤æ´»è·ï¼ä¹å¯ä»¥ç´æ¥çåºæ¥g[n]=3*g[n-1]-g[n-2]çå§ãã
*/
