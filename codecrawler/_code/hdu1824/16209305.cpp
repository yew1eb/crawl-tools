#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#define maxn 6005

using namespace std;

int n,m,Index,cnt;
int belong[maxn],dfn[maxn],low[maxn];
bool used[maxn],instack[maxn];
vector<int>map[maxn];
stack<int>s;

void init()
{
    int i;
    for(i=0;i<maxn;i++)
        map[i].clear();
    while(!s.empty())
        s.pop();
    memset(used,0,sizeof(used));
    memset(instack,0,sizeof(instack));
    memset(dfn,-1,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    Index=0,cnt=0;
}

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

void tarjan(int u)
{
    int i,v;
    Index++;
    dfn[u]=Index;
    low[u]=Index;
    used[u]=true;
    instack[u]=true;
    s.push(u);
    for(i=0;i<map[u].size();i++)
    {
        v=map[u][i];
        if(!used[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        do
        {
            v=s.top();
            s.pop();
            belong[v]=cnt;
            instack[v]=false;
        }
        while(u!=v);
    }
}

int main()
{
    int i,a,b,c,N;
    while(scanf("%d%d",&N,&m)!=EOF)
    {
        init();
        n=N*3;
        for(i=1;i<=N;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a+n].push_back(b);
            map[a+n].push_back(c);
            map[b+n].push_back(a);
            map[c+n].push_back(a);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            map[a].push_back(b+n);
            map[b].push_back(a+n);
        }
        for(i=0;i<n;i++)
            if(dfn[i]==-1)
                tarjan(i);
        bool flag=true;
        for(i=0;i<n;i++)
            if(belong[i]==belong[i+n])
            {
                flag=false;
                printf("no\n");
                break;
            }
        if(flag)
            printf("yes\n");
    }
    return 0;
}