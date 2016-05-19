/****************************************************
ç®æ³å¼å¥:
å¨æåå¾Gä¸­,å¦æä¸¤ä¸ªé¡¶ç¹é´è³å°å­å¨ä¸æ¡è·¯å¾,ç§°ä¸¤ä¸ªé¡¶ç¹å¼ºè¿é;
å¦ææåå¾Gçæ¯ä¸¤ä¸ªé¡¶ç¹é½å¼ºè¿é,ç§°Gæ¯ä¸ä¸ªå¼ºè¿éå¾;
éå¼ºè¿éå¾æåå¾çæå¤§å¼ºè¿éå­å¾,ç§°ä¸ºå¼ºè¿éåé;

ç®æ³ä»ç»ï¼
Tarjanç®æ³æ¯åºäºå¯¹å¾æ·±åº¦ä¼åæç´¢çç®æ³,æ¯ä¸ªå¼ºè¿éåéä¸ºæç´¢æ ä¸­çä¸æ£µå­æ ;
æç´¢æ¶,æå½åæç´¢æ ä¸­æªå¤ççèç¹å å¥ä¸ä¸ªå æ ,åæº¯æ¶å¯ä»¥å¤æ­æ é¡¶å°æ ä¸­çèç¹æ¯å¦ä¸ºä¸ä¸ªå¼ºè¿éåé;

å®ä¹dfn(u)ä¸ºèç¹uæç´¢çæ¬¡åºç¼å·(æ¶é´æ³),low(u)ä¸ºuæuçå­æ è½å¤è¿½æº¯å°çææ©çæ ä¸­èç¹çæ¬¡åºå·;
åå½dfn(u)=low(u)æ¶,ä»¥uä¸ºæ ¹çæç´¢å­æ ä¸ææèç¹æ¯ä¸ä¸ªå¼ºè¿éåé;

Tarjanç®æ³è¿ç¨ä¸­,æ¯ä¸ªé¡¶ç¹é½è¢«è®¿é®äºä¸æ¬¡,ä¸åªè¿åºäºä¸æ¬¡å æ ,æ¯æ¡è¾¹ä¹åªè¢«è®¿é®äºä¸æ¬¡,åè¯¥ç®æ³çæ¶é´å¤æåº¦ä¸ºO(N+M);

ç®æ³ä¼ªä»£ç ï¼
(1)æ¾ä¸ä¸ªæ²¡æè¢«è®¿é®è¿çèç¹v;å¦åç®æ³ç»æ;
(2)åå§ådfn[v]ålow[v];
å¯¹äºvææçé»æ¥é¡¶ç¹u:
â å¦ææ²¡æè¢«è®¿é®è¿,åè½¬å°æ­¥éª¤â¡,åæ¶ç»´æ¤low[v];
â¡å¦æè¢«è®¿é®è¿,ä½æ²¡æå é¤,ç»´æ¤low[v];
å¦ælow[v]==dfn[v],é£ä¹è¾åºç¸åºçå¼ºè¿éåé;

ç®æ³ä¸¾ä¾:
HDU2767(Proving Equivalences);

é¢ç®å¤§æ:
æ±å¨å¾ä¸­æ·»å å¤å°æ¡è¾¹è½ä½¿å¾å¼ºè¿é;

ç®æ³ææ³:
é¦åç¨Tarjanç®æ³æ±åºå¾ä¸­å¼ºè¿éåé,ç¶åç¼©ç¹,ç»è®¡ç¼©ç¹åçå¾çåºå¥åº¦;
æåç­æ¡æ¯å¥åº¦ä¸º0çç¹ååºåº¦ä¸º0çç¹ä¸­æ°éæå¤§ç;
*****************************************************/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=50050;

struct Node
{
    int to;
    int next;
};

Node Edge[N];
int head[N];
int flag[N],dfn[N],low[N];
int sum,top,stack[N];
int in[N],out[N],Dindex;
int n,m,cnt;

inline void Add_Edge(int u,int v)
{
    Edge[cnt].to=v;
    Edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}

int dfs(int s)
{
    flag[s]=1;
    low[s]=dfn[s]=Dindex++;
    stack[++top]=s;
    for(int i=head[s]; i!=-1; i=Edge[i].next)
    {
        if(flag[Edge[i].to]==0)
            dfs(Edge[i].to);
        if(flag[Edge[i].to]==1)
            low[s]=min(low[Edge[i].to],low[s]);
    }
    if(dfn[s]==low[s])
    {
        ++sum;
        do
        {
            low[stack[top]]=sum;
            flag[stack[top]]=2;
        }
        while(stack[top--]!=s);
    }
    return 0;
}

int Tarjan()
{
    sum=top=0;
    Dindex=1;
    memset(flag,0,sizeof(flag));
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    for(int i=1; i<=n; i++)
    {
        if(flag[i]==0)
            dfs(i);
    }
    if(sum==1)
        return 0;
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=1; i<=n; i++)
    {
        for(int j=head[i]; j!=-1; j=Edge[j].next)
        {
            if(low[Edge[j].to]!=low[i])
            {
                out[low[i]]++;
                in[low[Edge[j].to]]++;
            }
        }
    }
    int sum1=0,sum2=0;
    for(int i=1; i<=sum; i++)
    {
       // printf("in[%d]=%d,out[%d]=%d\n",i,in[i],i,out[i]);
        if(in[i]==0)
            sum1++;
        if(out[i]==0)
            sum2++;
    }
    return max(sum1,sum2);
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            Add_Edge(u,v);
        }
        printf("%d\n",Tarjan());
    }
    return 0;
}
