//*************************************************
//        Kruskal  æ¨¡æ¿
//
/*
struct KRUSKAL
{
    const int MAXN = 109;
    const int MAXE = 5009;

    struct EDGE
    {
        int u, v, length, choose;
    }    edge[ MAXE ];

    int path[ MAXN ];
    int N, edgecnt, sum;

    void Addedge(int u, int v, int len)
    {
        ++edgecnt;
        edge[ edgecnt ].u = u;
        edge[ edgecnt ].v = v;
        edge[ edgecnt ].length = len;
        edge[ edgecnt ].choose = false;
        return ;
    }

    void Set()
    {
        for (int i = 1; i <= N; i++)
            path[i] = i;
        return ;
    }

    int Find_Path(int x)
    {
        if (x != path[x]) path[x] = Find_Path( path[x] );
        return path[x];
    }

    int Work()
    {
        int cnt = 0, x, y;
        Qsort(1, edgecnt);    // i < j -> edge[i].length < edge[j].length
        Set();
        for (int i = 1; i <= E && cnt < N - 1; i++)
        {
            x = Find_Path( edge[i].u );
            y = Find_Path( edge[i].v );
            if (x == y) continue;
            path[x] = path[y];
            edge[i].choose = true, ++cnt;
            sum += edge[i].length;
        }
        return sum;
    }
}    Kruskal;
*/
//ä¸ªäººè§å¾åæ³æ¯è¾ç¹çï¼æ»ä½ææ³è¿æ¯å¹¶æ¥ééå ä¸ªå¤æ­ä»ä¹ç
//çäºä¸hdu1863,è¿ä¸ªé¢å°±æ¯æ¨¡æ¿ï¼äºæ¯ç®åä¸ä¸å°±ä½ä¸ºæ°çæ¨¡æ¿å§

//***************************************
//      hdu 1863 (kruskal)
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct Fuck
{
    int u,v,w;
}fuck[110];
int p[110],m,n,sum;
int cmp(Fuck x,Fuck y)
{
    return x.w<y.w;
}
int find(int x)
{
    return x==p[x]?p[x]:find(p[x]);
}
void Kruskal()
{
    int i,ans=0;
    for(i=1;i<=m;i++)
    p[i]=i;
    sort(fuck+1,fuck+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        int x=find(fuck[i].u);
        int y=find(fuck[i].v);
        if(x!=y)
        {
            sum++;
            ans+=fuck[i].w;
            p[x]=y;
        }
    }
    if(sum==m)
    printf("%d\n",ans);
    else
    printf("?\n");
}
int main()
{
    while(cin>>n>>m,n)
    {
        int i;
        sum=1;
        for(i=1;i<=n;i++)
        scanf("%d%d%d",&fuck[i].u,&fuck[i].v,&fuck[i].w);
        Kruskal();
    }
    return 0;
}
