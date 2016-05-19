/*****************************************************
é¢æï¼
Peteréè¯·æååå ä»çèä¼;
ä½æ¯è¢«éè¯·çäººå¿é¡»æ»¡è¶³ï¼
å¨èä¼ä¸­è³å°æAä¸ªè®¤è¯çäººåBä¸ªä¸è®¤è¯çäººï¼
æ±æå¤æå¤å°äººä¼è¢«ä»éè¯·ï¼
ç®æ³ï¼
æ ¹æ®é¢ç®ç»çæ°æ®éï¼ç®æµè¿æ¯ä¸éæ°´é¢ï¼
å³éè¿å¾ªç¯æ¥æ¾æ¾å°ä¸åæ³çç»ç¹ï¼å é¤ä»å¯¹åºçå³ç³»ï¼
ç¶åç»§ç»­æ¥æ¾ï¼ç´å°æ¯ä¸ä¸ªç»ç¹é½æ¯åæ³çï¼
*****************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

const int N=111;

struct relation
{
    int know,unknow;
} a[N];

int map[N][N];
bool visit[N];
int n,m;
int A,B;

int solve()
{
    int res=n;
    while(1)
    {
        int flag=1;
        for(int i = 0 ; i < n ; i++)
        {
            if(!visit[i]&&(a[i].know<A||a[i].unknow<B))
            {
                visit[i]=1;
                res--;
                flag=0;
                for(int j=0; j<n; j++)
                {
                    if(!visit[j])
                    {
                        if(map[i][j])
                        {
                            a[j].know--;
                        }
                        else
                            a[j].unknow--;
                    }

                }
            }
        }
        if(flag)
            break;//ææçç»ç¹å¨é¨æ»¡è¶³æ¡ä»¶
    }
    return res;
}

int main()
{
   //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    int tcase = 1;
    while(~scanf("%d%d%d%d",&n,&m,&A,&B))
    {
        if(!n&&!m&&!A&&!B)
            break;
        memset(a,0,sizeof(a));
        memset(map,0,sizeof(map));
        memset(visit,0,sizeof(visit));

        for(int i=0; i<m; i++)
        {
            int u , v;
            scanf("%d%d",&u,&v);
            map[u][v]=map[v][u]=1;
            a[u].know++;
            a[v].know++;
        }

        for(int i=0; i<n; i++)
        {
            a[i].unknow=n-a[i].know-1;//ä¸è®¤çäººæ°=n-è®¤è¯çåä»èªå·±
        }

        printf("Case #%d: %d\n" , tcase++ , solve());
    }
    return 0;
}

