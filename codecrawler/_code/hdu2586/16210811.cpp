#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=40004;
struct node{
    int to,w;
    node(int a=0,int b=0){to=a;w=b;}
};
vector<node>e[maxn];
int f[maxn],dis[maxn],deep[maxn],p[maxn][20],n;
void dfs(int u,int pre,int t)
{
    int i,num;
    deep[u]=t;//æ·±åº¦
    f[u]=pre;//ç¶èç¹
    num=e[u].size();
    for(i=0;i<num;i++)
    {
        int v=e[u][i].to;
        if(v!=pre)
        {
            dis[v]=dis[u]+e[u][i].w;//è·ç¦»è·çè·ç¦»
            dfs(v,u,t+1);
        }
    }
}
void init()
{
    //p[i][j]è¡¨ç¤ºiç»ç¹çç¬¬2^jç¥å
    int i,j;
    for(j=0;(1<<j)<=n;j++)
        for(i=1;i<=n;i++)
        p[i][j]=-1;
    for(i=1;i<=n;i++)p[i][0]=f[i];
    for(j=1;(1<<j)<=n;j++)
        for(i=1;i<=n;i++)
        if(p[i][j-1]!=-1)
        p[i][j]=p[p[i][j-1]][j-1];//içç¬¬2^jç¥åå°±æ¯içç¬¬2^(j-1)ç¥åçç¬¬2^(j-1)ç¥å
}
int lca(int a,int b)//æè¿å¬å±ç¥å
{
    int i,j;
    if(deep[a]<deep[b])swap(a,b);
    for(i=0;(1<<i)<=deep[a];i++);
    i--;
    //ä½¿aï¼bä¸¤ç¹çæ·±åº¦ç¸å
    for(j=i;j>=0;j--)
        if(deep[a]-(1<<j)>=deep[b])
        a=p[a][j];
    if(a==b)return a;
    //åå¢æ³ï¼æ¯æ¬¡åä¸è¿æ·±åº¦2^jï¼æ¾å°æè¿å¬å±ç¥åçå­ç»ç¹
    for(j=i;j>=0;j--)
    {
        if(p[a][j]!=-1&&p[a][j]!=p[b][j])
        {
            a=p[a][j];
            b=p[b][j];
        }
    }
    return f[a];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,i,a,b,c,ans;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)e[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            e[a].push_back(node(b,c));
            e[b].push_back(node(a,c));
        }
        dis[1]=0;
        dfs(1,-1,0);//æ¾å°åç¹çæ·±åº¦ååç¹çç¶èç¹ä»¥åè·ç¦»æ ¹çè·ç¦»
        init();     //åå§åä¸ªç¹ç2^jç¥åæ¯è°    
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            ans=dis[a]+dis[b]-2*dis[lca(a,b)];
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
    æè¿å¬å±ç¥ålcaï¼å¨çº¿ç®æ³/åå¢æ³ï¼æ¨¡æ¿é¢ãå¥å«äººæ¨¡æ¿èªå·±æ²äºéï¼ç°å¨è¿è¦åé¡¾ä¸é»æ¥è¡¨ï¼åãã
    ç¨vectorï¼åç°çæ äºï¼æ±ä¸ä¸ªãã
    ç¨#pragma comment(linker, "/STACK:1024000000,1024000000") å¼ä¸ªææ å¼å¤§ç¹å§ããhduå¯ä»¥ï¼å«çå°æ¹å°±ä¸æ¸æ¥äº
*/