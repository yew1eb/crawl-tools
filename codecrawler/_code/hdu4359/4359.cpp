#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=369;
const long long maxmod=1000000000+7;
long long f[maxn][maxn],c[maxn][maxn];
int n,m,z,sec;
int main()
{
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    for(int i=1;i<=360;i++)
    {
        c[0][0]=1;
        c[i][0]=1;
    }
    for(int i=1;i<=360;i++)
     for(int j=1;j<=i;j++)
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%maxmod;
    for(int j=1;j<=360;j++)
    f[1][j]=1;
    for(int i=2;i<=360;i++)
    for(int j=1;j<=360;j++)
    {
    f[i][j]=(c[i][i-1]*2*f[i-1][j-1])%maxmod;
    for(int k=1;k<=i-2;k++)
    f[i][j]=(f[i][j]+((c[i][i-1]*c[i-2][k])%maxmod)*((f[k][j-1]*f[i-1-k][j-1])%maxmod))%maxmod;
    }
    scanf("%d",&sec);
    for(int z=1;z<=sec;z++)
    {
        scanf("%d%d",&n,&m);
        printf("Case #%d: %I64d\n",z,(f[n][m]+maxmod-f[n][m-1])%maxmod);
    }
    return 0;
}