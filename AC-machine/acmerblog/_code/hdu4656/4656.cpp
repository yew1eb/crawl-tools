#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
#define maxn 3001
#define LL long long
struct matrix
{
    LL mat[3][3];
    matrix()
    {
        memset(mat,0,sizeof(mat));
    }
};
int m;
matrix mul(matrix A,matrix B)
{
    matrix C;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=2;j++)
        {
            C.mat[i][j]=0;
            for(int k=1;k<=2;k++)
            {
                C.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
            }
            C.mat[i][j]%=m;
            if(C.mat[i][j]<0)C.mat[i][j]+=m;
        }
    }
    return C;
}
matrix pows(matrix A,LL p)
{
    matrix B;
    B.mat[1][1]=B.mat[2][2]=1;
    while(p)
    {
        if(p&1)B=mul(B,A);
        A=mul(A,A);
        p>>=1;
    }
    return B;
}
int main()
{
    int a,b,n;
    while(~scanf("%d%d%d%d",&a,&b,&n,&m))
    {
        matrix A;
        A.mat[1][1]=2;
        A.mat[2][1]=2*a;
        matrix B;
        B.mat[1][1]=0;     B.mat[1][2]=1;
        B.mat[2][1]=b-a*a; B.mat[2][2]=2*a;
        B=pows(B,n);
        A=mul(B,A);
        cout<<A.mat[1][1]<<endl;
    }
    return 0;
}






















