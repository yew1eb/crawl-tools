#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define clr(x,y) memset(x,y,sizeof(x))
#define inf (1<<29)
const int maxn =33;
int n , m;
double G[maxn][maxn] , diss;
char ch[maxn][maxn] , ch1[maxn] , ch2[maxn];
void floyd() {
    re(k,n) re(i,n) re(j,n) if(G[i][j] < G[i][k]*G[k][j])
        G[i][j] = G[i][k] * G[k][j];
}
int main() {
    int cas = 1;
    while(~scanf("%d",&n) && n) {
        clr(G,0);
        re(i,n) scanf("%s",ch[i]);
        scanf("%d",&m);
        while(m--) {
            int u , v;
            scanf("%s%lf%s",ch1,&diss,ch2);
            re(i,n) if(strcmp(ch[i],ch1) == 0) { u = i; break; }
            re(i,n) if(strcmp(ch[i],ch2) == 0) { v = i; break; }
            G[u][v] = diss;
        }
        floyd();
        int flag = 0;
        re(i,n) if(G[i][i] > 1) { flag = 1; break; }
        if(flag) printf("Case %d: Yes\n",cas++);
        else printf("Case %d: No\n",cas++);
    }
    return 0;
}