#include <stdio.h>
#include <string.h>

const int maxn = 200000;
struct node
{
    int child[10];
    int cnt;
    int isword;
    void clear()
    {
        memset(child, 0, sizeof child );
        cnt = isword = 0;
    }
}tire[maxn];
int sz;
int flag;

void insert(char *s)
{
    int u, tmp, i;
    u = 0;
    if(!flag) return ;
    for(i=0; s[i]; ++i)
    {
        tmp = s[i] - '0';
        if(!tire[u].child[tmp])
        {
            tire[++sz].clear();
            tire[u].child[tmp] = sz;
        }
        u = tire[u].child[tmp];
        if(tire[u].isword == 1 )
        {
            flag = 0;
            return ;
        }
        tire[u].cnt++;
    }
    tire[u].isword = 1;
    if(tire[u].cnt > 1)
        flag = 0;
}
int main()
{
    int T, n, i;
    char str[20];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        flag = 1;
        sz = 0;
        tire[sz].clear();
        while(n--)
        {
            scanf("%s",str);
            insert(str);
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
