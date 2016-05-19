#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 52333;
int SUM[maxn<<4];
int num[maxn];

void PushUp(int rt)
{
        SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}
void build(int rt, int l, int r)
{
        if(l == r)
        {
                SUM[rt] = num[l];
                return ;
        }
        int m = (l+r)>>1;
        build(rt<<1, l, m);
        build(rt<<1|1, m+1, r);
        PushUp(rt);
}
void update(int rt, int l, int r, int p, int v)
{
        if(l == r)
        {
                SUM[rt] += v;
                return ;
        }
        int m = (l+r)>>1;
        if(p<= m) update(rt<<1, l, m, p, v);
        if(p > m) update(rt<<1|1, m+1, r, p, v);
        PushUp(rt);
}

int query(int rt, int L, int R, int l, int r)
{
        if(l<=L && R<=r)
        {
                return SUM[rt];
        }
        int m = (L+R)>>1;
        int ret = 0;
        if(l<=m) ret += query(rt<<1, L, m, l, r);
        if(r >m) ret += query(rt<<1|1,m+1,R, l, r); 
        return ret;
}
int main()
{
        int T, n;
        char ss[10];
        scanf("%d", &T);
        for(int cas=1; cas<=T; ++cas)
        {
                scanf("%d", &n);
                for(int i=1; i<=n; ++i) scanf("%d", &num[i]);
                build(1, 1, n);
                int ii, jj;
                printf("Case %d:\n", cas); 
                while(scanf("%s",ss))
                {
                        if(ss[0]=='E') break;
                        scanf("%d%d", &ii, &jj);
                        if(ss[0]=='A') {
                                update(1, 1, n, ii, jj);
                        }else if(ss[0]=='S') {
                                update(1, 1, n, ii, -jj);
                        }else if(ss[0]=='Q') {
                                int ans = query(1, 1, n, ii, jj);
                                printf("%d\n", ans);
                        }
                }
        }
        return 0;
}