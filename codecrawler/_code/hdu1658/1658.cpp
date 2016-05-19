#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 101;
const int inf = 100000000;
char s1[N],s2[N];
bool flag[N];
bool chk[N];
int block[N],pre[N];
vector<int> vec[N];

struct Edge
{
    int v;
    int dis;
    bool flag;
    Edge* next;
}*pp,*adj[N],pool[2*N*N],*tree[N],*minEdge;
struct Node
{
    int from;
    int dis,at;
    Node() {}
    Node(int _from,int _at,int _dis)
    {
        from = _from;
        at = _at;
        dis = _dis;
    }
    bool operator < (const Node n) const
    {
        return dis > n.dis;
    }
};
void init()
{
    pp = pool;
    memset(adj,0,sizeof(adj));
    memset(tree,0,sizeof(tree));
}
void addedge(int u,int v,int dis,bool flag,Edge* adj[])
{
    pp->v = v;
    pp->dis = dis;
    pp->flag = flag;
    pp->next = adj[u];
    adj[u] = pp++;
}
int prim_heap(int start,int n)
{
    int ans = 0;
    priority_queue<Node> pq;
    pq.push(Node(-1,start,0));
    int k = 0;
    while(k < n && !pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if(flag[now.at])
            continue;
        flag[now.at] = true;
        ans += now.dis;
        if(now.from != -1)
        {
            addedge(now.at,now.from,now.dis,true,tree);
            addedge(now.from,now.at,now.dis,true,tree);
        }
        k++;
        for(Edge* p = adj[now.at]; p; p=p->next)
            if(!flag[p->v])
                pq.push(Node(now.at,p->v,p->dis));
    }
    return ans;
}
void dfs(int from,int now)
{
    flag[now] = true;
    pre[now] = from;
    for(Edge* p = tree[now]; p; p=p->next)
        if(!flag[p->v] && p->flag)
            dfs(now,p->v);
}
void calMinEdge(int now,int val)
{
    for(Edge* p = tree[now]; p; p=p->next)
        if(flag[p->v]  && p->flag)
        {
            flag[p->v] = false;
            if(p->dis > val)
            {
                minEdge = p;
                val = p->dis;
            }
            calMinEdge(p->v,val);
        }
}
int main()
{
    int m;
    scanf("%d",&m);
    init();
    map<string,int> mp;
    mp["Park"] = 0;
    for(int i=0; i<N; i++)
        vec[i].clear();
    int idx = 1,degree;
    for(int i=0; i<m; i++)
    {
        int dis;
        scanf("%s %s %d",s1,s2,&dis);
        if(mp.find(s1) == mp.end())
            mp[s1] = idx ++;
        if(mp.find(s2) == mp.end())
            mp[s2] = idx ++;
        int u = mp[s1], v = mp[s2];
        addedge(u,v,dis,true,adj);
        addedge(v,u,dis,true,adj);
    }
    scanf("%d",&degree);
    int n = idx; // n points 0 ~ n - 1
    int rem = 0,nb = 0;
    memset(chk,0,sizeof(chk));
    for(int i=1; i<n; i++)
        if(!chk[i])
        {
            memset(flag,0,sizeof(flag));
            flag[0] = true;
            block[nb] = i;
            rem += prim_heap(i,n-1); // 1 ~ n - 1
            for(int j=1; j<n; j++)
                if(flag[j])
                {
                    vec[nb].push_back(j);
                    chk[j] = true;
                }

            nb++;
        }

    for(int i=0; i<nb; i++)
    {
        int mn  = inf,index = -1;
        Edge* tmp;
        for(int j=0; j<vec[i].size(); j++)
            for(Edge* p=adj[0]; p; p=p->next)
                if(p->v == vec[i][j])
                    if(p->dis < mn)
                    {
                        mn = p->dis;
                        index = vec[i][j];
                        tmp = p;
                        continue;
                    }
        addedge(index,0,mn,true,tree);  // link v0 to block
        addedge(0,index,mn,true,tree);
        tmp->flag = false;                // deleting edge
        (((tmp-pool)^1) + pool)->flag = false;
        rem += mn;
        degree--;
    }
    while(degree > 0) // deleting edge
    {
        degree -- ;
        int mx = -inf;
        Edge *tmpAdd,*tmpDel;
        for(Edge* p=adj[0]; p; p=p->next)
        {
            if(p->flag)
            {
                memset(flag,0,sizeof(flag));
                dfs(0,p->v);
                int now = 0;
                memset(flag,0,sizeof(flag));
                while(pre[now] != 0)
                {
                    flag[now] = true;
                    now = pre[now];
                }
                flag[now] = true;
                calMinEdge(0,-inf);
                int delta =  minEdge->dis - p->dis ;
                if(delta > mx)
                {
                    mx = delta;
                    tmpAdd = p;
                    tmpDel = minEdge;
                }
            }
        }
        if(mx <= 0 )
            break;
        rem -= mx;
        addedge(tmpAdd->v,0,mx,true,tree);  // link new edge
        addedge(0,tmpAdd->v,mx,true,tree);
        tmpAdd->flag = false;              // delete old edge
        (((tmpAdd-pool)^1) + pool)->flag = false;
        tmpDel->flag = false;              // delete old edge
        (((tmpDel-pool)^1) + pool)->flag = false;
    }
    printf("Total miles driven: %d\n",rem);
    return 0;
}