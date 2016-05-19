#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL __int64
#define maxn 4
#define MOD 10000007
struct Matrix
{
    LL a[maxn][maxn];
    Matrix()
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<maxn;++i) a[i][i]=1;
    }
};
Matrix operator *(Matrix A,Matrix B)
{
    Matrix C;
    for(int i=1;i<maxn;++i)
        for(int j=1;j<maxn;++j)
        {
            C.a[i][j]=0;
            for(int k=1;k<maxn;++k)
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j]%MOD)%MOD;
        }
    return C;
}
LL s;
Matrix pow(Matrix A,int n)
{
    Matrix res;
    while(n)
    {
        if(n&1) res=res*A;
        A=A*A;
        n>>=1;
    }
    return res;
}

LL a[100005];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        s=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d",&a[i]);
            s=(s+a[i])%MOD;
        }
        sort(a+1,a+1+n);
        Matrix A;
        A.a[1][1]=1,A.a[1][2]=1,A.a[1][3]=1;
        A.a[2][1]=1,A.a[2][2]=0,A.a[2][3]=1;
        A.a[3][1]=0,A.a[3][2]=0,A.a[3][3]=1;
        A=pow(A,k);
        s=A.a[3][3]*s%MOD;
        s=(s+A.a[1][3]*a[n]%MOD)%MOD;
        s=(s+A.a[2][3]*a[n-1]%MOD)%MOD;

        printf("%I64d\n",s);
    }
    return 0;
}