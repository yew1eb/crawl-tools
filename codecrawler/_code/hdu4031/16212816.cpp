#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000
#define M 10005
#define N 200005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
using namespace std;
struct Node{
    int left,right,mid;
    int sum;
}L[N*4];
struct Attack{
    int left,right;
    Attack(){}
    Attack(int a,int b){left=a;right=b;}
}att[N];
int n,q,t,tot,cnt[N],pos[N];
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].sum=0;
    if(l==r) return;
    Bulid(lson,l,L[step].mid);
    Bulid(rson,L[step].mid+1,r);
}
void Push_Down(int step){
    if(L[step].sum){
        L[lson].sum+=L[step].sum;
        L[rson].sum+=L[step].sum;
        L[step].sum=0;
    }
}
void Update(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r){
        L[step].sum++;
        return;
    }
    Push_Down(step);
    if(r<=L[step].mid) Update(lson,l,r);
    else if(l>L[step].mid) Update(rson,l,r);
    else{
        Update(lson,l,L[step].mid);
        Update(rson,L[step].mid+1,r);
    }
}
int Query(int step,int pos){
    if(L[step].left==L[step].right)
        return L[step].sum;
    Push_Down(step);
    if(pos<=L[step].mid) return Query(lson,pos);
    else Query(rson,pos);
}
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&q,&t);
        Bulid(1,1,n);
        tot=0;mem(cnt,0);mem(pos,0);
        printf("Case %d:\n",++cas);
        while(q--){
            char str[10];
            int l,r;
            scanf("%s",str);
            if(str[0]=='A'){
                scanf("%d%d",&l,&r);
                Update(1,l,r);
                att[tot++]=Attack(l,r);
            }
            else{
                scanf("%d",&l);
                if(t==1){puts("0");continue;}
                for(int i=pos[l];i<tot;i++){
                    if(l>=att[i].left&&l<=att[i].right){
                        cnt[l]++;
                        pos[l]=i+t;
                        i+=t-1;
                    }
                }
                printf("%d\n",Query(1,l)-cnt[l]);
            }
        }
    }
    return 0;
}
