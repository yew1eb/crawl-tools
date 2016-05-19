#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;


//é«æ¯æ¶å
const int eps=1e-8;
const int maxn=22;
struct matrix{
    double f[maxn][maxn];
}a;
void gauss_jordan(int n)
{
    int i,j,k,r;
    for(i=0;i<n;i++)
    {
        r=i;
        for(j=i+1;j<n;j++)
            if(fabs(a.f[j][i])>fabs(a.f[r][i]))r=j;
        if(fabs(a.f[r][i])<eps)continue;
        if(r!=i)for(j=0;j<=n;j++)swap(a.f[r][j],a.f[i][j]);
        for(k=0;k<n;k++)if(k!=i)
            for(j=n;j>=i;j--)a.f[k][j]-=a.f[k][i]/a.f[i][i]*a.f[i][j];
    }
}

int n,d[maxn];
int inf[maxn];
int main()
{
    double p;
    while(scanf("%lf",&p)!=EOF)
    {
        int i,j,k;
        memset(a.f,0,sizeof(a.f));
        for(i=0;i<20;i++)
        {
            if(i==0)a.f[0][0]=p;
            else if(i==1)a.f[1][0]=p-1;
            else a.f[i][i-2]=p-1;

            if(i!=19)a.f[i][i+1]=-p;
            if(i!=0)a.f[i][i]=1;
            a.f[i][20]=1;
        }
        gauss_jordan(20);
        memset(inf,0,sizeof(inf));
        for(i=n-1;i>=0;i--)
        {
            if(fabs(a.f[i][i])<eps&&fabs(a.f[i][n])>eps)inf[i]=1;
            for(j=i+1;j<n;j++)
                if(fabs(a.f[i][j])>eps&&inf[j])inf[i]=1;
        }

        printf("%.6f\n",a.f[0][20]/a.f[0][0]*2-a.f[19][20]/a.f[19][19]);
    }
    return 0;
}

