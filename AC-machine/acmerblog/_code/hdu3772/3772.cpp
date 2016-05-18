#include<stdio.h>
#include<string.h>
#define MAXD 210
#define INF 1000000000
char b[MAXD][1010];
int G[MAXD][MAXD] , yM[MAXD], N;
int A[MAXD], B[MAXD], slack;
int visx[MAXD], visy[MAXD];
int check(char *str1, char *str2)
{
    int i, j, num = 0;
    i =strlen(str1) - 1;
    for(j = 0; str1[i] == str2[j] && i >= 0 && str2[j]; i --, j ++)
        num ++;
    return num;
}
void init()
{
    int i, j, k;
    for(i = 0; i < N; i ++)
        scanf("%s", b[i]);
    memset(G, 0, sizeof(G));
    for(i = 0; i < N; i ++)
        for(j = i + 1; j < N; j ++)
        {
            G[i][j] = check(b[i], b[j]);
            G[j][i] = check(b[j], b[i]);
        }
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
void KM()
{
    int i, j, u;
    for(i = 0; i < N; i ++)
    {
        A[i] = 0;
        for(j = 0; j < N; j ++)
            if(G[i][j] > A[i])
                A[i] = G[i][j];
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
    for(i = 0; i < N ; i ++)
        res += G[yM[i]][i];
    printf("%d\n", res);
}
int main()
{
    while(scanf("%d", &N) == 1)
    {
        init();
        KM();
        printresult();
    }
    return 0;
}