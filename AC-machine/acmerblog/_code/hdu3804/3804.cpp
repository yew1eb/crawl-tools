#include <iostream>
#include <set>
#include <stack>
using namespace std;
const int maxn = 100005;
struct Graph
{
    int pnt[maxn*2], val[maxn*2], nxt[maxn*2];
    int head[maxn], idx;
    bool sign[maxn];
    void Init(int n)
    {
        memset(head, -1, 4 * (n + 1));
        memset(sign, 0, n + 1);
        idx = 0;
    }
    void Addedge(int x, int y, int v)
    {
        pnt[idx] = y; val[idx] = v; nxt[idx] = head[x]; head[x] = idx++;
        pnt[idx] = x; val[idx] = v; nxt[idx] = head[y]; head[y] = idx++;
    }
} graph;
struct Query
{
    int x[maxn], top[maxn], ans[maxn];
    int nxt[maxn], head[maxn], idx;
    void Init(int n)
    {
        memset(head, -1, 4 * (n + 1));
        idx = 0;
    }
    void Addquery(int tx, int tt)
    {
        if (tx == 1) ans[idx] = -1;
        x[idx] = tx; top[idx] = tt;
        nxt[idx] = head[tx]; head[tx] = idx++;
    }
} query;
struct Node
{
    int p, v;
};
multiset<int> mset;
multiset<int>::iterator it;
stack< pair<int, int> > stac;
pair<int, int> par;
void Init(int n)
{
    graph.Init(n);
    query.Init(n);
}
void Solve()
{
    mset.insert(-1);
    graph.sign[1] = 1;
    stac.push(make_pair(graph.head[1], -1));
    while (!stac.empty())
    {
        par = stac.top();
        stac.pop();
        int &p = par.first;
        if (p == -1)
        {
            mset.erase(mset.find(par.second));
        }
        else
        {
            int &y = graph.pnt[p];
            if (!graph.sign[y])
            {
                graph.sign[y] = 1;
                int tp = p;
                p = graph.nxt[p];
                stac.push(par);
                par.first = graph.head[y];
                par.second = graph.val[tp];
                stac.push(par);
                mset.insert(par.second);
                for (int i = query.head[y]; i != -1; i = query.nxt[i])
                {
                    it = mset.upper_bound(query.top[i]);
                    it--;
                    query.ans[i] = (*it);
                }
            }
            else
            {
                p = graph.nxt[p];
                stac.push(par);
            }
        }
    }
}
int main()
{
    int test, cas;
    scanf("%d", &test);
    for (cas = 1; cas <= test; cas++)
    {
        int n, m;
        int x, y, v, t;
        scanf("%d", &n);
        Init(n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &x, &y, &v);
            graph.Addedge(x, y, v);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &x, &t);
            query.Addquery(x, t);
        }
        Solve();
        for (int i = 0; i < m; i++)
        {
            printf("%d/n", query.ans[i]);
        }
    }
    return 0;
}
 

版权声明：本文为博主原创文章，未经博主允许不得转载。

参考：http://blog.csdn.net/racebug2010/article/details/6428221
						                        





(adsbygoogle = window.adsbygoogle || []).push({});

 


window._bd_share_config={"common":{"bdSnsKey":{},"bdText":"","bdMini":"2","bdMiniList":false,"bdPic":"","bdStyle":"0","bdSize":"24"},"share":{}};with(document)0[(getElementsByTagName('head')[0]||body).appendChild(createElement('script')).src='http://bdimg.share.baidu.com/static/api/js/share.js?v=89860593.js?cdnversion='+~(-new Date()/36e5)];

					