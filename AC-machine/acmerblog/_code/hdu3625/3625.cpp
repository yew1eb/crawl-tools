#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 21;
#define LL long long

LL str[maxn][maxn];

void init_strling()
{
    str[1][1]=1;
    for(int i=1;i<maxn;i++)
        str[i][0]=0;
    for(int i=2;i<maxn;i++)
    {
        for(int j=1;j<=i;j++)
        {
            str[i][j] = (i-1)*str[i-1][j]+str[i-1][j-1];
        }
    }
}

LL cal(int n,int k)
{
    LL a1=0;
    LL a2=0;
    for(int i=1;i<=k;i++)
        a1+=str[n][i];
    for(int i=1;i<=k-1;i++)
        a2+=str[n-1][i];
    //printf("a1 %d a2 %d\n",a1,a2);
    return a1-a2;
}

LL cal2(int n)
{
    LL a1=1;
    for(int i=1;i<=n;i++)
        a1*=i;
    return a1;
}

int main()
{
    int t;
    scanf("%d",&t);
    init_strling();
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        LL a1=cal(n,k);
        LL a2=cal2(n);
        printf("%.4lf\n",a1*1.0/a2);
    }
    return 0;
}



