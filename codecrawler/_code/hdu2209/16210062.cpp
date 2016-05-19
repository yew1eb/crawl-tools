#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
#define MAX 1<<20
#define N 50

char s1[N];
int visited[MAX],num[MAX];
int len;

int bfs(int x){
    queue<int>q;
    q.push(x);
    int i, now, next;
    while(!q.empty()){
        now = q.front();//åå¤´
        q.pop();//å¤´åºé
        for (i = 1; i <= len; i++){
            if(i == 1)
                next = now^3;//æå·¦ç¿»è½¬ä¸¤ä¸ª
            else
                next = now^(7<<(i-2));//ä¸­é´ç¿»è½¬3ä¸ª

            next &= (1<<len)-1;//æå³çæ¶åç¿»è½¬äºä¸ä¸ªï¼æ¶æä¸ä¸ª

            if(visited[next])continue;//æ¯å¦å·²æè¿

            visited[next] = 1;//æ è®°ä¸ºå·²æ
            num[next] = num[now] + 1;//æå°æ¬¡æ°å ä¸
            if(next == 0)   return num[next];//æ¯å¦æå°äº
            q.push(next);//æ²¡æï¼åå¥é
        }
    }
    return -1;
}

int main()
{
    int i, a;
    while(scanf("%s",s1)!=EOF){
        len = strlen(s1);
        a = 0;
        for(i = 0;i < len;i++)
            a = (a<<1) + s1[i] -'0';
        if(a){
            memset(visited,0,sizeof(visited));
            memset(num,0,sizeof(num));
            a = bfs(a);
        }
        if(a == -1)
            printf("NO\n");
        else printf("%d\n",a);
    }
    return 0;
}
