#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
#define LL long long
const int mod=123456789;
int n,m;
int a[10005];
int b[10005],cnt;

inline void Add(int &a,int b){
    a=(a+b)%mod;
}
inline int lowbit(int x){
    return x&(-x);
}
int sum[101][10005];
inline void add(int id,int x,int v){
    while(x<=cnt){
        Add(sum[id][x],v);
        x+=lowbit(x);
    }
}
inline int query(int id,int x){
    int ans=0;
    while(x){
        Add(ans,sum[id][x]);
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[++cnt]=a[i];
        }
        sort(b+1,b+cnt+1);
        cnt=(int)(unique(b+1,b+1+cnt)-(b+1));
        for(int i=1;i<=n;i++)a[i]=(int)(lower_bound(b+1,b+1+cnt,a[i])-b);
        
        memset(sum,0,sizeof sum);
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                if(a[i]>1){
                    int sum=query(j,a[i]-1);
                    add(j+1,a[i],sum);
                }
            }
            add(1,a[i],1);
        }
        ans=query(m,cnt);
        printf("%d\n",ans);
    }
    return 0;
}