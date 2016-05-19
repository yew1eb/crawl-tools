#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXD 110
#define MAX 10010
#define INF 1000000000
int N, hx[MAXD], hy[MAXD], px[MAXD], py[MAXD];
int a[MAXD][MAXD], G[MAXD][MAXD], yM[MAXD];
int A[MAXD], B[MAXD], slack, visx[MAXD], visy[MAXD];
char b[MAXD];
int init()
{
    int i, j, k, n, m, pn, x, y, newx, newy, front, rear;
    scanf("%d%d", &n, &m);
    if(!n && !m)
        return 0;
    N = pn = 0;
    for(i = 0; i < n ;i ++)
    {
        scanf("%s", b);
        for(j = 0; j < m; j ++)
        {
            if(b[j] == 'H')
            {
                a[i][j] = 0;
                hx[N] = i;
                hy[N] = j;
                N ++;
            }
            else if(b[j] == 'm')
            {
                a[i][j] = 1;
                px[pn] = i;
                py[pn] = j;
                pn ++;
            }
            else
                a[i][j] = 1;
        }
    }
    memset(G, 0, sizeof(G));
    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
            G[i][j] = MAX - (abs(px[i] - hx[j]) + abs(py[i] - hy[j]));
    return 1;
}
int searchpath(int u)
{
    int v, temp;
    visx[u] = 1;
    for(v = 0; v < N; v ++)
        if(!visy[v])
        {
            temp = A[u] + B[v] - G[u][v];
            if(temp == 0)
            {
                visy[v] = 1;
                if(yM[v] == -1 || searchpath(yM[v]))
                {
                    yM[v] = u;
                    return 1;
                }
            }
            else if(temp < slack)
                slack = temp;
        }
    return 0;
}
void EK()
{
    int i, j, u;
    for(i = 0; i < N; i ++)
    {
        A[i] = 0;
        for(j = 0; j < N; j ++)
        {
            if(G[i][j] > A[i])
                A[i] = G[i][j];
        }
    }
    memset(B, 0, sizeof(B));
    memset(yM, -1, sizeof(yM));
    for(u = 0; u < N; u ++)
        for(;;)
        {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            slack = INF;
            if(searchpath(u))
                break;
            for(i = 0; i < N; i ++)
            {
                if(visx[i])
                    A[i] -= slack;
                if(visy[i])
                    B[i] += slack;
            }
        }
}
void printresult()
{
    int i, res = 0;
    for(i = 0; i < N; i ++)
        res += MAX - G[yM[i]][i];
    printf("%d\n", res);
}
int main()
{
    while(init())
    {
        EK();
        printresult();
    }
    return 0;
}