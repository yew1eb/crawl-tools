/*
   本题从表面上看是排列组合题，但要推出公式还是有相当难度。所以想到用DP来做。
   方程可通过枚举几种情况来推出。
   以F[i][j]表示长度为i的pendant，用了j种珍珠，所构成的方案数，则F[i][j]=F[i-1][j]*j+F[i-1][j-1]*(k-j+1)。
   结果就是F[1][k]+…+F[n][k]。但注意到N的范围很大，申请那么大的数组会MLE。
   注意到当前状态只与上一个状态有关，那么可以使用循环数组来，并累加上每个F[I][K]的方法来做。
   但这样的复杂度为O（NK），会TLE。
   优化的方法是使用矩阵来做。将F[i-1]到F[i]的转移用矩阵来描述，相当于一个k*k的线性变换矩阵。
   因此F[i]=A*F[i-1]，这里A是转移矩阵，即F[i]=Ai-1*F[1]，
   所以F[1]+…+F[n]=A0*F[1]+…+An-1*F[1]=（E+A+A2+…+An-1)*F[1]。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
 
const int mod = 1234567891;
const int Max = 33;
struct Mat
{
    __int64 Matrix[Max][Max];
    void clear()
    {
        memset(Matrix, 0, sizeof(Matrix));
    }
}e, init, ans, temp;
 
int n, k;
 
Mat mul(Mat a, Mat b)
{
    int i, j, k;
    Mat c;
 
    c.clear();
    for(i=0; i<Max; i++)
    {
        for(k=0; k<Max; k++)
        {
            if(a.Matrix[i][k])
            {
                for(j=0; j<Max; j++)
                {
                    c.Matrix[i][j] = (c.Matrix[i][j] + a.Matrix[i][k] * b.Matrix[k][j])%mod;
                    if(c.Matrix[i][j] >= mod)
                        c.Matrix[i][j] %= mod;
                }
            }
        }
    }
    return c;
}
 
void solve(int p) //递归二分算和式:A^1+A^2+...+A^N
{
    if(p == 0)
        return;
    solve(p/2);
 
    int i, j;
    for(i=0; i<=k; ++i)
    {
        for(j=0; j<=k; ++j)
            temp.Matrix[i][j] = e.Matrix[i][j];
    }
 
    for(i=0; i<=k; ++i) //D=B+E
    {
        temp.Matrix[i][i] = (temp.Matrix[i][i] + 1)%mod;
    }
 
    ans = mul(ans, temp); //C=C*D=C*B+C;
    e = mul(e, e);  //B=B*B;
 
    if(p&1)
    {
        e = mul(e, init); //B=B*A
        for(i=0; i<=k; ++i) //C=C+B
        {
            for(j=0; j<=k; ++j)
                ans.Matrix[i][j] = (ans.Matrix[i][j] + e.Matrix[i][j])%mod;
        }
    }
}
 
int main()
{
    int i, j, t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        init.clear();
        ans.clear();
        temp.clear();
 
        for(i=0; i<Max; i++)
        {
            for(j=0; j<Max; j++)
                e.Matrix[i][j] = (i==j);
        }
 
        //F[i][j]=F[i-1][j]*j+F[i-1][j-1]*(k-j+1)
        for(i=1; i<=k; i++)
        {
            init.Matrix[i-1][i] = (k-i+1);
            init.Matrix[i][i] = i;
        }
 
        solve(n);
        if(ans.Matrix[0][k] < 0)
            ans.Matrix[0][k] += mod;
        printf("%I64d\n", ans.Matrix[0][k]);
    }
    return 0;
}