#include<stdio.h>
#include<string.h>
#define INF 1<<25
const int N = 160;
int w[N][N], d[N], m;
char add[N][40];

void Init()
{
    for(int i = 0; i <= 150; i++)
        for(int j = 0; j < 150; j++)
        {
            if(i == j)
                w[i][j] = 0;
            else
                w[i][j] = INF;
        }
}

int Change(char *s)
{
    int i;
    for(i = 0; i < m; i++)
        if(strcmp(add[i], s) == 0)
            return i;
    if(i == m)
    {
        strcpy(add[m], s);
        m++;
        return m-1;
    }
}

void Dijkstra()
{
    int vis[N], i;
    memset(vis, 0, sizeof(vis));
    for(i = 0; i < m; i++)
        d[i] = INF;
    d[0] = 0;
    for(i = 0; i < m; i++)
    {
        int x = 0, temp = INF;
        for(int y = 0; y < m; y++)
            if(!vis[y] && d[y] < temp)
                temp = d[x = y];
        if(temp == INF)  break;
        vis[x] = 1;
        for(int y = 0; y < m; y++)
            if(d[y] > d[x] + w[x][y])
                d[y] = d[x] + w[x][y];
    }
}
int main()
{
    int n, i, j;
    while(~scanf("%d",&n) && n != -1)
    {
        Init();
        char st[40], ed[40], s1[40], s2[40];
        int a, b, c;
        scanf("%s%s",st, ed);
        strcpy(add[0], st);
        strcpy(add[1], ed);
        m = 2;
        for(i = 0; i < n; i++)
        {
            scanf("%s%s%d",s1, s2, &c);
            a = Change(s1);
            b = Change(s2);
            w[a][b] = w[b][a] = c;
        }
        if(strcmp(st, ed) == 0)
        {
            printf("0\n");
            continue;
        }
        Dijkstra();
        if(d[1] == INF)
            printf("-1\n");
        else
            printf("%d\n",d[1]);
    }
    return 0;
}