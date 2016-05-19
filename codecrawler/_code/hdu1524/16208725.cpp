#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int mat[1010][1010];
int n;
int sg[1010];
int dfs(int d)
{
    if(sg[d]!=-1) return sg[d];
    bool g[1010]={0};
    for(int i=0;i<n;i++)
    {
        if(mat[d][i]==1)
        {
            g[dfs(i)]=1;
        }
    }
    for(int i=0;;i++)
    if(g[i]==0) return sg[d]=i;
}
int main()
{
    int m,x,y,q;
    while(scanf("%d",&n)!=EOF)
    {
        memset(mat,-1,sizeof(mat));
        memset(sg,-1,sizeof(sg));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==0)  sg[i]=0;
            while(x--)
            {
                scanf("%d",&y);
                mat[i][y]=1;
            }
        }
        scanf("%d",&m);
        while(1)
        {
            if(m==0) break;
            int ans=0;
            for(int i=0;i<m;i++)
            {
                scanf("%d",&q);
                if(sg[q]!=-1) ans^=sg[q];
                else
                ans^=dfs(q);
            }
            if(ans!=0) puts("WIN");
            else puts("LOSE");
            scanf("%d",&m);
        }
    }
}
