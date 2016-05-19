#include<stdio.h>
#include<string.h>
#define MAXD 310
#define INF 1000000000
int n, yM[MAXD], visx[MAXD], visy[MAXD];
int G[MAXD][MAXD], A[MAXD], B[MAXD], slack;
void init()
{
    int i, j;
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            scanf("%d", &G[i][j]);
    for(i = 0; i < n; i ++)
    {
        A[i] =0;
        for(j = 0; j < n; j ++)
            if(G[i][j] > A[i])
                A[i] = G[i][j];
    }
    memset(B, 0, sizeof(B));
}
int searchpath(int u)
{
    int v, temp;
    visx[u] = 1;
    for(v = 0; v < n; v ++)
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
void KM()
{
    int i, j;
    memset(yM, -1, sizeof(yM));
    for(i = 0; i < n; i ++) 
        for(;;)
        {