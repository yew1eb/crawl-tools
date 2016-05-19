#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
using namespace std;
#define max_n 1005
#define max_e 250002
#define inf 99999999

int stack[max_n],top;//æ 
int isInStack[max_n];//æ¯å¦å¨æ å
int low[max_n],dfn[max_n],tim;//ç¹çlowï¼dfnå¼ï¼timeä»1å¼å§
int node_id;
int head[max_n],s_edge;//é»æ¥è¡¨å¤´  s_edgeä»1å¼å§
int gro_id[max_n];
int n,m;
int val[max_n];
int in[max_n];
struct Node
{
    int to;
    int next;
} edge[max_e];
void init()
{
    top=0;
    node_id=0;
    memset(isInStack,0,sizeof(isInStack));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    tim=0;
    memset(in,0,sizeof(in));
    memset(head,0,sizeof(head));
    s_edge=0;
    memset(edge,0,sizeof(edge));
}
void addedge(int u,int v)
{
    s_edge++;
    edge[s_edge].to=v;
    edge[s_edge].next=head[u];
    head[u]=s_edge;
}
int min(int a,int b)
{
    if(a<b)return a;
    else return b;
}
void tarjan(int u)
{
    //lowå¼ä¸ºuæuçå­æ è½å¤è¿½æº¯å°å¾ææ©çæ ä¸­èç¹çæ¬¡åºå·
    stack[top++]=u;
    isInStack[u]=1;
    dfn[u]=++tim; //è®°å½ç¹uåºç°çè®°å½ï¼å¹¶æ¾å¨æ ä¸­
    low[u]=tim;

    int e,v;
    for(e=head[u]; e; e=edge[e].next) //å¦ææ¯å¶å­èç¹ï¼head[u]=0,edge[e].next=0;
    {
        v=edge[e].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(isInStack[v])
            low[u]=min(low[u],dfn[v]);
    }
    int j;
    if(dfn[u]==low[u])
    {
        node_id++;
        while(j=stack[--top])
        {
            isInStack[j]=0;
            gro_id[j]=node_id;
            if(j==u)break;
        }
    }
}
void find()
{
    for(int i = 1 ; i <=n ; ++i)
    {
        if(!dfn[i])
        {
            tarjan(i);
        }
    }
}
vector<int> vec[max_n];
int main()
{
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
            vec[i].clear();
        }
        for(int i = 0 ; i <m ; ++i)
        {
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
            addedge(a,b);
        }
        find();
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<vec[i].size(); j++)//æ±å¥åº¦ä¸ºé¶çç¹
            {
                if(gro_id[i]!=gro_id[vec[i][j]])
                    in[gro_id[vec[i][j]]]++;
            }
        }

        int sum=0,sum1=0;
        for(int i=1; i<=node_id; i++)
        {
            if(in[i]==0)
            {
                int mm=inf;
                for(int j=1; j<=n; j++)
                {
                    if(gro_id[j]==i)
                    {
                        if(mm>val[j])
                            mm=val[j];
                    }
                }
                sum++;
                sum1+=mm;
            }
        }
        printf("%d %d\n",sum,sum1);
    }
    return 0;
}
