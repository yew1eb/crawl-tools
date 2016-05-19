#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<map>
#include<memory.h>
#define ll __int64
using namespace std;
double e[100010];
int f[100010];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<=n;i++) e[i]=0;
        memset(f,-1,sizeof(f));
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            f[a]=b;
        }
        e[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            if(f[i]!=-1) e[i]=e[f[i]];
            else
            {
                for(int j=1;j<=6;j++)
                {
                    if(i+j<=n)
                    e[i]+=(1.0/6)*e[i+j];
                    else break;
                }
                e[i]+=1.0;
            }
        }
        printf("%.4lf\n",e[0]);

    }
}
