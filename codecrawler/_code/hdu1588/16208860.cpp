#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>

#define N 40
#define ss(a) scanf("%d",&a)
#define cl(a) memset(a,0,sizeof(a))
#define ll __int64

using namespace std;

struct matrix
{
    ll u[N][6][6];
    ll v[6][6];
    int size;
}f,g;
int mod;
ll g0[6][6];

void init()
{
    cl(f.u);cl(f.v);
    f.u[0][1][1]=1;f.u[0][1][2]=1;
    f.u[0][2][1]=1;f.u[0][2][2]=0;
    f.v[1][1]=1;f.v[1][2]=0;
    f.v[2][1]=0;f.v[2][2]=1;
    f.size=2;
}

void zmul(matrix &z,int x)
{
    cl(g0);
    int i,j,k;
    for (i=1;i<=z.size;i++)
        for (j=1;j<=z.size;j++)
        {   
            g0[i][j]=0;
            for (k=1;k<=z.size;k++) g0[i][j]+=(z.v[i][k]*z.u[x][k][j]%mod);
        }
    for (i=1;i<=z.size;i++)
        for (j=1;j<=z.size;j++) z.v[i][j]=g0[i][j];
}

void rmul(matrix &z,int x)
{
    int i,j,k;
    for (i=1;i<=z.size;i++)
        for (j=1;j<=z.size;j++)
        {
            ll re=0;
            for (k=1;k<=z.size;k++) re+=(z.u[x-1][i][k]*z.u[x-1][k][j]%mod);
            z.u[x][i][j]=re%mod;             
        }
}

void bin(matrix &z,int m)
{
    int i=0;
    while (m>0)
    {
        if (m&1) zmul(z,i);
        i++;
        rmul(z,i);
        m>>=1;
    }
}

void init1()
{
    int i,j,t;
    cl(g.u);cl(g.v);
    g.size=4;
    t=g.size;
    for (i=1;i<=t;i++)
        for (j=1;j<=t;j++) 
            if (i==j) g.v[i][j]=1; 
    for (i=1;i<=2;i++)
        for (j=1;j<=2;j++) g.u[0][i][j]=f.v[i][j];
    for (i=1;i<=2;i++)
        for (j=3;j<=4;j++)
            if (j-i==2) g.u[0][i][j]=1;
    for (i=3;i<=4;i++) 
        for (j=3;j<=4;j++)
            if (j==i) g.u[0][i][j]=1;
}

int main()
{
    int b,n,k,i,j;
    ll res;
    while (ss(k)!=EOF)
    {
        ss(b);ss(n);ss(mod);
        init();
        bin(f,k);
        init1();
        bin(g,n);   
        init();    
        if (b>=1) 
        {
            bin(f,b-1);
            res=f.v[1][1]*g.v[1][3]%mod+f.v[2][1]*g.v[1][4]%mod;
        }
        else
        {
            res=g.v[2][3];
        }
        res%=mod;
        printf("%d\n",res);
    }
    return 0;
}
