/*
1,ç»æµè¯ï¼æéç¹
2ï¼ç¨æ´æ°è®¡ç®
3ï¼èèä¸ç¹å±çº¿çæåµ
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 19
#define NT 1001

int hole[222][222];
struct point
{
    int x,y;
    int input()
    {
        scanf("%d%d",&x,&y);

        if(hole[x+100][y+100])
            return 0;
        hole[x+100][100+y] = 1;
        return 1;

    }
}p[N];


int dist(point a,point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
struct triangle
{
    int edge[3];
    void get_edge(point a,point b,point c)
    {
        edge[0] = dist(a,b);
        edge[1] = dist(a,c);
        edge[2] = dist(b,c);
        sort(edge,edge+3);
    }
}tri[NT];
bool similiar(triangle s1,triangle s2)
{
    return (s1.edge[0] * s2.edge[1] == s1.edge[1] * s2.edge[0])&&
           (s1.edge[0] * s2.edge[2] == s1.edge[2] * s2.edge[0])&&
           (s1.edge[1] * s2.edge[2] == s1.edge[2] * s2.edge[1]);
}
bool nline(point a,point b,point c)
{
    int x1 = b.x - a.x, y1 = b.y - a.y,
        x2 = c.x - a.x, y2 = c.y - a.y;
    return x1 * y2 != x2 * y1;
}

int main()
{
    int n,i,j,k,st;
    int cal[NT] = {0},temp;
    while(scanf("%d",&n) != EOF && n)
    {
        memset(hole,0,sizeof(hole));
        memset(cal,0,sizeof(cal));
        for(i = 0; i < n; ++i)
//            p[i].input();
            if(!p[i].input())
                --i,--n;
        st = 0;
        for(i = 0; i < n; ++i)
            for(j = i + 1; j < n; ++j)
                for(k = j + 1; k < n; ++k)
                if(nline(p[i],p[j],p[k]))
                    tri[st++].get_edge(p[i],p[j],p[k]);

        int sum = 0;
        for(i = 0; i < st; ++i)
            if(!cal[i])
            {
                temp = 1;
                cal[i] = 1;
                for(j = i + 1; j < st; ++j)
                    if(!cal[j] && similiar(tri[i],tri[j]))
                    {
                        ++temp;
                        cal[j] = 1;
                    }
                if(temp > sum)
                    sum = temp;
            }
        printf("%d\n",sum);
    }
    return 0;
}
