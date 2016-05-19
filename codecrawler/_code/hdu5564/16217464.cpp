#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int maxn = 71;
const int mod = 1e9 + 7;

struct Matrix
{
    int mat[maxn][maxn];
    Matrix()
    {
        memset(mat, 0, sizeof(mat));
    }
    void clear(){ memset(mat, 0, sizeof(mat)); }
    friend Matrix operator *(const Matrix &A, const Matrix &B);
    friend Matrix operator ^(Matrix A, int n);
};

Matrix res1, res2;

Matrix operator *(const Matrix &A, const Matrix &B)
{
    Matrix ret;
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            for (int k = 0; k < maxn; k++)
            {
                ret.mat[i][j] = (ret.mat[i][j] + (1LL*A.mat[i][k] * B.mat[k][j]) % mod) % mod;
            }
        }
    }
    return ret;
}

Matrix operator ^(Matrix A, int n)
{
    Matrix ret;
    for (int i = 0; i < maxn; i++)
    {
        ret.mat[i][i] = 1;
    }
    for (; n; n >>= 1, A = A*A)
        if (n & 1)
            ret = ret*A;
    return ret;
}

inline int statu(int i, int j)
{
    return i * 10 + j;
}

int main()
{
    //freopen("i.txt","r",stdin);
    //freopen("o.txt","w",stdout);
    
    int t;
    int i, j, L, R, K, x;
    
    Matrix A, B;
    for (i = 1; i < 10; i++)
        A.mat[0][statu(i % 7, i)] = 1;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &L, &R, &K);

        B.clear();
        for (i = 0; i < 7; i++)
        {
            for (j = 0; j < 10; j++)
            {
                for (x = 0; x < 10; x++)
                {
                    if (j + x != K)
                    {
                        B.mat[statu(i, j)][statu((i * 10 + x) % 7, x)] = 1;
                    }
                }
            }
        }

        for (i = 0; i < 10; i++)
            B.mat[i][maxn - 1] = 1;
        B.mat[maxn - 1][maxn - 1] = 1;
        
        res1 = A*(B^R);
        res2 = A * (B ^ (L - 1));
        printf("%d\n", (res1.mat[0][maxn - 1] - res2.mat[0][maxn - 1] + mod) % mod);
    }
    //system("pause");
    return 0;
}
