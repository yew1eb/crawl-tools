#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int num,val;
}Tree;

vector <Tree> tree[105];
int dp[105][505];
int ok,n,T;
int w[105];

void DFS1(int t,int p,int tag)
{
    int i,k;
    if (t==n)
    {
        ok=1;
    }
    if (ok==1)
    {
        if (p==-1) return;
        swap(tree[p][tag],tree[p][tree[p].size()-1]);
        return;
    }
    for (i=0;i<tree[t].size();i++)
    {
        k=tree[t][i].num;
        if (k==p) continue;
        DFS1(k,t,i);
        if (ok==1)
        {
            if (p==-1) return;
            swap(tree[p][tag],tree[p][tree[p].size()-1]);
            return;
        }
    }
}

void DFS2(int t,int p,int tag)
{
    int i,k,j;
    if (p==-1)
    {
        for (i=0;i<=T;i++)
        {
            dp[t][i]=w[t];
        }
    }
    else
    {
        for (j=tree[p][tag].val;j<=T;j++)
        {
            if (dp[p][j-tree[p][tag].val]!=-1) dp[t][j]=dp[p][j-tree[p][tag].val]+w[t];
        }
    }
    for (i=0;i<tree[t].size();i++)
    {
        k=tree[t][i].num;
        if (k==p) continue;
        DFS2(k,t,i);
    }
    if (p==-1) return;
    for (i=tree[p][tag].val;i<=T;i++)
    {
        dp[p][i]=max(dp[p][i],dp[t][i-tree[p][tag].val]);
    }
}

int main()
{
    int i,j,x,y,z,s;
    Tree tag;
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        ok=0;
        for (i=1;i<=n;i++)
        {
            tree[i].clear();
        }
        for (i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            tag.num=y;
            tag.val=z;
            tree[x].push_back(tag);
            tag.num=x;
            tree[y].push_back(tag);
        }
        DFS1(1,-1,-1);
        memset(dp,-1,sizeof(dp));
        dp[1][0]=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        DFS2(1,-1,-1);
        s=-1;
        for (i=0;i<=T;i++)
        {
            s=max(s,dp[n][i]);
        }
        if (s!=-1) printf("%d\n",s);
        else printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
    }
    return 0;
}
