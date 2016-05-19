#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define LL long long
const int MAXN = 1e5 + 5;
int id1[MAXN], cnt1[MAXN];
struct P
{
    int c, d, e;
    LL v;
    P(){}
    P(int _c, int _d, int _e, LL _v){c = _c, d = _d, e = _e,v = _v;}
    bool operator == (const P &rbs)const
    {
        if(c == rbs.c && d == rbs.d && e == rbs.e)  return true;
        return false;
    }
}p[MAXN];
bool cmp1(P u, P v)
{
    if(u.c != v.c)  return u.c < v.c;
    if(u.d != v.d)  return u.d < v.d;
    return u.e < v.e;
}
const int MAXM = 1000 + 5;
int tree[MAXM][MAXM];
int lowbit(int a)
{
    return a & -a;
}
void add(int x, int y, int val)
{
    for(int i = x ; i <= 1000 ; i += lowbit(i)){
        for(int j = y ; j <= 1000 ; j+= lowbit(j))
            tree[i][j] += val;
    }
}
LL sum(int x, int y)
{
    LL ans = 0;
    for(int i = x ; i > 0 ; i -= lowbit(i)){
        for(int j = y ; j > 0 ; j -= lowbit(j)){
            ans += tree[i][j];
        }
    }
    return ans;
}
LL query(int x1, int y1, int x2, int y2)
{
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}
int main()
{
//    freopen("HDU 5517.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1 ; cas <= T ; cas++){
        int n, m;
        scanf("%d%d", &n, &m);
        memset(id1, -1, sizeof(id1));
        int a, b, c;
        for(int i = 1 ; i <= n ; i++){
            scanf("%d%d", &a, &b);
            if(id1[b] < a){
                id1[b] = a;
                cnt1[b] = 1;
            }
            else if(id1[b] == a)    cnt1[b]++;
        }
        int num = 0;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d%d", &a, &b, &c);
            if(id1[c] != -1){
                p[num++] = P(id1[c], a, b, cnt1[c]);
            }
        }
        sort(p, p + num, cmp1);
        n = 0;
        for(int i = 1 ; i < num ; i++){
            if(p[n] == p[i]){
                p[n].v += p[i].v;
            }
            else    p[++n] = p[i];
        }
//        for(int i = 0 ; i < n ; i++)
//            printf("i = %d, c = %d, d = %d, e = %d\n", i, p[i].c, p[i].d, p[i].e);
        memset(tree, 0, sizeof(tree));
        LL ans = 0;
        for(int i = n ; i >= 0 ; i--){
            if(!query(p[i].d, p[i].e, 1000, 1000))   ans += p[i].v;
            add(p[i].d, p[i].e, 1);
        }
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}