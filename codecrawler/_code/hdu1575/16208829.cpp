#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 15
using namespace std;
struct matrix
{
    int num[MAX][MAX];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
};
matrix res;
matrix A;
int n,k;
matrix operator*(matrix &a,matrix &b)
{
    matrix t;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            t.num[i][j]=0;
            for(k=0;k<n;k++)
                t.num[i][j]+=(a.num[i][k]*b.num[k][j]);      //ä¸è½åæt.num[i][j]+=(a.num[i][k]*b.num[k][j])%9973;
            t.num[i][j]%=9973;
        }
    return t;
}
void quickpower(int x)
{
    while(x>=1)
    {
        if(x&1)
            res=res*A;
        x>>=1;
        A=A*A;
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&A.num[i][j]);
                res.num[i][j]=(i==j);
            }
        quickpower(k);
        int sum=0;
        for(i=0;i<n;i++)
        {
            sum+=res.num[i][i]%9973;
        }
        printf("%d\n",sum%9973);
    }
    return 0;
}