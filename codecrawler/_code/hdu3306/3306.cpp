#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;
typedef struct
{
  int matrix[4][4];
}Matrix;

Matrix multi(Matrix x,Matrix y)
{
  Matrix res;
  int i,j,k;
  int sum;

  for(i = 0;i<4;i++)
    for(j = 0;j<4;j++)
    {
      sum = 0;
      for(k = 0;k<4;k++)
        sum+=(x.matrix[i][k]*y.matrix[k][j])%10007;
      res.matrix[i][j] = sum%10007;
    }
    return res;
}

Matrix powermod(Matrix x,int n)
{
  Matrix res;
  int i,j;

  for(i = 0;i<4;i++)
    for(j = 0;j<4;j++)
    {
       if(i==j)
        res.matrix[i][j] = 1;
       else
        res.matrix[i][j] = 0;
    }
    for(;n;n>>=1)
    {
      if(n&1)
        res = multi(res,x);
       x = multi(x,x);
    }
    return res;
}

int main()
{
    int N,X,Y;
    while(~scanf("%d %d %d",&N,&X,&Y))
    {
        if(N <= 1)
        {
            printf("%d\n",N+1);
            continue;
        }
        X%=10007,Y%=10007;
        Matrix res;
        res.matrix[0][0]=1;
        res.matrix[0][1]=(X*X)%10007;
        res.matrix[0][2]=(Y*Y)%10007;
        res.matrix[0][3]=(2*X*Y)%10007;
        res.matrix[1][0]=0;
        res.matrix[1][1]=(X*X)%10007;
        res.matrix[1][2]=(Y*Y)%10007;
        res.matrix[1][3]=(2*X*Y)%10007;
        res.matrix[2][0]=0;
        res.matrix[2][1]=1;
        res.matrix[2][2]=0;
        res.matrix[2][3]=0;
        res.matrix[3][0]=0;
        res.matrix[3][1]=X;
        res.matrix[3][2]=0;
        res.matrix[3][3]=Y;
        res=powermod(res,N-1);
        printf("%d\n",(2*res.matrix[0][0]+res.matrix[0][1]+res.matrix[0][2]+res.matrix[0][3])%10007);
    }
}