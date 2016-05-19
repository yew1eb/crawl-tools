/**
é¢ç®å¤§æ:
ç»ä½ ä¸ä¸ªæ åè¿éå¾,é®å ä¸ä¸æ¡è¾¹åå¾å°çå¾çæå°çå²è¾¹æ°;

ç®æ³ææ³:
å¾çè¾¹åè¿éTarjanç®æ³+æ å½¢DP;
å³éè¿Tarjanç®æ³å¯¹è¾¹åè¿éç¼©å¾,ææä¸æ£µæ ,ç¶åç¨æ å½¢DPæ±æé¿é¾,è¿æ¥é¦å°¾å³å¯;å©ä¸çè¿éåå³ä¸ºææ±ç­æ¡;

ç®æ³æè·¯:
å¯¹å¾æ·±åº¦ä¼åæç´¢,å®ä¹DFN(u)ä¸ºuå¨æç´¢æ ä¸­è¢«éåå°çæ¬¡åºå·;
å®ä¹Low(u)ä¸ºuæuçå­æ ä¸­è½éè¿éç¶å­è¾¹è¿½æº¯å°çææ©çèç¹,å³DFNåºå·æå°çèç¹;
åæï¼
Low(u)=Min
{
    DFN(u),
    Low(v),(u,v)ä¸ºæ æè¾¹ï¼uä¸ºvçç¶èç¹
    DFN(v),(u,v)ä¸ºæåæ ä¸­èç¹çååè¾¹(éæ¨ªåè¾¹)
}

ä¸ä¸ªé¡¶ç¹uæ¯å²ç¹,å½ä¸ä»å½æ»¡è¶³(1)æ(2)
(1)uä¸ºæ æ ¹,ä¸uæå¤äºä¸ä¸ªå­æ ;
(2)uä¸ä¸ºæ æ ¹,ä¸æ»¡è¶³å­å¨(u,v)ä¸ºæ æè¾¹(æç§°ç¶å­è¾¹,å³uä¸ºvå¨æç´¢æ ä¸­çç¶äº²),ä½¿å¾DFN(u)<=Low(v);

ä¸æ¡æ åè¾¹(u,v)æ¯æ¡¥,å½ä¸ä»å½(u,v)ä¸ºæ æè¾¹ä¸æ»¡è¶³DFN(u)<Low(v);

**/
#pragma comment(linker,"/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

const int N=200010;
const int M=1000010;

struct node
{
    int v;
    int next;
} e[M*2];

int head[N];
int dfn[N],low[N],dp[N][2];//dp[i][0]è¡¨ç¤ºç¬¬iä¸ªèç¹çå­æ ä¸­æé¿çé¾ï¼dp[i][1]è¡¨ç¤ºç¬¬iä¸ªèç¹çå­æ ä¸­ç¬¬äºé¿çé¾
bool visit[M];
int n,m,cnt,res;

void AddEdge(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void Tarjan(int u)
{
    dfn[u]=low[u]=cnt++;
    dp[u][0]=dp[u][1]=0;
    for(int i=head[u]; i!=-1; i=e[i].next)
    {
        int j=e[i].v;
        if(!visit[i>>1])
        {
            visit[i>>1]=true;
            if(dfn[j]==0)//è·å¼ºè¿éä¸æ ·
            {
                Tarjan(j);
                res+=dfn[u]<low[j];//ç»è®¡è¿éåï¼æ¯å®éæ°ç®å°ä¸ä¸ªï¼å°±æ¯åæº¯çæ¶åçæåä¸ä¸ª
                int temp=dp[j][0]+(dfn[u]<low[j]);
                if(temp>dp[u][0])
                {
                    dp[u][1]=dp[u][0];
                    dp[u][0]=temp;
                }
                else if(temp>dp[u][1])
                {
                    dp[u][1]=temp;
                }
                low[u]=min(low[u],low[j]);
            }
            else
                low[u]=min(low[u],dfn[j]);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    #endif
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        cnt=0;
        res=0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(head,-1,sizeof(head));
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            AddEdge(u,v);
            AddEdge(v,u);
        }
        cnt=1;
        memset(visit,0,sizeof(visit));
        Tarjan(1);
        int temp=0;
        for(int i=1; i<=n; i++)
        {
            temp=max(temp,dp[i][0]+dp[i][1]);//+çæ¶åæ²¡æç®å½åç¹æå¨çå,ä½æ¯resä¹å°ç®ä¸ä¸ª
        }
        printf("%d\n",res-temp);
    }
    return 0;
}
