#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100010;
const int maxm=5;
const int MOD=10000007;
int N,a[maxn],K;
struct Matrix
{
    LL mat[maxm][maxm];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator * (Matrix A)
    {
        Matrix res;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                    res.mat[i][j]=(res.mat[i][j]+(mat[i][k]*A.mat[k][j])%MOD)%MOD;
            }
        }
        return res;
    }
};
Matrix pow_mul(Matrix A,int n)
{
    Matrix res;
    for(int i=0;i<maxm;i++)res.mat[i][i]=1;
    while(n)
    {
        if(n&1)res=res*A;
        A=A*A;
        n>>=1;
    }
    return res;
}
int main()
{
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        for(int i=1;i<=N;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+N);
        Matrix A,B;
        A.mat[0][1]=A.mat[1][0]=A.mat[1][1]=A.mat[2][0]=A.mat[2][1]=A.mat[2][2]=1;
        A=pow_mul(A,K);
        B.mat[0][0]=a[N-1],B.mat[1][0]=a[N],B.mat[2][0]=a[N-1]+a[N];
        A=A*B;
        LL sum=0;
        for(int i=1;i<N-1;i++)sum+=a[i];
        sum=(sum+A.mat[2][0])%MOD;
        printf("%I64d\n",sum);
    }
    return 0;
}
