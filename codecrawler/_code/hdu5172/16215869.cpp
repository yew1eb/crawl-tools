#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
#define N 1000010
#define ls rt << 1
#define rs rt << 1 | 1
#define LL long long
struct node{
    int l,r;
    int pre;
}T[N<<2];
LL sum[N];
int pre[N],now[N];

void Pushup(int rt){
     T[rt].pre = max(T[ls].pre , T[rs].pre);
}

void build(int l,int r,int rt){
     T[rt].l = l;
     T[rt].r = r;
     if(l == r){
        T[rt].pre = now[l];
        return ;
     }
     int m = (l + r) >> 1;
     build(l,m,ls);
     build(m + 1,r,rs);
     Pushup(rt);
}

LL SUM(int l,int r){
    LL a = r - l + 1,ret;
    ret = ((LL)1+a)*a/(LL)2;
    return ret;
}

int query(int l,int r,int rt){
     if(l <= T[rt].l && T[rt].r <= r){
        return T[rt].pre;
     }
     int ret = -1;
     if( l <= T[ls].r ) ret = query(l,r,ls);
     if( r >= T[rs].l) ret = max(ret, query(l,r,rs));
     return ret;
}



int main()
{
    int n,m,t,l,r;
    LL ans;
    sum[0] = 0;
    while(~scanf("%d%d",&n,&m)){
        memset(pre,-1,sizeof(pre));
        for(int i=1;i<=n;i++){
            scanf("%d",&t);
            if(i==1){
                sum[i] = t;
            }
            else sum[i] = sum[i - 1] + (LL)t;
           // printf("%I64d ",sum[i]);//shan
            if(pre[t] == -1){
                now[i] = -1;
                pre[t] = i;
            }
            else{
                now[i] = pre[t];
                pre[t] = i;
            }
        }
        //printf("\n");// shan
        build(1,n,1);
        //printf("1\n");
        for(int i=0;i<m;i++){
            scanf("%d%d",&l,&r);
            ans = sum[r] - sum[l - 1];
            if(ans == SUM(l,r)){
            ans = query(l,r,1);
            if(ans >= l){
                printf("NO\n");
            }
            else {
                printf("YES\n");
            }
            }
            else{
                printf("NO\n");
            }
        }

    }
    return 0;
}
