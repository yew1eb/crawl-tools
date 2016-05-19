#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>

typedef long long llo;
typedef double llb;

#define con continue
#define vec vector
#define str string
#define pt puts("");
#define pb push_back
#define for0(a,b) for(a=0;a<b;++a)
#define for1(a,b) for(a=1;a<=b;++a)
#define foru(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=a;i>=b;--i)
const long maxn=2500;
const long mod=1000000000+7;

long i,j,k,l;
long t,n,sum;
long max,ans;
long a[maxn],f[maxn][maxn];

long work(long sum){
    long i,j,k,l,tmp;
    f[1][0]=1;
    max=0;
    for1(i,n){
        for0(j,sum+1)f[i+1][j]=0;
        for0(j,sum+1){
            if(j>max)break;
            if(f[i][j]){
                for0(k,a[i]+1)if(k+j<=sum){
                    f[i+1][j+k]+=f[i][j];
                    if(f[i+1][j+k]>=mod)f[i+1][j+k]-=mod;
                    if(j+k>max)max=j+k;
                }
                f[i][j]=0;
            }
        }
    }
    tmp=f[n+1][sum];
    for0(j,max+1)f[n+1][j]=0;
    return tmp;    
}
long maxd(long x,long y){
    return (x>y)?x:y;
}
long mind(long x,long y){
    return x<y?x:y;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    #endif
    scanf("%ld",&t);
    while(t--){
        scanf("%ld",&n);
        sum=0;
        for1(i,n){
            scanf("%ld",&a[i]);
            sum+=a[i];
        }
        ans=work(sum/2);
        printf("%ld\n",ans);
    }
    return 0;    
}
