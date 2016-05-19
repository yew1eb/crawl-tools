/*
 *é¢ç®å¤§æï¼
 *ç»ä½ ä¸ä¸ªDAGå¾,é®ä½ æå¤è½æ·»å å¤å°æ¡è¾¹ä½¿å¾è¿ä¸ªDAGå¾ä¾ç¶ä¸æ¯å¼ºèéç;
 *
 *ç®æ³ææ³ï¼
 *å¼ºè¿é+ç¼©ç¹
 *æç»æ·»å å®è¾¹çå¾,è¯å®å¯ä»¥åæä¸¤ä¸ªé¨XåY,å¶ä¸­åªæXå°Yçè¾¹æ²¡æYå°Xçè¾¹;
 *é£ä¹è¦ä½¿å¾è¾¹æ°å°½å¯è½çå¤,åXé¨è¯å®æ¯ä¸ä¸ªå®å¨å¾,Yé¨ä¹æ¯,åæ¶Xé¨ä¸­æ¯ä¸ªç¹å°Yé¨çæ¯ä¸ªç¹é½æä¸æ¡è¾¹;
 *åè®¾Xé¨æxä¸ªç¹,Yé¨æyä¸ªç¹,åx+y=n;
 *åæ¶è¾¹æ°F=x*y+x*(x-1)+y*(y-1),ç¶åå»æå·²ç»æäºçè¾¹m,åä¸ºç­æ¡;
 *å½x+yä¸ºå®å¼æ¶,äºèè¶æ¥è¿,x*yè¶å¤§ï¼æä»¥è¦ä½¿å¾è¾¹æ°æå¤,é£ä¹Xé¨åYé¨çç¹æ°çä¸ªæ°å·®è·å°±è¦è¶å¤§;
 *å¯¹äºç»å®çæåå¾ç¼©ç¹,å¯¹äºç¼©ç¹åçæ¯ä¸ªç¹,å¦æå®çåºåº¦æèå¥åº¦ä¸º0,é£ä¹å®ææå¯è½æä¸ºXé¨æèYé¨;
 *ç¶åæ¾åºæå¤§å¼å³å¯;
**/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200010;
const int M=400010;
const int INF=0xffffffff;

typedef long long LL;

struct Edge
{
    int to,next;
} edge[M];

LL n,m,cnt,head[N];
LL dep,top,atype;

LL dfn[N],low[N],vis[N],stack[N],belong[N],in[N],out[N],sum[N];

void addedge(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void Tarjan(int u)
{
    dfn[u]=low[u]=++dep;
    stack[top++]=u;
    vis[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    int j;
    if(dfn[u]==low[u])
    {
        atype++;
        do
        {
            j=stack[--top];
            belong[j]=atype;
            sum[atype]++;   //è®°å½æ¯ä¸ªè¿éåéä¸­ç¹çä¸ªæ°
            vis[j]=0;
        }
        while(u!=j);
    }
}

void solve()
{
    if(n==1)
    {
        puts("-1");
        return;
    }
    cnt=dep=top=atype=0;
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(belong,0,sizeof(belong));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(sum,0,sizeof(sum));

    int u,v;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&u,&v);
        addedge(u,v);
    }

    for(int i=1; i<=n; i++)
        if(!dfn[i])
            Tarjan(i);
    if(atype==1)
    {
        puts("-1");
        return;
    }
    for(int u=1; u<=n; u++)
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(belong[u]!=belong[v])
            {
                out[belong[u]]++;
                in[belong[v]]++;
            }
        }
    LL ans=0,tmp;
    for(int i=1; i<=atype; i++)
        if(in[i]==0 || out[i]==0)     //æ¾åºåº¦æèå¥åº¦ä¸º0çç¹ï¼åå«èç¹æ°æå°çé£ä¸ªç¹
        {
            tmp=sum[i];//ä»¤å®ä¸ºä¸ä¸ªé¨ï¼å¶å®ææç¹å èµ·æ¥åå¦ä¸ä¸ªé¨ï¼å°±å¯ä»¥å¾å°æå¤è¾¹æ°çå¾äº
            ans=max(ans,tmp*(tmp-1)+(n-tmp)*(n-tmp-1)+tmp*(n-tmp)-m);
        }
    printf("%d\n",ans);
}

int main()
{

    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int t1,t2=0;
    scanf("%d",&t1);
    while(t1--)
    {
        t2++;
        printf("Case %d: ",t2);
        scanf("%d%d",&n,&m);
        solve();
    }
    return 0;
}
