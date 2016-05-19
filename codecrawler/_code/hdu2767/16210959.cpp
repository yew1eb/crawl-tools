#include <iostream>
#include <cstring>
#include <stack>
#define Mn 20020
#define Me 200010
#define mm(a, b) (a<b)?a:b
#define clr(x, k) memset((x), (k), sizeof(x))
using namespace std;

struct Edges
{
    int st, to, next;
}edg[Me];

int n, m, ct, index;
int head[Mn], low[Mn], dfn[Mn], belong[Mn], io[Mn], oo[Mn];
bool instack[Mn];
stack <int> s;

void add_e(int i, int u, int v)
{
    edg[i].st = u;
    edg[i].to = v;
    edg[i].next = head[u];
    head[u] = i;
}

void tarjan(int i)
{
        int j;
        dfn[i] = low[i] = ++index;
        s.push(i);
        instack[i] = true;
        for (int u=head[i];u!=-1;u=edg[u].next)
        {
            j = edg[u].to;
            if (dfn[j]==0)
            {
                tarjan(j);
                if (low[i]>low[j])
                {
                    low[i] = low[j];
                }
            }
            else
            if (instack[j] && low[i]>dfn[j])
            {
                low[i] = dfn[j];
            }
        }
        if (dfn[i]==low[i])
        {
            ct++;
            do
            {
                j = s.top(), s.pop();
                instack[j] = false;
                belong[j] = ct;
            }while (i!=j);
        }
}


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        clr(head, -1);
        clr(instack, 0);
        clr(dfn, 0);
        clr(belong, 0);
        while (!s.empty()) s.pop();
        int u, v;
        for (int i=0;i<m;++i)
        {
            scanf("%d %d", &u, &v);
            add_e(i, u, v);
        }
        index = 0;
        ct = 0;
        for (int i=1;i<=n;++i)
        {
            if (!dfn[i])
              tarjan(i);
        }
        if (ct==1)
        {
            printf("0\n");
            continue;
        }
        for (int i=1;i<=ct;++i)
        {
            io[i] = oo[i] = 0;
        }
        int i, j;
        for (int k=0;k<m;++k)
        {
            if ((i=belong[edg[k].st])!=(j=belong[edg[k].to]))
            {
                ++io[i];
                ++oo[j];
            }
        }
        int a, b;
        a = b = 0;
        for (i=1;i<=ct;++i)
        {
            a += (io[i]==0);
            b += (oo[i]==0);
        }
        if (a<b) a = b;
        printf("%d\n", a);
    }
    return 0;
}
        
