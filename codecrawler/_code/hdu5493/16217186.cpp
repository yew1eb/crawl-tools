#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define rdddd(x,y,z,w) scanf("%d%d%d%d",&x,&y,&z,&w)
#define rds(s) scanf("%s",s)
#define rep(i,n) for(int i=0;i<n;i++)
#define LL long long
const int N = 2e5+10;
const int M=2000;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
int MOD=1e9+7;
int cas=1;
int n,m,q;
#define lowbit(x) x&(-x)
struct node{
    int h,k;
    bool operator <(const node& o) const{
        return h<o.h;
    }
}a[N];
int sum[N];
void add(int x){
        for(int i=x;i<=n;i+=lowbit(i))
          sum[i]++;
}
int query(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)) ret+=sum[i];
    return ret;
}
int calc(int p){
    if(p<0) return -1;
    int l=1,r=n;
    int ans=-1;
    while(l<=r){
        int m=l+r>>1;
        int num=query(m);
        int left=m-num;
        if(left<p) l=m+1;
        else if(left>p) r=m-1;
        else {
            int has=query(m)-query(m-1);
            if(has==1) r=m-1;
            else return m;
        }
    }
    return -1;
}
int ans[N];
int main()
{
#ifndef ONLINE_JUDGE
  freopen("aaa","r",stdin);
#endif
    int T;
    rd(T);
    while(T--){
          rd(n);
            for(int i=1;i<=n;i++){
                rdd(a[i].h,a[i].k);
            }
            sort(a+1,a+n+1);
            for(int i=0;i<=n;i++) sum[i]=0;
            bool ok=true;
            for(int i=1;i<=n && ok;i++){
                int h=a[i].h,k=a[i].k;
                int left=n-i;
                int p;
                if(k>left){
                    ok=false;break;
                }
                if(k<=left/2) p=k;
                else p=left-k;
                int ret=calc(p+1);
                if(ret==-1) ok=false;
                else{
                    add(ret);
                    ans[ret]=h;
                }
            }
            printf("Case #%d: ",cas++);
            if(!ok) puts("impossible");
            else{
                for(int i=1;i<=n;i++){
                    printf("%d%c",ans[i],i<n?' ':'\n');
                }
            }
            //for(int i=1;i<=n;i++) printf("%d%s",pos[i],);
    }
    return 0;
}