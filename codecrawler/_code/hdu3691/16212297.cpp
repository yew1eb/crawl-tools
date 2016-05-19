#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 305;
const int MAXV = 0x3F3F3F3F;
int n,m,v[MAXN],mat[MAXN][MAXN],dis[MAXN];
bool vis[MAXN];
int res,s;
int Stoer_Wagner(int n)
{
    int i, j;
    int res = MAXV;
    for (i = 0; i < n; i++)
        v[i] = i+1;//åå§åç¬¬iä¸ªç»ç¹å°±æ¯i
    while (n > 1)
    {
        int maxp = 1,prev = 0;
        for (i = 1; i < n; i++) //åå§åå°å·²åéåçå²å¤§å°,å¹¶æ¾åºæå¤§è·ç¦»çé¡¶ç¹
        {
            dis[v[i]] = mat[v[0]][v[i]];
            if (dis[v[i]] > dis[v[maxp]])
                maxp = i;
        }
        memset(vis, 0, sizeof(vis));
        vis[v[0]] = true;
        for (i = 1; i < n; i++)
        {
            if (i == n - 1)  //åªå©æåä¸ä¸ªæ²¡å å¥éåçç¹ï¼æ´æ°æå°å²
            {
                res = min(res,dis[v[maxp]]);
                for (j = 0; j < n; j++)  //åå¹¶æåä¸ä¸ªç¹ä»¥åæ¨åºå®çéåä¸­çç¹
                {
                    mat[v[prev]][v[j]] += mat[v[j]][v[maxp]];
                    mat[v[j]][v[prev]] = mat[v[prev]][v[j]];
                }
                v[maxp] = v[--n];//ç¬¬maxpä¸ªèç¹å»æï¼ç¬¬nä¸ªèç¹åæç¬¬maxpä¸ª
            }
            vis[v[maxp]] = true;
            prev = maxp;
            maxp = -1;
            for (j = 1; j < n; j++)
                if (!vis[v[j]])  //å°ä¸æ¬¡æ±çmaxpå å¥éåï¼åå¹¶ä¸å®ç¸é»çè¾¹å°å²é
                {
                    dis[v[j]] += mat[v[prev]][v[j]];
                    if (maxp == -1 || dis[v[maxp]] < dis[v[j]])
                        maxp = j;
                }
        }
    }
    return res;
}
int main()
{
    //freopen("input.txt","r",stdin);
    while (scanf("%d%d%d", &n, &m, &s),n||m||s)
    {
        memset(mat,0,sizeof (mat));
        int x,y,z;
        while (m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            mat[x][y] += z;
            mat[y][x] += z;
        }
        printf("%d\n",Stoer_Wagner(n));
    }
}
