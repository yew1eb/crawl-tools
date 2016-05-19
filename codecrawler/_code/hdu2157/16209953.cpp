#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 25
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
int n,m;
int map[MAX][MAX];
matrix A;
matrix operator*(matrix &a,matrix &b)
{
    matrix t;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            t.num[i][j]=0;
            for(k=0;k<n;k++)
                t.num[i][j]+=(a.num[i][k]*b.num[k][j]);
            t.num[i][j]%=1000;
        }
    return t;
}
void quickpower(int x)
{
    while(x)
    {
        if(x&1)
            res=res*A;
        x>>=1;
        A=A*A;
    }
}
void init()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            A.num[i][j]=map[i][j];
            res.num[i][j]=(i==j);
        }
    }
}
int main()
{

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        if(n==0&&m==0)
            break;
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            map[u][v]=1;
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int a,b,k;
            init();
            scanf("%d%d%d",&a,&b,&k);
            quickpower(k);
            printf("%d\n",res.num[a][b]%1000);
        }

    }
    return 0;
}
