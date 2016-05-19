#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node
{
    int child,father,brother,present,not_present;
    int max()//ç»æä½åçå½æ°è°ç¨æ¶èæ¶å°
    {
        return present>not_present?present:not_present;
    }
    void init()
    {
        child=father=brother=not_present=0;
    }
}tree[6005];

void dfs(int root)
{
    int son = tree[root].child;
    while(son)
    {
        dfs(son);
        tree[root].present+=tree[son].not_present;
        tree[root].not_present+=tree[son].max();
        son = tree[son].brother;
    }
}

int main()
{
    int n,i,j,k,l;
    while(~scanf("%d",&n)&&n)
    {
        for(i = 1;i<=n;i++)
        {
            scanf("%d",&tree[i].present);
            tree[i].init();
        }
        while(~scanf("%d%d",&l,&k),l+k)
        {
            tree[l].father = k;
            tree[l].brother = tree[k].child;
            tree[k].child = l;
        }
        for(i = 1;i<=n;i++)
        {
            if(!tree[i].father)
            {
                dfs(i);
                printf("%d\n",tree[i].max());
                break;
            }
        }
    }

    return 0;
}
