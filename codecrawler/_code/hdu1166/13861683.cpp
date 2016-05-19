#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 52333;

int c[maxn];
int n;
int lowbit(int x) {return x&(-x);}
int update(int x, int val){for(int i=x; i<=n; i += lowbit(i)) c[i] +=val;}
int query(int x){int ret=0; for(int i=x; i>0; i -= lowbit(i)) ret += c[i]; return ret;}

int main()
{
        int T, x;
        char ss[10];
        scanf("%d", &T);
        for(int cas=1; cas<=T; ++cas)
        {
                scanf("%d", &n);
                memset(c, 0, sizeof(int)*(n+1));
                int x, ii, jj;
                for(int i=1; i<=n; ++i)
                {
                        scanf("%d", &x);
                        update(i, x);
                }
                printf("Case %d:\n", cas); 
                while(scanf("%s",ss))
                {
                        if(ss[0]=='E') break;
                        scanf("%d%d", &ii, &jj);
                        if(ss[0]=='A') {
                                update(ii, jj);
                        }else if(ss[0]=='S') {
                                update(ii, -jj);
                        }else if(ss[0]=='Q') {
                                int ans = query(jj) - query(ii-1);
                                printf("%d\n", ans);
                        }
                }
        }
        return 0;
}