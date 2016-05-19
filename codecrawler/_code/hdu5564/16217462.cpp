#include <bits/stdc++.h>
using namespace std;

const int maxn = 72;
const int mod = 1e9+7;
struct Matrix
{
    int mat[maxn][maxn];
    Matrix()
    {memset(mat,0,sizeof(mat));}
    friend Matrix operator *(const Matrix &A,const Matrix &B);
    friend Matrix operator ^(Matrix A,int n);
};

Matrix operator *(const Matrix &A,const Matrix &B) //mul 
{
    Matrix ret;
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                (ret.mat[i][j]+=1ll*A.mat[i][k]*B.mat[k][j]%mod)%=mod;
    return ret;
}
Matrix operator ^(Matrix A,int n)  //pow
{
    Matrix ret;
    for(int i=0;i<maxn;i++)
        ret.mat[i][i]=1;
    for(;n;n>>=1,A=A*A) if(n&1)
        ret=ret*A;
    return ret;
}
inline int Statu(int i,int j)
{
    return i*10+j;
}
int main()
{
    int nCase,i,j,L,R,K;
    scanf("%d",&nCase);
    while(nCase--)
    {
        scanf("%d%d%d",&L,&R,&K);
        Matrix A,B;
        for(i=0;i<7;i++)
            for(j=0;j<10;j++)
                for(int x=0;x<10;x++) if(j+x!=K)
                    B.mat[Statu(i,j)][Statu((i*10+x)%7,x)]++;
        for(i=0;i<10;i++)
            B.mat[Statu(0,i)][maxn-1]++;
        B.mat[maxn-1][maxn-1]=1;
        for(i=1;i<10;i++)
            A.mat[0][Statu(i%7,i)]++;
        Matrix ret1=A*(B^R);
        Matrix ret2=A*(B^(L-1));
        int res=ret1.mat[0][maxn-1]-ret2.mat[0][maxn-1];
        while(res<0)    res+=mod;
        while(res>=mod)    res-=mod;
        printf("%d\n",res);
    }
    return 0;
}