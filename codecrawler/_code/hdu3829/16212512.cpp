#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 505;
vector<int> vec[N];
char like[N][10], dislike[N][10];
int flag[N], vis[N];

bool dfs(int a)
{
    int i;
    for(i = 0; i < vec[a].size(); i++)
    {
        int u = vec[a][i];
        if(!vis[u])
        {
            vis[u] = 1;
            if(!flag[u] || dfs(flag[u]))
            {
                flag[u] = a;
                return true;
            }
        }
    }
    return false;
}

int hungary(int n) //åçå©ç®æ³æ±æå¤§å¹é
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i))
            cnt++;
    }
    return cnt;
}

int main()
{
    int i, j, n, m, p;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        memset(vec, 0, sizeof(vec));
        memset(flag, 0, sizeof(flag));
        for(i = 0; i < p; i++)
            scanf("%s%s",like[i], dislike[i]);
        for(i = 0; i < p; i++)
            for(j = i + 1; j < p; j++)
            {
                if(!strcmp(like[i], dislike[j]) || !strcmp(dislike[i], like[j]))
                {   // iåjäº§ççç¾æ¶å°±å¨iåjä¹é´å»ºç«ä¸æ¡è¾¹
                    vec[i].push_back(j);
                    vec[j].push_back(i);
                }
            }
        int k = hungary(p);
        printf("%d\n",p - k/2);
    }
    return 0;
}