#include <stdio.h>
const int maxn = 100005;

int num[maxn<<2];

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

void PushUp(int id){
    if(num[id<<1] == num[id<<1|1]){
        num[id] = num[id<<1];
    }
}

void PushDown(int id){
    if(num[id] != -1){
        num[id<<1] = num[id<<1|1] = num[id];
        num[id] = -1;
    }
}

void Build(int l, int r, int id){
    num[id] = -1;
    if(l == r){
        scanf("%d", &num[id]);
        return ;
    }
    int mid = (l+r)>>1;
    Build(l, mid, id<<1);
    Build(mid+1, r, id<<1|1);
    PushUp(id);
}


void Update(int op, int L, int R, int t, int l, int r, int id){
    if(op == 1){
        if(L <= l && r <= R){
            num[id] = t;
            return ;
        }
    }
    else if(op == 2){
        if(L <= l && r <= R && num[id] != -1){
            if(num[id] > t){
                num[id] = gcd(num[id], t);
            }
            return ;
        }
    }
    PushDown(id);
    int mid = (l+r)>>1;
    if(L <= mid){
        Update(op, L, R, t, l, mid, id<<1);
    }
    if(R > mid){
        Update(op, L, R, t, mid+1, r, id<<1|1);
    }
    PushUp(id);
}

void Query(int l, int r, int id){
    if(l == r){
        printf("%d ", num[id]);
        return ;
    }
    PushDown(id);
    int mid = (l+r)>>1;
    Query(l, mid, id<<1);
    Query(mid+1, r, id<<1|1);
}

int T, n, m;

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        Build(1, n, 1);
        scanf("%d", &m);
        while(m--){
            int op, a, b, c;
            scanf("%d%d%d%d", &op, &a, &b, &c);
            Update(op, a, b, c, 1, n, 1);
        }
        Query(1, n, 1);
        puts("");
    }

    return 0;
}
