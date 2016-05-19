//åçå©ç®æ³
//ç¬ç«éï¼ä»»æä¸¤ç¹é½ä¸ç¸è¿çé¡¶ç¹çéå
//ç¬ç«æ°ï¼ç¬ç«éä¸­é¡¶ç¹çä¸ªæ°
//å®å¨å­å¾ï¼ä»»æä¸¤ç¹é½ç¸è¿çé¡¶ç¹çéå
//æå¤§å®å¨æ°ï¼æå¤§å®å¨å­å¾ä¸­é¡¶ç¹çä¸ªæ°
//æå¤§å®å¨æ°=åå¾çè¡¥å¾çæå¤§ç¬ç«æ°
//æå°ç¹è¦çæ° = æå¤§å¹éæ°
//æå¤§ç¬ç«é¡¶ç¹é = é¡¶ç¹æ»æ°âæå¤§å¹éæ°
//æå°è·¯å¾è¦çæ° = é¡¶ç¹æ»æ°âæå¤§å¹éæ°
#include<cstdio>
#include<cstring>
using namespace std;
bool path[205][205],visit[205];
int match[205];
bool SearchPath(int s,int m)
{
    for(int i=1; i<=m; ++i)
    {
        if(!path[s][i]&&!visit[i])
        {
            visit[i]=true;
            if(match[i]==-1||SearchPath(match[i],m))
            {
                match[i]=s;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int a,b,n,m,r;
    for(int tt=1; scanf("%d%d%d",&n,&m,&r); ++tt)
    {
        if(n+m+r==0)  break;
        memset(path,false,sizeof(path));
        for(int i=0; i<r; ++i)
        {
            scanf("%d%d",&a,&b);
            path[a][b]=true;
        }
        for(int i=1;i<=n;++i)
            path[i][i]=true;
        int summ=0;
        memset(match,-1,sizeof(match));
        for(int i=1; i<=n; ++i)
        {
            memset(visit,0,sizeof(visit));
            if(SearchPath(i,m))
                summ++;
        }
        printf("Case %d: %d\n",tt,n+m-summ);
    }
}
