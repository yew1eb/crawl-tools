/*
 *é¢ç®å¤§æ:
 *é¢ç®ä¸ºå¤©ææå­,ä¸å¤è¯´;
 *
 *ç®æ³ææ³:
 *é¢ç®å¾ææ¾è¦æ±çæ¯ä¸ä¸ªLCAé®é¢;
 *å³è¯¢é®ä»Aå°Bçéè¦çæ­¥æ°,å³é¦åä»Aå°è¾¾AåBçæè¿å¬å±ç¥åéè¦çæ­¥æ°+1å°±OKäº;
 *
 *ç®æ³æ­¥éª¤:
 *ç±äºæ¯æåå¾,æä»¥å¼å§å¯ä»¥ç¨ä¸ä¸ªæ°ç»indè®°å½æ¯ä¸ªé¡¶ç¹çå¥åº¦;
 *å¦æè¯¥é¡¶ç¹çå¥åº¦ä¸º0,åå¯ä»¥å½åæ ¹èç¹,å©ç¨dfsæ±åºæ ä¸­æ¯ä¸ªé¡¶ç¹çæ·±åº¦d;
 *åä»uå°vçæ­¥æ°ans=d[u]-lca(u,v)+1,å½ç¶è¦èèå ä¸ªç¹æ®æåµ;
**/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

const int N=400010;

int p[N];//å¹¶æ¥éçç¶èç¹
int ind[N];//æ±é¡¶ç¹çå¥åº¦,å¤æ­æ ¹èç¹
int head[N];
int qhead[N];//è¯¢é®
bool visit[N];

int d[N];

struct node
{
    int to;
    int w;
    int next;
    int lca;
    int num;
};

struct query//è®°å½æ¥è¯¢
{
    int u;
    int v;
    int lca;
} q[N];

node edge[N];
node qedge[N];//è¯¢é®è¾¹

int n,m;
int cnt1,cnt2;
int cnt;

map<string,int> Map;

int get_num(string s)//è¿åæ¯ä¸ªäººå¯¹åºç»ç¹
{
    if(Map.find(s)==Map.end())//æ²¡ææç´¢å°è¯¥é®å¼
    {
        Map[s]=++cnt;//å¯¹åºå»ºå¾
    }
    // cout<<"  Map["<<s<<"]=="<<Map[s]<<endl;
    return Map[s];
}

inline void Addedge(int u,int v,int w)
{
    edge[cnt1].w=w;
    edge[cnt1].to=v;
    edge[cnt1].next=head[u];
    head[u]=cnt1;
    cnt1++;

    edge[cnt1].w=w;
    edge[cnt1].to=u;
    edge[cnt1].next=head[v];
    head[v]=cnt1;
    cnt1++;
}

inline void Addqedge(int u,int v,int num)
{
    qedge[cnt2].num=num;
    qedge[cnt2].to=v;
    qedge[cnt2].next=qhead[u];
    qhead[u]=cnt2;
    cnt2++;

    qedge[cnt2].num=num;
    qedge[cnt2].to=u;
    qedge[cnt2].next=qhead[v];
    qhead[v]=cnt2;
    cnt2++;
}


void dfs(int u,int f,int w)
{
    d[u]=w;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==f)
            continue;
        dfs(v,u,w+edge[i].w);
    }
}

int Find(int x)
{
    if(p[x]!=x)
        p[x]=Find(p[x]);
    return p[x];
}


void Tarjan_LCA(int u)//ç¦»çº¿LCAç®æ³
{
    p[u]=u;
    visit[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        if(!visit[edge[i].to])
        {
            Tarjan_LCA(edge[i].to);
            p[edge[i].to]=u;
        }
    }

    for(int i=qhead[u]; i!=-1; i=qedge[i].next)
    {
        if(visit[qedge[i].to])
        {
            qedge[i].lca=Find(qedge[i].to);
            qedge[i^1].lca=qedge[i].lca;
            //printf("%då%dçæè¿å¬å±ç¥åä¸º: %d\n",u,qedge[i].to,qedge[i].lca);
            q[qedge[i].num].lca=qedge[i].lca;
        }
    }
}

void Solve()
{
    for(int i=0; i<=n; i++)
    {
        p[i]=i;
    }
    memset(head,-1,sizeof(head));
    memset(qhead,-1,sizeof(qhead));
    memset(visit,0,sizeof(visit));
    memset(ind,0,sizeof(ind));
    cnt=cnt1=cnt2=0;
    int u,v,w;
    string s1,s2;
    Map.clear();
    for(int i=1; i<n; i++)
    {
        cin>>s1>>s2;
        u=get_num(s1);
        v=get_num(s2);
        Addedge(u,v,1);
        ind[u]++;
    }

    for(int i=0; i<m; i++)
    {
        cin>>s1>>s2;
        u=get_num(s1);
        v=get_num(s2);
        /*cout<<s1;
        printf("==%d\n",u);
        cout<<s2;
        printf("==%d\n",v);*/
        Addqedge(u,v,i);
        q[i].u=u;
        q[i].v=v;
    }

    int root=0;
    for (int i=1; i<=n; i++)
    {
        if(ind[i]==0)
        {
            root=i;
        }
    }
    //printf("root==%d\n",root);
    dfs(root,-1,0);
    //for(int i=1; i<=n; i++)
          //printf("d[%d]==%d\n",i,d[i]);
    Tarjan_LCA(root);
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d%d",&n,&m);
        Solve();

        for (int i=0; i<m; i++)
        {
            int ans=0;
            ans=d[q[i].u]-d[q[i].lca];
            if(q[i].lca!=q[i].v)
                ans++;
            if(q[i].u==q[i].v)
                ans=0;
            printf("%d\n",ans);
        }

    }
    return 0;
}
