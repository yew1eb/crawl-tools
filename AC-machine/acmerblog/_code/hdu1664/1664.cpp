#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<map>
///LOOP
#define REP(i, n) for(int i = 0; i < n; i++)
#define FF(i, a, b) for(int i = a; i < b; i++)
#define FFF(i, a, b) for(int i = a; i <= b; i++)
#define FD(i, a, b) for(int i = a - 1; i >= b; i--)
#define FDD(i, a, b) for(int i = a; i >= b; i--)
///INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RIV(n, m, k, p) scanf("%d%d%d%d", &n, &m, &k, &p)
#define RV(n, m, k, p, q) scanf("%d%d%d%d%d", &n, &m, &k, &p, &q)
#define RFI(n) scanf("%lf", &n)
#define RFII(n, m) scanf("%lf%lf", &n, &m)
#define RFIII(n, m, k) scanf("%lf%lf%lf", &n, &m, &k)
#define RFIV(n, m, k, p) scanf("%lf%lf%lf%lf", &n, &m, &k, &p)
#define RS(s) scanf("%s", s)
///OUTPUT
#define PN printf("\n")
#define PI(n) printf("%d\n", n)
#define PIS(n) printf("%d ", n)
#define PS(s) printf("%s\n", s)
#define PSS(s) printf("%s ", s)
#define PC(n) printf("Case %d: ", n)
///OTHER
#define PB(x) push_back(x)
#define CLR(a, b) memset(a, b, sizeof(a))
#define CPY(a, b) memcpy(a, b, sizeof(b))
#define display(A, n, m) {REP(i, n){REP(j, m)PIS(A[i][j]);PN;}}
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int MOD = 9901;
const int INFI = 1e9 * 2;
const LL LINFI = 1e17;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int N = 66666;
const int M = 66;
const int move[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

int a[10], pre[N], val[N], a1[N], a2[N];
int na, n, n1, n2;
bool use[10];

void print(int x)
{
    if(pre[x])print(pre[x]);
    a2[n2++] = val[x];
}

void cmp()
{
    if(n1)
    {
        if(n1 < n2)return;
        else if(n1 == n2)
        {
            REP(i, n2)
            {
                if(a1[i] < a2[i])return;
                if(a1[i] == a2[i])continue;
                break;
            }
        }
    }
    n1 = n2;
    REP(i, n2)a1[i] = a2[i];
}

void bfs()
{
    int p, t;
    queue<int> q;
    CLR(pre, -1);
    REP(i, na)
    {
        if(!a[i])continue;
        t = a[i] % n;
        if(!t)
        {
            a2[0] = a[i];
            n2 = 1;
            cmp();
            return;
        }
        pre[t] = 0;
        val[t] = a[i];
        q.push(t);
    }
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        REP(i, na)
        {
            t = ((p * 10) + a[i]) % n;
            if(!t)
            {
                n2 = 0;
                print(p);
                a2[n2++] = a[i];
                cmp();
                return ;
            }
            if(pre[t] == -1)
            {
                pre[t] = p;
                val[t] = a[i];
                q.push(t);
            }
        }
    }
    return ;
}

void dfs(int x)
{
    if(x == na)
    {
        bfs();
        return;
    }
    REP(i, 10)
    {
        if(use[i])continue;
        a[x] = i;
        use[i] = 1;
        dfs(x + 1);
        use[i] = 0;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    while(RI(n), n)
    {
        FFF(i, 1, 10)
        {
            na = i;
            n1 = 0;
            CLR(use, 0);
            dfs(0);
            if(n1)break;
        }
        REP(i, n1)printf("%d", a1[i]);
        puts("");
    }
    return 0;
}