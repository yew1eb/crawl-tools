#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 100000 + 10;
int num[maxn*4], lazy[maxn*4], L[maxn*4], R[maxn*4];

int gcd(int a, int b){ return b?gcd(b, a%b):a; }

void PushUp(int rt){
    if(num[rt<<1]==num[rt<<1|1]){
        num[rt] = num[rt<<1];
    }else num[rt] = -1;
}

void PushDown(int rt)
{
    if(lazy[rt]){
        lazy[rt<<1] = lazy[rt<<1|1] = 1;
        num[rt<<1] = num[rt<<1|1] = num[rt];
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r)
{
    L[rt] = l, R[rt] = r;
    lazy[rt] = 0;
    if(l == r)
    {
        scanf("%d", &num[rt]);
        return ;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
}

void update1(int rt, int l, int r, int x){
    if(l<=L[rt] && R[rt]<=r){
        lazy[rt] = 1;
        num[rt] = x;
        return ;
    }
    PushDown(rt);
    int mid = (L[rt]+R[rt])>>1;
    if(l<=mid) update1(rt<<1, l, r, x);
    if(r> mid) update1(rt<<1|1, l, r, x);
    PushUp(rt);
}

void update2(int rt, int l, int r, int x)
{
    if(l<=L[rt] && R[rt]<=r && num[rt]!=-1) {
        if(num[rt]>x){
            num[rt] = gcd(num[rt], x);
            lazy[rt] = 1;
        }
        return ;
    }
    PushDown(rt);
    int mid = (L[rt]+R[rt])>>1;
    if(l<=mid) update2(rt<<1, l, r, x);
    if(r> mid) update2(rt<<1|1, l, r, x);
    PushUp(rt);
}
void query(int rt)
{
    if(L[rt]==R[rt]){
        printf("%d ", num[rt]);
        return ;
    }
    PushDown(rt);
    int mid = (L[rt]+R[rt])>>1;
    query(rt<<1);
    query(rt<<1|1);
}

int main()
{
    int n, m, i, T, t, l, r, x;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d%d%d%d", &t, &l, &r, &x);
            if(t==1){
                update1(1, l, r, x);
            }else {
                update2(1, l, r, x);
            }
        }
        query(1);
        printf("\n");
    }
    return 0;
}
