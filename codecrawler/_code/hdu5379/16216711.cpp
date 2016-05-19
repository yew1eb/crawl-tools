#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
const LL base=1e9+7;
vector<int> tree[maxn];
int T,n,x,y,tt=0;
LL ans[maxn],f[maxn],flag;

void dfs(int x,int fa)
{
    if (!flag) return ;
    LL a=tree[x].size(),b=0;
    ans[x]=1;
    for (int i=0;i<a;i++)
    if (tree[x][i]!=fa)
    {
        dfs(tree[x][i],x);
        if (!flag) return ;
        ans[x]=(ans[x]*ans[tree[x][i]])%base;
        b+=(tree[tree[x][i]].size()>1)?1:0;
    }
    if (b>2) {flag=0; return ;}
    ans[x]=ans[x]*f[a-1-b]%base;
    if (b) ans[x]=(ans[x]<<1)%base;
}

int main()
{
    for (LL i=f[0]=1;i<=100000;i++) f[i]=f[i-1]*i%base;
    scanf("%d",&T);
    while (T--)
    {
        flag=1;
        scanf("%d",&n);
        if (n==1){ printf("Case #%d: 1\n",++tt); continue;}
        for (int i=1;i<=n;i++) tree[i].clear();
        tree[1].push_back(1);
        for (int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        dfs(1,1);
        printf("Case #%d: %lld\n",++tt,flag?((ans[1]<<1)%base):flag);
    }
    return 0;
}