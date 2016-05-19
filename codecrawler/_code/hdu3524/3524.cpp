#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define mod 10007
const int N = 4;
struct Mat{
    int mat[N][N];
    void clear()
    {
        memset(mat,0,sizeof(mat));
    }
};

Mat mul(Mat A,Mat B)
{
    Mat C;
    C.clear();
    int i,j,k;
    for(i = 0;i < N;i++)
        for(j = 0;j < N;j++)
            for(k = 0;k < N;k++)
                C.mat[i][j] = (C.mat[i][j]+A.mat[i][k]*B.mat[k][j])%mod;
    return C;
}

Mat fastm(Mat C,int n)
{
    if(n == 1)
        return C;
    else if(n&1)
        return mul(fastm(mul(C,C),n>>1),C);
    else return fastm(mul(C,C),n>>1);
}

int main()
{
    int t,i,n;
    Mat A;
    A.clear();
    A.mat[0][0] = A.mat[1][1] = 2;
    A.mat[0][1] = A.mat[0][3] = A.mat[1][0] = A.mat[1][2] = 0;
    A.mat[2][0] = A.mat[2][1] = A.mat[2][2] = A.mat[3][0] = A.mat[3][1] = A.mat[3][3] = 0;
    A.mat[0][2] = A.mat[1][3] = A.mat[2][3] = A.mat[3][2] = 1;
    int f1 = 2,f2 = 2,a = -2,b = -1,fn;
    scanf("%d",&t);
    for(i = 1;i <= t;i++)
    {
        scanf("%d",&n);
        if(n == 1 || n == 2)
        {
            printf("Case #%d: 2\n",i);
            continue;
        }
        Mat Ans = fastm(A,n-1);
        fn = ((Ans.mat[0][0]*f1)%mod+(Ans.mat[0][1]*f2)%mod+(Ans.mat[0][2]*a+Ans.mat[0][3]*b)%mod + mod)%mod;
        printf("Case #%d: %d\n",i,fn);
    }
    return 0;
}