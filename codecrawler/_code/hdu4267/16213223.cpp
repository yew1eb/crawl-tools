#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
#include<map>
#define eps 1e-7
#define LL long long
#define N 500005
#define zero(a) fabs(a)<eps
#define lson step<<1
#define rson step<<1|1
#define MOD 1234567891
#define pb(a) push_back(a)
using namespace std;
struct Node{
    int left,right,add[55],sum;
    int mid(){return (left+right)/2;}
}L[4*N];
int a[N],n,b[11][11];
void Bulid(int step ,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].sum=0;
    memset(L[step].add,0,sizeof(L[step].add));
    if(l==r) return ;
    Bulid(lson,l,L[step].mid());
    Bulid(rson,L[step].mid()+1,r);
}
void push_down(int step){
    if(L[step].sum){
        L[lson].sum+=L[step].sum;
        L[rson].sum+=L[step].sum;
        L[step].sum=0;
        for(int i=0;i<55;i++){
                L[lson].add[i]+=L[step].add[i];
                L[rson].add[i]+=L[step].add[i];
                L[step].add[i]=0;
        }
    }
}
void update(int step,int l,int r,int num,int i,int j){
    if(L[step].left==l&&L[step].right==r){
        L[step].sum+=num;
        L[step].add[b[i][j]]+=num;
        return;
    }
    push_down(step);
    if(r<=L[step].mid()) update(lson,l,r,num,i,j);
    else if(l>L[step].mid()) update(rson,l,r,num,i,j);
    else {
        update(lson,l,L[step].mid(),num,i,j);
        update(rson,L[step].mid()+1,r,num,i,j);
    }
}
int query(int step,int pos){
    if(L[step].left==L[step].right){
        int tmp=0;
        for(int i=1;i<=10;i++)  tmp+=L[step].add[b[i][pos%i]];
        return a[L[step].left]+tmp;
    }
    push_down(step);
    if(pos<=L[step].mid()) return query(lson,pos);
    else return query(rson,pos);
}
int main(){
    int cnt=0;
    for(int i=1;i<=10;i++) for(int j=0;j<i;j++) b[i][j]=cnt++;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        Bulid(1,1,n);
        int q,d;
        scanf("%d",&q);
        while(q--){
            int k,l,r,m;
            scanf("%d",&k);
            if(k==2){
                scanf("%d",&m);
                printf("%d\n",query(1,m));
            }
            else{
                scanf("%d%d%d%d",&l,&r,&d,&m);
                update(1,l,r,m,d,l%d);
            }
        }
    }
    return 0;
}
