#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXEDGE 54000
#define BREAK 1000000000
struct Edge{
    int flow;
    int cost;
    int point;
    int forhead;
}edge[MAXEDGE];
int path[210];
int que[220];
int code[210],num;
int weight[210];
int visit[210];
int in[210],out[210];
int AddEdge(int man,int son,int cost,int flow)
{
    edge[num].cost=cost,edge[num].flow=flow,edge[num].forhead=code[man],edge[num].point=son;
    code[man]=num;
    ++num;
    edge[num].cost=-cost,edge[num].flow=0,edge[num].forhead=code[son],edge[num].point=man;
    code[son]=num;
    ++num;
    return 0;
}
int FindAMinCostWay(int n,int sta,int end)
{
    int i,j;
    int l,r,temp;
    for(i=1;i<=n;i++)
        weight[i]=BREAK;
    l=0,r=1;
    que[0]=sta;
    weight[sta]=0;
    for(i=que[l];l!=r;i=que[l])
    {
        for(j=code[i],visit[i]=0;j!=-1;j=edge[j].forhead)
        {
            if(edge[j].flow&&(weight[edge[j].point]>(temp=weight[i]+edge[j].cost)))
            {
                weight[edge[j].point]=temp;
                path[edge[j].point]=j^1;
                if(visit[edge[j].point])continue;
                que[r]=edge[j].point;
                visit[edge[j].point]=1;
                ++r;
                if(r>=200)
                    r=0;
            }
        }
        ++l;
        if(l>=200)
            l=0;
    }
    if(weight[end]==BREAK)
        return 0;
    else
        return 1;///这里把我坑害惨了；因为weight[end]==0时也可能满足
}                ///，使得返回值即使是0不能排除存在一条最短路径
int main()
{
    int T,cas;
    int n,m,s,t;
    int u,v,a,b;
    int end,sta;
    int MaxFlow;
    int i;
    int ans,flow,cost;
    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        num=0;
        memset(code,-1,sizeof(code));
        ans=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            ans+=(a<b)?a:b;
            if(a<b)
                AddEdge(v,u,b-a,1),out[u]++,in[v]++;
            else
                AddEdge(u,v,a-b,1);
        }
        out[t]++,in[s]++;
        end=n+2,sta=n+1;
        MaxFlow=0;
        for(i=1;i<=n;i++)
        {
            if(out[i]>in[i])
                AddEdge(i,end,0,out[i]-in[i]),MaxFlow+=out[i]-in[i];
            if(out[i]<in[i])
                AddEdge(sta,i,0,in[i]-out[i]);
        }
        flow=0;
        while(1)
        {
            cost=FindAMinCostWay(n+2,sta,end);
            if(cost)
            {
                ++flow;
                ans+=weight[end];
                path[sta]=-1;
            for(i=end;path[i]!=-1;i=edge[path[i]].point)
                    edge[path[i]].flow+=1,edge[path[i]^1].flow-=1;
            }
            else
                break;
        }
        printf("Case %d: ",cas);
        if(MaxFlow==flow)
            printf("%d\n",ans);
        else
            printf("impossible\n");
    }
    return 0;
}