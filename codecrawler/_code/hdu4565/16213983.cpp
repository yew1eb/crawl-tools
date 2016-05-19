#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include<math.h>
using namespace std;
#define ll long long

int aa,b,n,m;

struct matrix
{
    ll a[2][2];
} origin,res;


matrix multiply(matrix x,matrix y)
{
    matrix temp;
    memset(temp.a,0,sizeof(temp.a));
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                temp.a[i][j]+=(((x.a[i][k])%m)*((y.a[k][j])%m))%m;
            }
            temp.a[i][j]%=m;
        }
    }
    return temp;
}

void init()
{
    origin.a[0][0]=(2*(aa%m))%m;
    origin.a[0][1]=(b%m-((aa%m)*(aa%m))%m+m)%m;
    origin.a[1][0]=1;
    origin.a[1][1]=0;
    memset(res.a,0,sizeof(res.a));
    res.a[0][0]=res.a[1][1]=1;
}

void calc(int N)
{
    int n=N;
    while(n)
    {
        if(n&1)
            res=multiply(res,origin);
        n>>=1;
        origin=multiply(origin,origin);
    }
    matrix tmp,tmp2;
    tmp2.a[0][0]=(((2*(aa%m)*(aa%m))%m)%m+2*(b%m))%m;

    tmp2.a[0][1]=0;
    tmp2.a[1][0]=(2*(aa%m))%m;
    tmp2.a[1][1]=0;
    if(N==0)
        printf("%lld\n",tmp2.a[0][0]%m);
    else
    {
        tmp=multiply(res,tmp2);
        printf("%lld\n",tmp.a[0][0]%m);
    }
}
int main()
{
    while(cin>>aa>>b>>n>>m)
    {
        if(n==1)
        {
            printf("%lld\n", (ll)ceil((aa*1.0+sqrt(b*1.0))*1.0)%m);
        }
        else
        {
            init();
            calc(n-2);
        }
    }
    return 0;
}
/*
2 3 10 2013
2 3 2 2013
2 2 1 2013
*/


