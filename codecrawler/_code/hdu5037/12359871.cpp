#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>

using namespace std;

typedef long long llo;
typedef double llb;

#define con continue
#define vec vector
#define str string
#define pt puts("");
#define pb push_back
#define lowbit(x) (x&(-x))
#define for0(a,b) for(a=0;a<b;++a)
#define for1(a,b) for(a=1;a<=b;++a)
#define foru(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=a;i>=b;--i)

const long maxn=305000;
long tmp;
long i,j,k,l;
long n,m,len;
long last,now;
long t,tt,ans;

long a[maxn];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
    #endif
    scanf("%ld",&tt);
    for1(t,tt){
        printf("Case #%ld: ",t);
        scanf("%ld%ld%ld",&n,&m,&len);
        for1(i,n){
            scanf("%ld",&a[i]);
            if(a[i]>=m){
                --i;
                --n;
            }
        }
        sort(a+1,a+n+1);        
        a[++n]=m;
        last=-len;
        ans=0;
        for1(i,n){
            now=a[i-1];
            tmp=(a[i]-now)/(len+1);
            ans+=tmp*2;
            now+=tmp*(len+1);
            last+=tmp*(len+1);
            if(a[i]-last<=len)continue;
            ++ans;
            last=now;
        }
        printf("%ld\n",ans);
    }
    return 0;
}