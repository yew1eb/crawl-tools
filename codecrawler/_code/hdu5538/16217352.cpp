#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#define exp 1e-10
using namespace std;
const int N = 55;
const int M = 2010;
const int inf = 2147483647;
const int mod = 2009;
int s[N][N];
int main()
{
    int t,n,m,k,c,i,j;
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&m);
        for(k=0,i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&s[i][j]);
                if(s[i][j]>0)
                    k++;
            }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                c=s[i][j]-s[i][j+1];
                if(c>0)
                    k+=c;
            }
        for(i=1;i<=n;i++)
            for(j=m;j>=1;j--)
            {
                c=s[i][j]-s[i][j-1];
                if(c>0)
                    k+=c;
            }
        for(j=1;j<=m;j++)
            for(i=1;i<=n;i++)
            {
                c=s[i][j]-s[i+1][j];
                if(c>0)
                    k+=c;
            }
        for(j=1;j<=m;j++)
            for(i=n;i>=1;i--)
            {
                c=s[i][j]-s[i-1][j];
                if(c>0)
                    k+=c;
            }
        printf("%d\n",k);
    }
    return 0;
}