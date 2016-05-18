#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 8
#define MAXL 5
int N, n[MAXN], a[MAXN][MAXL];
char ch[128];
void init()
{
    int i, j;
    char b[10];
    scanf("%d", &N);
    for(i = 0; i < N; i ++)
    {
        scanf("%s", b);
        n[i] = strlen(b);
        for(j = 0; j < n[i]; j ++) a[i][j] = ch[b[j]];
    }
}
int Max(int *x)
{
    int i, j, h[4], max[4] = {0};
    for(i = 0; i < N; i ++)
    {
        memset(h, 0, sizeof(h));
        for(j = x[i]; j < n[i]; j ++) ++ h[a[i][j]];
        for(j = 0; j < 4; j ++) max[j] = std::max(max[j], h[j]);
    }
    return max[0] + max[1] + max[2] + max[3];
}
int dfs(int d, int *ix)
{
    if(Max(ix) > d) return 0;
    if(d == 0) return 1;
    int i, j, x[MAXN];
    for(i = 0; i < 4; i ++)
    {
        for(j = 0; j < N; j ++)
        {
            if(ix[j] < n[j] && a[j][ix[j]] == i)
                x[j] = ix[j] + 1;
            else x[j] = ix[j];
        }    
        if(dfs(d - 1, x)) return 1;
    }
    return 0;
}
void solve()
{
    int dep, ini[8] = {0};
    for(dep = 1; !dfs(dep, ini); dep ++);
    printf("%d\n", dep);
}
int main()
{
    int t;
    ch['A'] = 0, ch['T'] = 1, ch['C'] = 2, ch['G'] = 3;
    scanf("%d", &t);
    while(t --)
    {
        init();
        solve();    
    }
    return 0;    
}