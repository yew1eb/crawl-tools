#include<set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100100;
#define Ch1 (i<<1)
#define Ch2 (Ch1|1)
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,l,r) for(int i=l;i<=r;i++)

struct tnode{
    int l,r,mid;
    long long mark,sum,sumf;
}T[N<<2];
long long F[110];
int n,m,op;
long long l,r;

long long ABS(long long x){
    if(x<0) return -x;
    return x;
}

long long MAX(long long A,long long B){
    if(A>B) return A;
    else    return B;
}

long long find(long long x){
    long long Min = 0 , Max = 0;
    Rep(i,0,103)
        if(F[i]<=x) Min = MAX(F[i],Min);
        else if(F[i]>x){
            Max = F[i];
            break;
        }
    if(ABS(x-Min)<=ABS(x-Max)) return Min;
    else                       return Max;
}

void Pushdown(int i){
    if(T[i].mark){
        T[Ch1].sum = T[Ch1].sumf;T[Ch1].mark = 1;
        T[Ch2].sum = T[Ch2].sumf;T[Ch2].mark = 1;
        T[i].mark = 0;
    }
}

void Build(int l,int r,int i){
    T[i].l = l; T[i].r = r; T[i].mid = (l+r)>>1;
    T[i].mark = 0;  T[i].sum = T[i].sumf = 0;
    if(l==r){
        T[i].sumf = 1;
        return;
    }
    Build(l,T[i].mid,Ch1);Build(T[i].mid+1,r,Ch2);
    T[i].sumf = T[Ch1].sumf + T[Ch2].sumf; 
}

void Modify(int i,int x,long long delta){
    if(T[i].l==T[i].r){
        T[i].sum+=delta;
        T[i].sumf = find(T[i].sum);
        return;
    }
    Pushdown(i);
    if(x<=T[i].mid) Modify(Ch1,x,delta);
    else            Modify(Ch2,x,delta);
    T[i].sum = T[Ch1].sum + T[Ch2].sum;
    T[i].sumf = T[Ch1].sumf + T[Ch2].sumf;
}

void Modifyf(int i,int l,int r){
    if(l<=T[i].l&&T[i].r<=r){
        T[i].mark = 1;
        T[i].sum = T[i].sumf;
        return;
    }
    Pushdown(i);
    if(r<=T[i].mid)  Modifyf(Ch1,l,r);else
    if(l>T[i].mid)   Modifyf(Ch2,l,r);else
    Modifyf(Ch1,l,T[i].mid) , Modifyf(Ch2,T[i].mid+1,r);
    T[i].sum = T[Ch1].sum + T[Ch2].sum;
    T[i].sumf = T[Ch1].sumf + T[Ch2].sumf;
}

long long query(int l,int r,int i){
    if(l<=T[i].l&&T[i].r<=r) return T[i].sum;
    Pushdown(i);
    if(r<=T[i].mid) return query(l,r,Ch1);else
    if(l>T[i].mid)  return query(l,r,Ch2);else
    return   query(l,T[i].mid,Ch1) + query(T[i].mid+1,r,Ch2);
    
}

void init(){
    while(scanf("%d%d",&n,&m)!=EOF){
        Build(1,n,1);
        For(i,m){
            scanf("%d%I64d%I64d",&op,&l,&r);
            if(op==1)   Modify(1,l,r);
            if(op==2)   printf("%I64d\n",query(l,r,1));
            if(op==3)   Modifyf(1,l,r);
        }
    }
}

int main(){
    F[0] = 1; F[1] = 1;
    Rep(i,2,103) F[i] = F[i-1] + F[i-2];
    init();    
    return 0;
}