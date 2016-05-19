#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>

#define lson l, m, rt << 1
#define rson m+1, r, rt<<1|1
using namespace std;

const int maxn = 100010;
int tree[maxn << 2];
int CLF[maxn<<2];
void PushUp(int rt){
    tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}
void PushDown(int rt){
    if(!CLF[rt]) return;
    tree[rt<<1] = tree[rt<<1|1] = tree[rt];
    CLF[rt] = 0;
    CLF[rt<<1|1] = CLF[rt<<1] = 1;
}

void Build(int l, int r, int rt){
    CLF[rt] = 0;
    if(l == r){
        int tmp;
        scanf("%d", &tmp);
        tree[rt] = tmp;
        return;
    }
    int m = (l + r)>>1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}

void Change1(int l, int r, int rt, int L, int R, int x){
    if(L <= l && r <= R){
        tree[rt] = x;
        CLF[rt] = 1;
        return ;
    }
    int m = (l + r) >> 1;
    PushDown(rt);
    if(L <= m)
        Change1(lson, L, R, x);
    if(m < R)
        Change1(rson, L, R, x);
    PushUp(rt);
}
int gcd(int a, int b){
    while(b){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void Change2(int l, int r, int rt, int L, int R, int x){
    if(L <= l && r <= R && CLF[rt] && tree[rt] > x){
        tree[rt] = gcd(tree[rt], x);
        return;
    }
    if(l == r){
        tree[rt] = gcd(tree[rt], x);
        return ;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m && tree[rt<<1] > x)
        Change2(lson, L, R, x);
    if(m < R && tree[rt<<1|1] > x)
        Change2(rson, L, R, x);
    PushUp(rt);
}
void Query(int l, int r, int rt){
    if(CLF[rt]){
        for(int i = r - l + 1; i; i--){
            printf("%d ", tree[rt]);
        }
        return;
    }
    if(l == r){
        printf("%d ", tree[rt]);
        return;
    }
    int m = (l + r) >> 1;
    Query(lson);
    Query(rson);
}
int main()
{
    int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        Build(1, n, 1);
        int q;
        scanf("%d", &q);
        while(q--){
            int c, l, r, num;
            scanf("%d%d%d%d", &c, &l, &r, &num);
            if(c == 1){
                Change1(1, n, 1, l, r, num);
            }
            if(c == 2)
                Change2(1, n, 1, l, r, num);
        }
        Query(1, n, 1);
        printf("\n");
    }
    return 0;
}