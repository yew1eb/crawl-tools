#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 100000 + 10;
int num[maxn*4], L[maxn*4], R[maxn*4];
int n;

int gcd(int a, int b)
{
    return b?gcd(b, a%b):a;
}

void PushUp(int rt)
{
    if(num[rt<<1]==num[rt<<1|1]) {
        num[rt] = num[rt<<1];
    }
}

void PushDown(int rt)
{
    if(num[rt]!=-1) {
        num[rt<<1] = num[rt<<1|1] = num[rt];
        num[rt] = -1;
    }
}

void build(int rt, int l, int r)
{
    L[rt] = l, R[rt] = r;
    num[rt] = -1;
    if(l == r) {
        scanf("%d", &num[rt]);
        return ;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
    PushUp(rt);
}

void update(int rt, int l, int r, int x, int op)
{
    if(op==1){
        if(l<=L[rt] && R[rt]<=r){
            num[rt] = x;
            return ;
        }
    }else {
        if(l<=L[rt] && R[rt]<=r && num[rt] != -1){
            if(num[rt] > x){
                num[rt] = gcd(num[rt], x);
            }
            return ;
        }
    }
    PushDown(rt);
    int mid = (L[rt]+R[rt])>>1;
    if(l<=mid) update(rt<<1, l, r, x, op);
    if(r> mid) update(rt<<1|1, l, r, x, op);
    PushUp(rt);
}


void query(int rt)
{
    if(L[rt]==R[rt]) {
        printf("%d ", num[rt]);
        return ;
    }
    PushDown(rt);
    query(rt<<1);
    query(rt<<1|1);
}

int main()
{
    int m, i, T, t, l, r, x;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &m);
        while(m--) {
            scanf("%d%d%d%d", &t, &l, &r, &x);
            update(1, l, r, x, t);

        }
        query(1);
        printf("\n");
    }
    return 0;
}
