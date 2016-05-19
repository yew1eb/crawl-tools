#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define max 3
struct Matrix
{
    int data[max][max];
};

Matrix A,B;
int n = 3;
int mod = 2010;

void init()
{
    memset(A.data,0,sizeof(A.data));
    memset(B.data,0,sizeof(B.data));
    A.data[0][1] = 1;
    A.data[1][2] = 1;
    A.data[2][0] = 1;
    A.data[2][2] = 2;
    B.data[0][0] = 1;
    B.data[1][0] = 1;
    B.data[2][0] = 2;
}
//矩阵相乘
Matrix mul(Matrix u,Matrix v)
{
    Matrix t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            t.data[i][j] = 0;
            for(int k=0;k<n;k++)
            {
                t.data[i][j] += (u.data[i][k] * v.data[k][j])%mod;
                t.data[i][j] %= mod;
            }
        }
    }
    return t;
}
//矩阵的幂
Matrix power(Matrix matrix,int k)
{
    int k_temp = k;
    Matrix result,a;

    memset(result.data,0,sizeof(result.data));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a.data[i][j] = matrix.data[i][j];
            if(i == j)
            {
                result.data[i][j] = 1;
            }
            //printf("%d ",a.data[i][j]);
        }
        //printf("\n");
    }
    while(k_temp)
    {
        if(k_temp&1)
        {
            result = mul(result,a);
        }
        a = mul(a,a);
        k_temp = k_temp>>1;
    }
    return result;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int num;
    init();
    while(scanf(" %d",&num)!=EOF)
    {
        if(num == 1) printf("1\n");
        else if(num == 2) printf("2\n");
        else
        {
            Matrix temp = power(A,num - 2);
            Matrix fin = mul(temp,B);
            printf("%d\n",fin.data[2][0]);
        }
    }
    return 0;
}