#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 20000+100;
int a[maxn];
int l[maxn],r[maxn];
int cnt[100100];
int lowbit(int x){
    return x&(-x);
}
int sum(int x){
    int res=0;
    while(x>0){
       res+=cnt[x];  x-=lowbit(x);
    }
     return res;
}
void add(int x){
    while(x<=100005){
       cnt[x]+=1;  x+=lowbit(x);
    }
}
int main(){
    int T,n;  scanf("%d",&T);
    while(T--){
         scanf("%d",&n);
         for(int i=1;i<=100000;i++)  cnt[i]=0;
         memset(l,0,sizeof(l));  memset(r,0,sizeof(r));
         for(int i=1;i<=n;i++)  scanf("%d",&a[i]);

         for(int i=1;i<=n;i++){
             add(a[i]);
             l[i]=sum(a[i]-1);
         }
         for(int i=1;i<=100000;i++)  cnt[i]=0;
         for(int i=n;i>=1;i--){
             add(a[i]);
             r[i]=sum(a[i]-1);
         }
         long long ans=0;
         for(int i=2;i<=n;i++){
             ans+=(long long)l[i]*(n-i-r[i])+(i-1-l[i])*(long long)r[i];
         }

         printf("%I64d\n",ans);
    }
    return 0;
}
