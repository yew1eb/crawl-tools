#include <iostream>
#include <cstdio>
#include <vector>
 
#define N 32767
#define cl(a) memset(a,0,sizeof(a))
#define mod 1000000007
#define pb push_back
#define ll __int64
#define ss(a) scanf("%d",&a)

using namespace std;

ll f[3][3],f1[3][3],z[3];

ll js(ll n,int k)
{    
    ll res=1,t=n;
    while (k>0)
    {
        if (k&1) res=(res*t)%mod;
        t=(t*t)%mod;
        k>>=1;
    }
    return res;
}

void init()
{
    cl(z);cl(f);
    z[1]=1;z[2]=0;
    f[1][1]=1;f[1][2]=1;
    f[2][1]=1;f[2][2]=0;   
}

void rmul()
{
    int i,j,k;
    for (i=1;i<=2;i++)
        for (j=1;j<=2;j++)
        {
            f1[i][j]=0;
            for (k=1;k<=2;k++) f1[i][j]=(f1[i][j]+f[i][k]*f[k][j])%(mod-1);
        }
    for (i=1;i<=2;i++)
        for (j=1;j<=2;j++) f[i][j]=f1[i][j];
}

void zmul()
{
    ll z1,z2;
    z1=(f[1][1]*z[1]+f[1][2]*z[2])%(mod-1);
    z2=(f[2][1]*z[1]+f[2][2]*z[2])%(mod-1);
    z[1]=z1;
    z[2]=z2;
}

ll fib(int n)
{
    int i;
    init();
    n--;
    if (n&1) zmul();
    n>>=1;
    for (i=1;i<N;i++) 
    {
        rmul();
        if (n&1) zmul();
        n>>=1;
        if (!n) break;
    }
    return z[1]; 
}

int main()
{
    int n,a1,b1;
    while (ss(a1)!=EOF)
    {
        ss(b1);ss(n);
        if (n<2)
        {
            if (!n) cout<<a1%mod<<endl;
            else cout<<b1%mod<<endl;
            continue;
        }
        if (!a1||!b1)
        {
            cout<<0<<endl;
            continue;
        }
        int m1,m2;
        ll res=1;
        if (a1>1) res=res*js(a1,fib(n-1))%mod;
        if (b1>1)res=res*js(b1,fib(n))%mod;
        printf("%d\n",res);
    }
    return 0;
}
