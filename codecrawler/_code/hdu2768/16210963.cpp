/*************************************************************
é¢æï¼
ç»ä½ nåªç«ï¼måªçï¼pä¸ªäººï¼
æ¯ä¸ªäººé½æä¸åªåæ¬¢çåä¸åªè®¨åçå¨ç©ï¼
å¦æå»ææäººè®¨åçå¹¶ä¸çä¸ä»åæ¬¢çï¼
åè¿äººæ¯é«å´çï¼è®©ä½ æ±åºæå¤é«å´äººæ°ã
ç®æ³ï¼
å©ç¨äºåå¹éæ±æå¤§ç¬ç«é
æå¤§ç¬ç«é=èç¹æ°-æå¤§å¹éæ°
å»ºå¾ï¼
åæ¬¢ç«çäººå·¦è¾¹ï¼åæ¬¢ççäººå³è¾¹
äºåå¾åå§åä¸º0ï¼
åªè¦æå²çªçï¼æå¼ä¸º1ã
****************************************************************/
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 555;
const int M = 5;
struct darling
{
    char like[M], dislike[M];
};
int map[N][N];
darling cat[N], dog[N];
int visit[N];
int match[N];
int n,m,p;
int k1,k2;//ç»è®¡åæ¬¢ç«ççæ°é
int find (int x)
{
    for (int i = 0; i < k2; i++)
        if (map[x][i] && !visit[i])
        {
            visit[i] = true;
            if (match[i] == -1 || find(match[i]))
            {
                match[i] = x;
                return 1;
            }
        }
    return 0;
}

int main()
{
    //freopen("C:\\Users\\Administrator\\Desktop\\kd.txt","r",stdin);
    char like[M],dislike[M];
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &p);
        k1 = k2 = 0;
        for (int i = 0; i < p; i++)
        {
            scanf("%s%s", like, dislike);
            if (like[0] == 'C')
            {
                strcpy(cat[k1].like, like);
                strcpy(cat[k1].dislike, dislike);
                k1++;
            }
            else
            {
                strcpy(dog[k2].like, like);
                strcpy(dog[k2].dislike, dislike);
                k2++;
            }
        }

        memset(map, 0, sizeof(map));
        for (int i = 0; i < k1; i++)
            for (int j = 0; j < k2; j++)
                if (strcmp(cat[i].like, dog[j].dislike) == 0 || strcmp(cat[i].dislike, dog[j].like) == 0)
                    map[i][j] = 1;

        int res = 0;
        memset(match, -1, sizeof(match));
        for (int i = 0; i < k1; i++)
        {
            memset(visit, false, sizeof(visit));
            if (find(i))
                res++;
        }

        printf("%d\n", p-res);
    }
    return 0;
}
