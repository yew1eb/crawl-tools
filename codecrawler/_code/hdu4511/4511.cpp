#include <queue>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define CLR(a,v) memset(a,v,sizeof(a))

typedef pair<double,double> PDD;

PDD p[55];

#define F first
#define S second

double d[55][55];

double sqr(double x)
{
    return x * x;
}

double dis(PDD& p1,PDD& p2)
{
    return sqrt( sqr(p1.F - p2.F) + sqr(p1.S - p2.S) );
}

namespace Trie
{
    const int N = 505;
    const int Size = 50;
    int top;
    struct Node{
        Node *next[Size], *f;
        bool ended;
    }node[N], *root;
    inline Node* new_node()
    {
        node[top].ended = false;
        CLR(node[top].next,NULL);
        return &node[top++];
    }
    void init()
    {
        top = 0;
        root = new_node();
    }
    void insert(char *s)
    {
        Node *u = root;
        for(int i=0;s[i];i++)
        {
            int id = s[i] - 1;
            if(u->next[id] == NULL)
                u->next[id] = new_node();
            u = u->next[id];
        }
        u->ended = true;
    }
}

namespace ACam
{
    using namespace Trie;
    void get_fail()
    {
        queue<Node*> Q;
        for(int i=0;i<Size;i++)
        {
            Node *&ch = root->next[i];
            if(!ch)
                ch = root;
            else
            {
                ch->f = root;
                Q.push(ch);
            }
        }
        while(!Q.empty())
        {
            Node *cur = Q.front();Q.pop();
            for(int i=0;i<Size;i++)
            {
                Node *&ch = cur->next[i];
                if(!ch)
                    ch = cur->f->next[i];
                else
                {
                    ch->f = cur->f->next[i];
                    ch->ended |= ch->f->ended;
                    Q.push(ch);
                }
            }
        }
    }
    double dp[55][N];
    double solve(int n)
    {
        const double inf = 1e12;
        fill(&dp[0][0],&dp[54][Size-1],inf);
        int state_init = node[0].next[0] - node;
        if(node[state_init].ended)
            return -1;
        dp[0][state_init] = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<top;j++)
            {
                if(dp[i][j] == inf)
                    continue;
                for(int k=i+1;k<n;k++)
                {
                    int jj = node[j].next[k] - node;
                    if(node[jj].ended)
                        continue;
                    dp[k][jj] = min(dp[k][jj],dp[i][j]+dis(p[i],p[k]));
                }
            }
        }
        double ans = inf;
        for(int j=0;j<top;j++)
            ans = min(ans,dp[n-1][j]);
        return ans == inf ? -1 : ans;
    }
}

char str[9];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        ACam::init();
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].F,&p[i].S);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                d[i][j] = dis(p[i],p[j]);
        }
        while(m--)
        {
            int k;
            scanf("%d",&k);
            for(int i=0;i<k;i++)
            {
                int id;
                scanf("%d",&id);
                str[i] = id;
            }
            str[k] = '\0';
            ACam::insert(str);
        }
        ACam::get_fail();
        double ans = ACam::solve(n);
        if(ans == -1)
            puts("Can not be reached!");
        else
            printf("%.2f\n",ans);
    }
    return 0;
}
