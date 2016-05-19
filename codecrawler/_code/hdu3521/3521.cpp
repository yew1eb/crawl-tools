#include<stdio.h>
int n;
struct Matrix
{
 double arr[101][101];
};
Matrix mul(Matrix A, Matrix B)
{
 Matrix res;
 int i,j,k;
 double s;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 {
 s=0.0;
 for(k=0;k<n;k++)
 {
 s+=A.arr[i][k]*B.arr[k][j];
 }
 res.arr[i][j]=s;
 }
 return res;
}
Matrix add(Matrix A,Matrix B)
{
 Matrix res;
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 res.arr[i][j]=A.arr[i][j]+B.arr[i][j];
 return res;
}
Matrix chufa(Matrix A, int k)
{
 Matrix res;
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 res.arr[i][j]=A.arr[i][j]/k;
 return res;
}
bool ok(Matrix A)
{
 int i,j;
 bool flag=1;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 {
 if(A.arr[i][j] > 0.001) flag=0;
 }
 return flag;
}
int main()
{
 int i,j;
 while(scanf("%d",&n) && n)
 {
 Matrix A, I, res;
 for(i=0;i<n;i++)
 for(j=0;j<n;j++)
 {
 scanf("%lf",&A.arr[i][j]);
 res.arr[i][j]=A.arr[i][j];
 I.arr[i][j] = (i==j)?1.0:0;
 }
 int k=2;
 while(k<=50)
 {
 I=add(I,res);
 res=chufa(res,k);
 res=mul(res,A);
 k++;
 }
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 printf("%.2f ",I.arr[i][j]);
 }
 printf("\n");
 }
 }
}