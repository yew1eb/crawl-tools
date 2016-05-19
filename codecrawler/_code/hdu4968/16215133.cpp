#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>

#define eps 1e-8
#define op operator
#define MOD  10009
#define MAXN  5010

#define FOR(i,a,b)  for(int i=a;i<=b;i++)
#define FOV(i,a,b)  for(int i=a;i>=b;i--)
#define REP(i,a,b)  for(int i=a;i<b;i++)
#define REV(i,a,b)  for(int i=a-1;i>=b;i--)
#define MEM(a,x)    memset(a,x,sizeof a)
#define ll __int64

using namespace std;

double func(int m)
{
    if(m<60)   return 0;
    if(m<70)   return 2.0;
    if(m<75)   return 2.5;
    if(m<80)   return 3.0;
    if(m<85)   return 3.5;
    else return 4.0;
}

int num,n;
int x[MAXN];


void max_gpa()
{
    int sum=num*n;
    for(int i=0;i<n;i++)
        x[i]=60;
    sum-=n*60;
    double maxav=0.0;
    for(int i=0;i<n;i++)
    {
        int tmp=min(sum,85-60);
        x[i]+=tmp;
        sum-=tmp;
        maxav+=func(x[i]);
    }
    printf("%.4lf\n",maxav/(n*1.0));
}

void min_gpa()
{
    int sum=num*n;
    sum-=n*69;
    double minav=0.0;
    if(sum<=0)
    {
        printf("%.4lf ",2.0);
        return;
    }
    for(int i=0;i<n;i++)
        x[i]=69;
    for(int i=0;i<n;i++)
    {
        int tmp=min(100-69,sum);
        sum-=tmp;
        x[i]+=tmp;
        minav+=func(x[i]);
    }
    printf("%.4lf ",minav/(n*1.0));
}

int main()
{
//freopen("ceshi.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d%d",&num,&n);
        min_gpa();
        max_gpa();

    }
    return 0;
}
