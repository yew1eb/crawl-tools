/*
hdu4085
ÌâÄ¿´óÒâ£ºÒ»¸ö´å×¯ÓÐn´±·¿×Ó£¬mÌõÍ¨µÀÁ¬½Ó×ÅÕân´±·¿×Ó£¬ÐÞ½¨Í¨µÀ¶¼ÓÐÌØ¶¨µÄ»¨·Ñ¡£ÔÚ1..k´±·¿×ÓÀïÃæ×¡ÓÐÈË£¬
ÏÖÔÚµÀÂ·±»ÆÆ»µÁËÈ´ÒªÈÃÕâÐ©ÈËË³ÀûÅÜµ½n-k+1,n-k+2...nÀïÃæ£¬ÎÊ×îÉÙÐèÒª»¨·Ñ¶àÉÙmoneyÀ´ÐÞ¸´ÕâÐ©µÀÂ·¡£

¾ÍÊÇÇóÒ»¸öÍ¼ÖÐÖÁÉÙ°üº¬Ö¸¶¨k¸öµãµÄ×îÐ¡Éú³ÉÊ÷¡£
×îÓÅ½â±ØÈ»ÊÇÒ»¿ÃÊ÷£¬È»ºóÕâ¿ÃÊ÷ÓÖÊÇÓÉÈô¸É¿Ã×ÓÊ÷ºÏ²¢³ÉµÄ£¬ÓÚÊÇÎÒÃÇ¿ÉÒÔ×´Ì¬Ñ¹Ëõ£¬°Ñk¸ö½ÚµãµÄÁ¬Í¨×´Ì¬ÓÃÒ»¸ö¶þ½øÖÆÊýj±íÊ¾£¬dp[i][j]±íÊ¾ÒÔiÎª¸ùºÍ¶ÔÓ¦×´Ì¬ÎªjµÄ½ÚµãÁ¬Í¨µÄ×ÓÊ÷µÄ×îÐ¡È¨Öµ¡£ÓÐÁ½ÖÖ×ªÒÆ·½·¨£º

       Ã¶¾Ù×ÓÊ÷µÄÐÎÌ¬£ºdp[ i ][ j ]=min{ dp[ i ][ j ]£¬dp[ i ][ k ]+dp[ i ][ l ] }£¬ÆäÖÐkºÍlÊÇ¶ÔjµÄÒ»¸ö»®·Ö¡£
       °´ÕÕ±ß½øÐÐËÉ³Ú£ºdp[ i ][ j ]=min{ dp[ i ][ j ]£¬dp[ i' ][ j ]+w[ i ][ i' ] }£¬ÆäÖÐiºÍi'Ö®¼äÓÐ±ßÏàÁ¬¡£

       ¶ÔÓÚµÚÒ»ÖÖ×ªÒÆ£¬ÎÒÃÇÖ±½ÓÃ¶¾Ù×Ó¼¯¾ÍÐÐÁË¡£¶ÔÓÚµÚ¶þÖÖ×ªÒÆ£¬ÎÒÃÇ×ÐÏ¸¹Û²ì¿ÉÒÔ·¢ÏÖÕâ¸ö·½³ÌºÍ×î¶ÌÂ·µÄÔ¼ÊøÌõ¼þÊÇºÜÀàËÆµÄ£¬ÓÚÊÇÎÒÃÇ¿ÉÒÔÓÃspfa»òÕßdijÀ´½øÐÐ×´Ì¬×ªÒÆ¡£
       Ã¶¾Ù×Ó¼¯µÄ¸´ÔÓ¶È=n*sum{C(k£¬i)*2^i£¬0<i=k}=n*3^k£¬spfaµÄ¸´ÔÓ¶ÈÎªn*2^k¡£ËùÒÔ×Ü¸´ÔÓ¶ÈÎªO(n*3^k)¡£
*/

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 1200
#define INF (1<<29)
#define min(a,b) ((a)<(b)?(a):(b))


struct node {

    int v,len;
    node *next;
}*head[MAX*2],tree[MAX*2];
queue<int> qu;
bool in[100][MAX];
int cost[100][MAX],dp[MAX];
int n,nn,m,k,ptr,ans,st[MAX];


void Initial() {

    ptr = 0,nn = 1<<(2*k);
    memset(st,0,sizeof(st));
    memset(in,0,sizeof(in));
    memset(head,NULL,sizeof(head));
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < nn; ++i)
            cost[j][i] = INF;
    for (int i = 0; i < k; ++i) {

        st[i] = 1<<i,cost[i][st[i]] = 0;
        st[n-k+i] = 1<<(i+k),cost[n-k+i][st[n-k+i]] = 0;//°Ñn-k+iÓ³Éäµ½i+k£¬ÕâÑù±£Ö¤×´Ì¬²»³¬¹ý2^(2*k)
    }
}
void AddEdge(int a,int b,int c) {

    tree[ptr].v = b,tree[ptr].len = c;
    tree[ptr].next = head[a],head[a] = &tree[ptr++];
}
void Spfa() {

    while (!qu.empty()) {

        int j = qu.front() / MAX;
        int i = qu.front() % MAX;
        qu.pop(),in[j][i] = false;


        node *p = head[j];
        while (p != NULL) {

            int v = p->v,nst = i | st[v];
            if (cost[j][i] + p->len < cost[v][nst]) {

                cost[v][nst] = cost[j][i] + p->len;
                if (nst == i && !in[v][nst]) {

                    in[v][nst] = true;
                    qu.push(v * MAX + nst);
                }
            }
            p = p->next;
        }
    }
}
void Steiner_Tree() {

    int i,j,t,s;


    for (i = 0; i < nn; ++i) {

        for (j = 0; j < n; ++j) {

            for (t = (i - 1) & i; t; t = (t-1) & i)
                cost[j][i] = min(cost[j][i],cost[j][t|st[j]]+cost[j][(i-t)|st[j]]);
            if (cost[j][i] < INF) qu.push(j * MAX + i),in[j][i] = true;
        }
       Spfa();
    }
}
int Check(int s) {

    int i,cnt = 0;
    for (i = 0; i < k; ++i){

        if (s & (1 << i)) cnt++;
        if (s & (1 << k + i)) cnt--;
    }
    return cnt == 0;
}
int Solve_DP() {

    int i,j,t;


    for (i = 0; i < nn; ++i) {

        dp[i] = INF;
        for (j = 0; j < n; ++j)
            dp[i] = min(dp[i],cost[j][i]);
    }
    for (i = 1; i < nn; ++i)
        if (Check(i)) for (j = (i-1)&i; j; j = (j-1) & i)
            if (Check(j)) dp[i] = min(dp[i],dp[j] + dp[i-j]);
    return dp[nn-1];
}

int main()
{
    int i,j,t,a,b,c;


    scanf("%d",&t);
    while (t--) {

        scanf("%d%d%d",&n,&m,&k);
        Initial();
        for (i = 0; i < m; ++i) {

            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            AddEdge(a,b,c);
            AddEdge(b,a,c);
        }

        Steiner_Tree();
        ans = Solve_DP();
        if (ans < INF) printf("%d\n",ans);
        else printf("No solution\n");
    }
}
