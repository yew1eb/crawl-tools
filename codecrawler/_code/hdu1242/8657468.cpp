#include<stdio.h>
#define max 32000
int n, m, time, visited[202][202], map[202][202], mx[5] = {0, 0, 0, -1, 1}, my[5] = {0, 1, -1, 0, 0}, ax, ay, ex, ey;
void init();
int dfs(int x, int y, int t);
int main()
{
    init();
    return 0;
}
void init()
{
    int i, j;
    char str[203];
    while(scanf("%d %d\n", &n, &m) != EOF){
        time = max;
        for(i = 0; i <= n + 2; ++i)
            for(j = 0; j <= m + 2; ++j){
                map[i][j] = -1;
                visited[i][j] = -1;
            }
        for(i = 1; i <= n; ++i){
            gets(str);
            for(j = 0; j <= m - 1; ++j)
                if(str[j] == '.')
                    visited[i][j + 1] = 1;
                else
                    if(str[j] == 'a'){
                        ax = i;
                        ay = j + 1;
                    }
                    else
                        if(str[j] == 'r'){
                            ex = i;
                            ey = j + 1;
                            visited[i][j + 1] = 1;
                        }
                        else
                            if(str[j] == 'x')
                                visited[i][j + 1] = 2;
        }
        dfs(ax, ay, 0);
        if(time != max)
            printf("%d\n", time);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n" );
    }
}
int dfs(int x, int y, int t){
    int i, ch, xn, yn;
    if(x == ex && y == ey){
        if(t < time)
            time = t;
        return 0;
    }
    else{
        for(i = 1; i <= 4; ++i){
            xn = x + mx[i];
            yn = y + my[i];
            if((visited[xn][yn] == 1 || visited[xn][yn] == 2) && t + visited[xn][yn] <= time){
                if(map[xn][yn] == -1 || t + visited[xn][yn] <= map[xn][yn]){
                    map[xn][yn] = t + visited[xn][yn];
                    ch = visited[xn][yn];
                    visited[xn][yn] = -1;
                    dfs(xn, yn, t + ch);
                    visited[xn][yn] = ch;
                }
            }
        }
    }
}