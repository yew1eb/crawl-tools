下面是 m^n % k 的快速幂：
// m^n % k
int quickpow(int m,int n,int k)
{
    int b = 1;
    while (n > 0)
    {
        if (n & 1)
            b = (b*m)%k;
        n = n >> 1 ;
        m = (m*m)%k;
    }
    return b;
}


下面是矩阵快速幂：
//HOJ 3493
/*===================================*/
|| 快速幂（quickpow）模板
|| P 为等比，I 为单位矩阵
|| MAX 要初始化！！！！
||
/*===================================*/
/*****************************************************/
#include <cstdio>
const int MAX = 3;

typedef struct
{
    int m[MAX][MAX];
} Matrix;

Matrix P = {5,-7,4,
            1,0,0,
            0,1,0,
           };

Matrix I = {1,0,0,
            0,1,0,
            0,0,1,
           };

Matrix matrixmul(Matrix a,Matrix b) //矩阵乘法
{
    int i,j,k;
    Matrix c;
    for (i = 0 ; i < MAX; i++)
        for (j = 0; j < MAX; j++)
        {
            c.m[i][j] = 0;
            for (k = 0; k < MAX; k++)
                c.m[i][j] += (a.m[i][k] * b.m[k][j])%9997;
            c.m[i][j] %= 9997;
        }
    return c;
}

Matrix quickpow(long long n)
{
    Matrix m = P, b = I;
    while (n >= 1)
    {
        if (n & 1)
            b = matrixmul(b,m);
        n = n >> 1;
        m = matrixmul(m,m);
    }
    return b;
}
/*************************************/

int main()
{
    Matrix re;
    int f[3] = {2,6,19};
    long long n;
    while (scanf("%I64d",&n) && n != 0)
    {
        if (n == 1)
            printf("1\n");
        else if (n <= 4)
            printf("%d\n",f[n-2]);
        else
        {
            re = quickpow(n - 4);
            printf("%d\n",(((re.m[0][0]*f[2])
                            + (re.m[0][1]*f[1]) + (re.m[0][2]*f[0])) %9997 + 9997) % 9997);
        }
    }
    return 0;
}
