#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf (1ull<<63)-1
#define N 100005
#define maxn 100005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define ULL unsigned long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
#define mp(a,b) make_pair(a,b)
using namespace std;
struct Node{
    int left,right;
    int cnt;
    LL sum[5];
}L[N*4];
int n,tot,a[N],k,q[N];
char str[N][10];
void Bulid(int step,int l,int r){
    L[step].left=l;L[step].right=r;
    L[step].cnt=0;
    memset(L[step].sum,0,sizeof(L[step].sum));
    if(l==r) return ;
    int m=(l+r)/2;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
}
void Push_Up(int step){
    for(int i=0;i<5;i++)
        L[step].sum[i]=(LL)L[lson].sum[i]+L[rson].sum[((i-L[lson].cnt)%5+5)%5];
}
void Update(int step,int pos,int num){
    L[step].cnt+=2*k-1;
    if(L[step].left==L[step].right){
        L[step].sum[0]=(LL)k*num;
        return;
    }
    int m=(L[step].left+L[step].right)/2;
    if(pos<=m) Update(lson,pos,num);
    else Update(rson,pos,num);
    Push_Up(step);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        tot=0;
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            if(str[i][0]!='s'){
                scanf("%d",&q[i]);
                a[tot++]=q[i];
            }
        }
        sort(a,a+tot);
        tot=unique(a,a+tot)-a;
        if(tot==0) memset(L[1].sum,0,sizeof(L[1].sum));
        else
        Bulid(1,1,tot);
        for(int i=0;i<n;i++){
            int pos=lower_bound(a,a+tot,q[i])-a;
            if(str[i][0]=='a')k=1,Update(1,pos,q[i]);
            else if(str[i][0]=='d') k=0,Update(1,pos,q[i]);
            else printf("%I64d\n",L[1].sum[2]);
        }
    }
    return 0;
}
    
