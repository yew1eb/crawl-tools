#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N_node 1000*1000+10
#define N_edge 1000 * 1000 * 2 + 10

using namespace std;

typedef struct
{
    int a ,b ,c;
}EDGE;

EDGE E[N_edge];
int map[1005][1005];

bool camp(EDGE a ,EDGE b)
{
    return a.c < b.c;
}

int mer[N_node];

int finds(int x)
{
    return x == mer[x] ? x : mer[x] = finds(mer[x]);
}

int abss(int x)
{
    return x > 0 ? x : -x;
}

int main ()
{
    int t ,n ,m ,i ,j ,cas = 1;
    scanf("%d" ,&t);
    while(t--)
    {
        scanf("%d %d" ,&n ,&m);

        for(i = 1 ;i <= n ;i ++)
        for(j = 1 ;j <= m ;j ++)
        scanf("%d" ,&map[i][j]);
        int nowid = 0;
        for(i = 1 ;i <= n ;i ++)
        for(j = 1 ;j <= m ;j ++)
        {
            int now = (i - 1) * m + j;
            mer[now] = now;
            if(j < m)
            {
                nowid ++;
                E[nowid].a = now;
                E[nowid].b = (i - 1) * m + j + 1;
                E[nowid].c = abss(map[i][j] - map[i][j+1]);
            }
            if(i < n)
            {
                nowid ++;
                E[nowid].a = now;
                E[nowid].b = (i - 1 + 1) * m + j;
                E[nowid].c = abss(map[i][j] - map[i+1][j]);
            }
        }
        sort(E + 1 ,E + nowid + 1 ,camp);
        int sum = 0;
        for(i = 1 ;i <= nowid ;i ++)
        {
            int a = finds(E[i].a);
            int b = finds(E[i].b);
            if(a != b)
            {
                mer[a] = b;
                sum += E[i].c;
            }
        }
        printf("Case #%d:\n" ,cas ++);
        printf("%d\n" ,sum);

    }
    return 0;
}



