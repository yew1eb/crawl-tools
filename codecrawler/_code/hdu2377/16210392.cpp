#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

typedef set<int>::iterator it;
const int N = 10000;
int dis[N], tdis[N], link[N][12];
queue<int> q;
set<int> zone;

void bfs(int o)
{
    memset(tdis, 0, sizeof(tdis));
    tdis[o] = 1;
    q.push(o);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(tdis[cur] > dis[cur]) dis[cur] = tdis[cur];
        for(int i = 1; i <= link[cur][0]; ++i)
        {
            int j = link[cur][i];
            if(tdis[j] == 0)  q.push(j), tdis[j] = tdis[cur] + 1;
        }
    }
}

int main()
{
    int cas, nz, nr, id, mz, mr, ans, t;
    scanf("%d", &cas);
    while(cas--)
    {
        zone.clear();
        memset(dis, 0, sizeof(dis));
        scanf("%d%d", &nz, &nr);
        for(int i = 1; i <= nz; ++i)
        {
            scanf("%d %d", &id, &mz);
            link[id][0] = mz;
            zone.insert(id);
            for(int i = 1; i <= mz; ++i)
                scanf("%d", &link[id][i]);
        }

        for(int i = 1; i <= nr; ++i)
        {
            scanf("%d", &mr);
            for(int j = 1; j <= mr; ++j)
            {
                scanf("%d", &t);
                bfs(t);
            }
        }

        it i = zone.begin();
        ans = *i;
        for(++i; i != zone.end(); ++i)
            if(dis[*i] < dis[ans]) ans = *i;
        printf("%d %d\n", dis[ans], ans);
    }
    return 0;
}