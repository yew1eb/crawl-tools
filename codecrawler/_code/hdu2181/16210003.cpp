#include <stdio.h>
#include <string.h>

#define MAX 21
#define bool int
#define false 0
#define true 1

bool map[MAX][MAX];//å®å¿ä½å°å¾
bool used[MAX];//æ è®°åå¸èµ°è¿

int res[MAX];//ä¿å­å½åèµ°è¿çè·¯å¾

int num;//è®°å½æå°å°äºç¬¬å ä¸ª
int cas;

void init()
{
    int a, b, c, i;
    for(i = 1; i <= 20; ++ i){
        scanf("%d%d%d",&a, &b, &c);
        map[i][a] = true;
        map[i][b] = true;
        map[i][c] = true;
    }
}

void dfs(int dep, int count)
{
    int i, j;
    res[count] = dep;
    if(count == 19){
        if(map[dep][cas]){
            printf("%d:  ", ++ num);
            for(i = 0; i < 20; ++ i){
                printf("%d ", res[i]);
            }
            printf("%d\n", res[0]);
        }
        return;
    }
    for(j = 1; j <= 20; j ++){
        if(map[dep][j] && !used[j]){
            used[j] = true;
            dfs(j, count+1);
            used[j] = false;
        }
    }
}

int main()
{
/*    freopen("input.txt","r+",stdin);
    freopen("output.txt","w+",stdout);*/
    memset(map,0,sizeof(map));
    init();
    while(scanf("%d",&cas), cas){
        num = 0 ;
        memset(used, false, sizeof(used));
        memset(res, 0, sizeof(res));
        used[cas] = true;
        dfs(cas, 0);
    }
    return 0;
}