#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<28
#define M 6000005
#define N 100005
#define maxn 300005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct Tree{
    int left,right,cnt;
}L[N*4];
struct Q{
    int l,r,h,id;
    bool operator <(const Q q1)const{
        return h<q1.h;
    }
}que[N];
struct Node{
    int pos,val;
    bool operator<(const Node n1)const{
        return val<n1.val;
    }
}nod[N];
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].cnt=0;
    if(l==r) return;
    int m=(l+r)/2;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
}
void Update(int step,int pos){
    L[step].cnt++;
    if(L[step].left==L[step].right) return;
    int m=(L[step].left+L[step].right)/2;
    if(pos<=m) Update(lson,pos);
    else Update(rson,pos);
}
int Query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
         return L[step].cnt;
    int m=(L[step].left+L[step].right)/2;
  //  printf("%d %d %d %d\n",L[step].left,L[step].right,l,r);
    if(r<=m) return Query(lson,l,r);
    else if(l>m) return Query(rson,l,r);
    else return Query(lson,l,m)+Query(rson,m+1,r);
}
int ans[N];
int main(){
    int t,cas=0,n,q;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++){
            scanf("%d",&nod[i].val);
            nod[i].pos=i+1;
        }
        for(int i=0;i<q;i++){
            que[i].id=i;
            scanf("%d%d%d",&que[i].l,&que[i].r,&que[i].h);
        }
        sort(nod,nod+n);
        sort(que,que+q);
        Bulid(1,1,n);
        printf("Case %d:\n",++cas);
        int k=0;
        for(int i=0;i<q;i++){
            while(k<n&&nod[k].val<=que[i].h){
                Update(1,nod[k].pos);
                k++;
            }
            ans[que[i].id]=Query(1,que[i].l+1,que[i].r+1);
        }
        for(int i=0;i<q;i++) printf("%d\n",ans[i]);
    }
    return 0;
}