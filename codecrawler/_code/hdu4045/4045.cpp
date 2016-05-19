#include <iostream>

#define LL __int64
#define mod 1000000007

using namespace std;

const int N=1000;
LL s[N+5][N+5],c[2*N+5][2*N+5];


void cpre()
{
    c[0][0]=1;
    int i,j;
    for (i=1;i<=2*N;i++)
        for (j=0;j<=i;j++)
            if (j>(i+1)/2) c[i][j]=c[i][i-j];
            else if (j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod; 
}

void spre()
{
    int i,j;
    s[0][0]=1;
    for (i=1;i<=N;i++)
        for (j=0;j<=i;j++)
            if (i==j) s[i][j]=1;
            else if (j==0) s[i][j]=0;
            else s[i][j]=(j*s[i-1][j]+s[i-1][j-1])%mod;
}

int main()
{
    int n,r,k,m,i;
    cpre();
    spre();
    while (scanf("%d%d%d%d",&n,&r,&k,&m)!=EOF)
    {
        LL res,s1=0;
        int e=n-(r-1)*k-1;
        if (e<0) 
        {
            printf("0\n");
            continue;
        }
        res=c[e+r][r];
        for (i=0;i<=m;i++) s1=(s1+s[r][i])%mod;
        res=(res*s1)%mod;
        printf("%d\n",res); 
    } 
    return 0;
}
