#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#define M 1005
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int dep;
int a[6][6];
int h()
{
    int r=0,c=0;
    for(int i=1;i<=4;i++)
    {
        int tot=4;
        int ha[5]={0};
        for(int j=1;j<=4;j++)
        {
            if(ha[a[i][j]]) tot--;
            ha[a[i][j]]++;
        }
        r=max(tot-1,r);
    }
    for(int i=1;i<=4;i++)
    {
        int tot=4;
        int ha[5]={0};
        for(int j=1;j<=4;j++)
        {
            if(ha[a[j][i]]) tot--;
            ha[a[j][i]]++;
        }
        c=max(tot-1,c);
    }
    return min(r,c);
}
void row_l(int k)
{
    int tmp=a[k][1];
    for(int i=1;i<=3;i++)
    {
        a[k][i]=a[k][i+1];
    }
    a[k][4]=tmp;
}
void row_r(int k)
{
    int tmp=a[k][4];
    for(int i=4;i>=2;i--)
    {
        a[k][i]=a[k][i-1];
    }
    a[k][1]=tmp;
}
void column_u(int k)
{
    int tmp=a[1][k];
    for(int i=1;i<=3;i++)
    {
        a[i][k]=a[i+1][k];
    }
    a[4][k]=tmp;
}
void column_d(int k)
{
    int tmp=a[4][k];
    for(int i=4;i>=2;i--)
    {
        a[i][k]=a[i-1][k];
    }
    a[1][k]=tmp;
}
bool endr()
{
    for(int i=1;i<=4;i++)
    {
        int tot=4;
        int ha[5]={0};
        for(int j=1;j<=4;j++)
        {
            if(ha[a[i][j]]) tot--;
            ha[a[i][j]]++;
        }
        if(tot!=1) return false;
    }
    return true;
}
bool endc()
{
    for(int i=1;i<=4;i++)
    {
        int tot=4;
        int ha[5]={0};
        for(int j=1;j<=4;j++)
        {
            if(ha[a[j][i]]) tot--;
            ha[a[j][i]]++;
        }
        if(tot!=1) return false;
    }
    return true;
}
bool dfs(int now)
{
    if(now+h()>dep) return false;
    if(endr()||endc()) return true;
    for(int i=1;i<=4;i++)
    {
        row_l(i);
        if(dfs(now+1)) return true;
        row_r(i);

        row_r(i);
        if(dfs(now+1)) return true;
        row_l(i);
    }
    for(int j=1;j<=4;j++)
    {
        column_u(j);
        if(dfs(now+1)) return true;
        column_d(j);

        column_d(j);
        if(dfs(now+1)) return true;
        column_u(j);
    }
    return false;
}
void debug()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            printf("%d ",a[i][j]);
        }
        puts("");
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(dep=0;dep<=5;dep++)
        {
            if(dfs(0)) break;
        }
        printf("%d\n",dep==6?-1:dep);
    }
    return 0;
}