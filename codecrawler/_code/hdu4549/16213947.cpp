#include<stdio.h>
#define mod 1000000007
typedef __int64 LL;
struct Matrix
{
    LL mat[2][2];
};

Matrix unit_matrix =
{
    1, 0,
    0, 1
}; //åä½ç©éµ

Matrix mul(Matrix a, Matrix b) //ç©éµç¸ä¹
{
    Matrix res;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        {
            res.mat[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                res.mat[i][j] %= 1000000006;
            }
        }
    return res;
}

Matrix pow_matrix(Matrix a, LL n)  //ç©éµå¿«éå¹
{
    Matrix res = unit_matrix;
    while(n != 0)
    {
        if(n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

LL pow(LL a, LL n) //äºåå¿«éå¹
{
    a %= mod;
    LL res = 1;
    while(n != 0)
    {
        if(n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    LL a, b, n;
    Matrix tmp;
    tmp.mat[0][0] = 0;
    tmp.mat[0][1] = tmp.mat[1][0] = tmp.mat[1][1] = 1;
    while(~scanf("%I64d%I64d%I64d",&a,&b,&n))
    {
        Matrix p = pow_matrix(tmp, n); //p.mat[0][0]å³ä¸ºF(n-1)ï¼p.mat[1][0]å³ä¸ºF(n)
        LL ans = (pow(a, p.mat[0][0]) * pow(b, p.mat[1][0])) % mod;
        printf("%I64d\n",ans);
    }
    return 0;
}