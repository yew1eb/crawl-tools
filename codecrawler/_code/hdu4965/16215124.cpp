#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8
#define INF 0x7fffffff
#define PI acos(-1.0)
#define seed 31//131,1313
typedef long long LL;
typedef unsigned long long ULL;
#define MOD 6
#define maxn 1005
#define maxm 1005
using namespace std;
struct Matrix
{
    int n,m;
    int a[maxn][maxm];
    void init()
    {
        n=m=0;
        memset(a,0,sizeof(a));
    }
    Matrix operator +(const Matrix &b) const
    {
        Matrix tmp;
        tmp.n=n;
        tmp.m=m;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                tmp.a[i][j]=a[i][j]+b.a[i][j];
        return tmp;
    }
    Matrix operator -(const Matrix &b) const
    {
        Matrix tmp;
        tmp.n=n;
        tmp.m=m;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                tmp.a[i][j]=a[i][j]-b.a[i][j];
        return tmp;
    }
    Matrix operator *(const Matrix &b) const
    {
        Matrix tmp;
        tmp.n=n;
        tmp.m=b.m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b.m;j++)
                tmp.a[i][j]=0;
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<b.m; j++)
                for(int k=0; k<m; k++)
                {
                    tmp.a[i][j]+=a[i][k]*b.a[k][j];
                }
        for(int i=0; i<n; i++)
            for(int j=0; j<b.m; j++)
                tmp.a[i][j]%=MOD;
        return tmp;
    }
    void Copy(const Matrix &x)
    {
        n=x.n;
        m=x.m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=x.a[i][j];
    }
};//åªæå½ç©éµAçåæ°ä¸ç©éµBçè¡æ°ç¸ç­æ¶AÃBæææä¹
Matrix M_quick_pow(Matrix m,int k)
{
    Matrix tmp;
    tmp.n=m.n;
    tmp.m=m.m;//m=næè½åå¿«éå¹
    for(int i=0; i<tmp.n; i++)
    {
        for(int j=0; j<tmp.n; j++)
        {
            if(i==j)
                tmp.a[i][j]=1;
            else tmp.a[i][j]=0;
        }
    }
    while(k)
    {
        if(k&1)
            tmp.Copy(tmp*m);
        k>>=1;
        m.Copy(m*m);
    }
    return tmp;
}
Matrix a,b;
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k))
    {
        if(n==0&&k==0)
            break;
        a.n=n;
        a.m=k;
        for(int i=0; i<a.n; i++)
            for(int j=0; j<a.m; j++)
                scanf("%d",&a.a[i][j]);
        b.n=k;
        b.m=n;
        for(int i=0; i<b.n; i++)
            for(int j=0; j<b.m; j++)
                scanf("%d",&b.a[i][j]);
        Matrix e,c;
        c.Copy(b*a);
        c.Copy(M_quick_pow(c,n*n-1));
        e.Copy(a*c);
        e.Copy(e*b);
        LL ans=0;
        for(int i=0;i<e.n;i++)
        {
            for(int j=0;j<e.m;j++)
            {
                ans+=(LL)(e.a[i][j]);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
