#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<set>
#include<cstdio>
#include<iostream>
#define N 2
#define LL long long
using namespace std;
const LL MOD1 = 1000000007LL;
//222222224
const LL MOD2 = 222222224LL;
//183120
const LL MOD3 = 183120LL;
struct matrix
{
    long long  m[N][N];
};
matrix p= {0,1,//左乘矩阵
           1,0,
          };
matrix I= {0,1,//要幂乘的矩阵
           1,3,
          };
matrix unin={1,0,//单位矩阵
             0,1,
            };
matrix matrixmul(matrix a,matrix b,long long  mod)//矩阵a乘矩阵b
{
    matrix c;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            c.m[i][j]=0;
            for(int k=0; k<N; k++)
                c.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
            c.m[i][j]%=mod;
        }
    return c;
}
matrix qiuckpow(long long n,long long  mod)
{
    matrix m=I,b=unin;//求矩阵I的n阶矩阵
    while(n>=1)
    {
        if(n&1)
            b=matrixmul(b,m,mod);
        n=n>>1;
        m=matrixmul(m,m,mod);
    }
    return matrixmul(p,b,mod);
}
long long  n;
int main()
{
    while(scanf("%I64d",&n)!=EOF)
    {
        matrix ans;
        ans=qiuckpow(n,MOD3);
        ans=qiuckpow(ans.m[0][0],MOD2);
        ans=qiuckpow(ans.m[0][0],MOD1);
        cout<<ans.m[0][0]<<endl;
//        for(int i=0;i<2;i++)
//        {
//             for(int j=0;j<2;j++)
//                cout<<ans.m[i][j]<<' ';
//             cout<<endl;
//        }
    }
    return 0;
}
