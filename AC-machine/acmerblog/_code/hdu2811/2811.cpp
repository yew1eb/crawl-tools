#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define O 1005
#define Int __int64
using namespace std;
Int f[O][O];
Int g[O];
Int n,k;
int main()
{
    int i,j;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {   
            f[i][0]=f[i][i]=1;
            for(j=1;j<i;j++)
            f[i][j]=(f[i-1][j-1]+f[i-1][j])%k;
        }
       g[0]=1,g[1]=1,g[2]=1;
        for(i=3;i<=n;i++)
        {   
            g[i]=0;
            for(j=1;j<i;j++)
               g[i]=(g[i]+g[j]*f[i-2][j-1]%k*g[i-j-1]%k)%k;
        }
        printf("%I64d\n",g[n]%k);
    }
    return 0;
}
