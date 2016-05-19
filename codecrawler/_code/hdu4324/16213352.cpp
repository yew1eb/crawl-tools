#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int N=2005;

int head[N],low[N];
int dfn[N],stack[N];
int ans[N];
bool temp[N];
char str[N][N];
int index,m,flag;

typedef struct
{
    int to;
    int next;
}Node;

Node map[N*N];

void add(int u,int v)
{
    map[index].to=v;
    map[index].next=head[u];
    head[u]=index++;
}

void Tarbfs(int k,int lay,int &scc_num)
{
    int t;
    temp[k]=1;
    low[k]=lay;
    dfn[k]=lay;
    stack[m++]=k;
    for(int i=head[k];i!=-1;i=map[i].next)
    {
        t=map[i].to;
        if(!dfn[t])
        {
             Tarbfs(t,++lay,scc_num);
             if(flag) return;
             low[k]=min(low[k],low[t]);
        }
        if(temp[t])
        {
             low[k]=min(low[k],dfn[t]);
        }

    }
    if(dfn[k]==low[k])
    {
        ++scc_num;
        while(1)
        {
            t=stack[--m];
            temp[t]=0;
            ans[scc_num]++;
            if(ans[scc_num]>=3)
            {
                flag=1;
                return;
            }
            if(t==k) break;
        }
    }
    if(flag) return;
}

int Tarjan(int n)
{
    int scc_num=0,lay=1;
    m=0;
    memset(temp,0,sizeof(temp));
    memset(low,0,sizeof(low));
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
            Tarbfs(i,lay,scc_num);
        if(flag) break;
    }
    return scc_num;
}

int main()
{
    int i,j,n,t=1,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(dfn,0,sizeof(dfn));
        memset(ans,0,sizeof(ans));
        memset(head,-1,sizeof(head));
        memset(stack,0,sizeof(stack));
        index=flag=0;
        for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(str[i][j]=='1')
                {
                    add(i,j);
                }
            }
        }
        printf("Case #%d: ",t++);
        Tarjan(n);
        if(flag)   puts("Yes");
        else       puts("No");
    }
    return 0;
}
