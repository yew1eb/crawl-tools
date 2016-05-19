#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<ctime>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define inf 1<<30
#define N 100005
#define pi acos(-1.0)
#define pb(a) push_back(a)
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct SegmentTree{
    int left,right,mid;
    int mx,lx,rx;
    int dist(){return right-left+1;}
}L[N*4];
int a[N];
void Push_Up(int step){
    L[step].lx=L[lson].lx+((L[lson].lx==L[lson].dist()&&a[L[rson].left]>a[L[lson].right])?L[rson].lx:0);
    L[step].rx=L[rson].rx+((L[rson].rx==L[rson].dist()&&a[L[rson].left]>a[L[lson].right])?L[lson].rx:0);
    L[step].mx=max(max(L[lson].mx,L[rson].mx),a[L[rson].left]>a[L[lson].right]?(L[lson].rx+L[rson].lx):0);
}
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    if(l==r){
        L[step].lx=L[step].rx=L[step].mx=1;
        return;
    }
    Bulid(lson,l,L[step].mid);
    Bulid(rson,L[step].mid+1,r);
    Push_Up(step);
}
void Update(int step,int pos,int k){
    if(L[step].left==L[step].right){
        L[step].lx=L[step].rx=L[step].mx=1;
        return ;
    }
    if(pos<=L[step].mid) Update(lson,pos,k);
    else Update(rson,pos,k);
    Push_Up(step);
}
int Query(int step,int l,int r){
    if(l==L[step].left&&r==L[step].right)
        return L[step].mx;
    if(r<=L[step].mid) return Query(lson,l,r);
    else if(l>L[step].mid) return Query(rson,l,r);
    else{
        int ltmp=Query(lson,l,L[step].mid);
        int rtmp=Query(rson,L[step].mid+1,r);
        int sum=0;
        if(a[L[rson].left]>a[L[lson].right])
            sum=min(L[step].mid-l+1,L[lson].rx)+min(r-L[step].mid,L[rson].lx);
        return max(max(ltmp,rtmp),sum);
    }
}
int main(){
    int t,n,m,l,r;
    char str[10];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        Bulid(1,0,n-1);
       // for(int i=1;i<=30;i++)
        //   printf("%d %d %d %d %d\n",L[i].left,L[i].right,L[i].mx,L[i].lx,L[i].rx);
        while(m--){
            scanf("%s%d%d",str,&l,&r);
            if(str[0]=='Q') printf("%d\n",Query(1,l,r));
            else {a[l]=r;Update(1,l,r);}
        }
    }
    return 0;
}