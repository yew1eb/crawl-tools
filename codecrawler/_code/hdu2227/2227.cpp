#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000000007;
const int maxn=100000;
struct node{
    int num;
    int id;
}a[maxn+10];
__int64 dp[maxn+10];
int num[maxn+10];
int cmp(node a,node b){
    if(a.num!=b.num)
        return a.num<b.num;
    return a.id<b.id;
}
int lowbit(int x){
    return x&-x;
}
void update(int x,__int64 d){
    for(;x<=maxn;x+=lowbit(x)){
        dp[x]+=d;
        if(dp[x]>=mod) dp[x]-=mod;
    }
}
__int64 sum(int x){
    __int64 ans=0;
    for(;x>0;x-=lowbit(x)){
        ans+=dp[x];
        if(ans>=mod)     ans-=mod;
    }
    return ans;
}
int main(){
    int n,i;
    __int64 ans;
    while(scanf("%d",&n)!=EOF){
        ans=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i].num);
            a[i].id=i;
        } 
        sort(a+1,a+n+1,cmp);
        for(i=1;i<=n;i++){
            __int64 s=sum(a[i].id)+1;
            update(a[i].id,s);
            ans+=s;
            if(ans>=mod) ans-=mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}