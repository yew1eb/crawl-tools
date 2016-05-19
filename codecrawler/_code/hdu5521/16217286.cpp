#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre(){freopen("c://test//input.in","r",stdin);freopen("c://test//output.out","w",stdout);}
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T> inline void gmax(T &a,T b){if(b>a)a=b;}
template <class T> inline void gmin(T &a,T b){if(b<a)a=b;}
const int N=1e5+2e6+10,M=3e6+10,Z=1e9+7,ms63=1061109567;
int casenum,casei;
int id;
int first[N],w[M],c[M],nxt[M];
LL f[N],F[N];
bool e[N];
struct node
{
    int x;LL v;
    node(){}
    node(int x_,LL v_){x=x_;v=v_;}
    bool operator < (const node& b)const{return v>b.v;}
};
void ins(int x,int y,int z)
{
    id++;
    w[id]=y;
    c[id]=z;
    nxt[id]=first[x];
    first[x]=id;
}
priority_queue<node>q;
void inq(int x,LL dis)
{
    if(dis>=f[x])return;
    f[x]=dis;
    q.push(node(x,dis));
}
void dijkstra(int st)
{
    MS(f,63);
    MS(e,0);
    inq(st,0);
    q.push(node(st,0));
    while(!q.empty())
    {
        int x=q.top().x;q.pop();
        if(e[x])continue;e[x]=1;
        for(int z=first[x];z;z=nxt[z])inq(w[z],f[x]+c[z]);
    }
}
int main()
{
    scanf("%d",&casenum);
    for(casei=1;casei<=casenum;casei++)
    {
        MS(first,0);id=1;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int dis,g,x;
            scanf("%d%d",&dis,&g);
            int in=n+i;
            int out=n+m+i;
            ins(in,out,dis);
            while(g--)
            {
                scanf("%d",&x);
                ins(x,in,0);
                ins(out,x,0);
            }
        }
        dijkstra(1);
        MC(F,f);
        dijkstra(n);
        LL ans=1e18;
        int ed;
        for(int i=1;i<=n;i++)
        {
            gmax(F[i],f[i]);
            if(F[i]<=ans)
            {
                ans=F[i];
                ed=i;
            }
        }
        if(ans==1e18)printf("Case #%d: Evil John\n",casei);
        else
        {
            printf("Case #%d: %lld\n",casei,ans);
            for(int i=1;i<ed;i++)if(F[i]==ans)printf("%d ",i);
            printf("%d\n",ed);
        }
    }
    return 0;
}
/*
ãtrick&&åæ§½ã
ç¹æ°N=n+2*æå¤§éåæ°=1e5+2e6
è¾¹æ°M=3*æå¤§éåæ°=3e6

ãé¢æã
ä¸¤ä¸ªäººAï¼Bæ³è¦è§é¢ã
ænï¼[2,1e5]ï¼ä¸ªç¹ï¼Aåå§å¨1ç¹ï¼Båå§å¨nç¹ã
æmä¸ªéåå³ç³»ï¼ç¬¬iä¸ªéåæSiä¸ªç¹ï¼è¿äºç¹ä¸¤ä¸¤ä¹é´ç§»å¨æè±è´¹çæ¶é´é½ä¸ºdisï¼[1,1e9]ï¼ï¼æâSi<=1e6ã
è®©ä½ è¾åºAåBå¨åªäºç¹ç¢°é¢ï¼ä½¿å¾ä»ä»¬è½å¨ææ©æ¶é´ç¸éã
è¾åºè¿ä¸ªææ©ç¸éæ¶é´ä»¥åæææ»¡è¶³çç¹ã

ãç±»åã
æç­è·¯

ãåæã
è¿é¢å¾æ¾ç¶æ¯ä¸ä¸ªæç­è·¯æ¨¡åãç¶èå¦ææ´åå»ºè¾¹ï¼è¾¹æ°å¯è¾¾1e12æ¡ï¼çç¸ã
é®é¢æ¯æä¹å¤çéåå³ç³»ãæ¯è¾å¥½æ³ï¼æè¯»å®é¢çç¬é´å°±æ³å°äºåæ³ââæç¹ã
å¯¹æ¯ä¸ªéåæé ä¸¤ä¸ªç¹ï¼å¥ç¹ååºç¹ï¼ä¹é´è¿ä¸æ¡è¾¹æä¸ºdisçè¾¹ï¼
æéååçæ¯ä¸ªç¹åè¿ä¸ªéåçå¥ç¹è¿è¾¹ï¼è¾¹æä¸º0ï¼
æéåçåºç¹åè¿ä¸ªéååçæ¯ä¸ªç¹è¿è¾¹ï¼è¾¹æä¸º0ã
è¿æ ·å°±å®ç°äºï¼å¯¹äºæ¯ä¸ªéåï¼å©ç¨2Si+1æ¡è¾¹ï¼æ¹åå¶åä»»æä¸¤ä¸ªç¹çè¾¹æé½ä¸ºdisã
ç¶ååå«ä»¥1ånä¸ºèµ·ç¹ï¼è·æç­è·¯ï¼ç¶åæ«æä¸ä¸å³å¯ã

ãæ¶é´å¤æåº¦&&ä¼åã
O(mlogm)

ãæ°æ®ã
input
2
5 4
1 3 1 2 3
2 2 3 4
10 2 1 5
3 3 3 4 5
3 1
1 2 1 2

output
Case #1: 3
3 4
Case #2: Evil John

*/