#include <stdio.h>
#include <string.h>
typedef int LL;
const int MAXN = 50000 + 10;
int C[MAXN], n;

int lowbit(int x) {return (x&-x);}
void add(int i, int d) {for(; i <= n; i += lowbit(i)) C[i] += d;}
LL query(int i) {LL ret = 0; for(; i > 0; i -= lowbit(i)) ret += C[i]; return ret;}
int main()
{
    int T, cas, x, i, j;
    char cmd[10];
    scanf("%d",&T);
    for(cas=1; cas<=T; ++cas) {
        scanf("%d",&n);
        memset(C, 0, sizeof(int)*(n+1));
        for(i=1; i<=n; ++i) {
            scanf("%d",&x);
            add(i, x);
        }
        printf("Case %d:\n",cas);
        while(1) {
            scanf("%s",cmd);
            if(cmd[0] == 'E') break;
            scanf("%d%d",&i,&j);
            if(cmd[0] == 'A') {
                add(i, j);
            }else if(cmd[0] == 'S') {
                add(i, -j);
            }else if(cmd[0] == 'Q') {
                printf("%d\n",query(j) - query(i-1));
            }
        }
    }
    return 0;
}
