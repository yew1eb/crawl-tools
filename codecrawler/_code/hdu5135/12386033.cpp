#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>
#include<math.h>

using namespace std;

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
#define REP0(a,b) for(int a=0;a<b;++a)
#define REP1(a,b) for(int a=1;a<=b;++a)
#define REPu(i,a,b) for(int i=a;i<=b;++i)
#define REPd(i,a,b) for(int i=a;i>=b;--i)

const long maxn=102,maxm=5050;

llb ans2,tmp;
int n,now,maxz,tmp2;
int a[maxn];
llb ans[maxm];

llb get(llb a,llb b,llb c){
    llb p=(a+b+c)*0.5;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
    while(~scanf("%d",&n)){
        if(!n)return 0;
        REP0(i,n)scanf("%d",&a[i]);
        sort(a,a+n);
        
        maxz=1<<n;
        
        ans2=0;
        memset(ans,0,sizeof(ans));
        
        for0(now,maxz){
            if(ans[now]>ans2)ans2=ans[now];
            REP0(i,n){
                if((1<<i)&now)continue;
                REPu(j,i+1,n-1){
                    if((1<<j)&now)continue;
                    REPu(k,j+1,n-1){
                        if((1<<k)&now)continue;
                        tmp=ans[now]+get(a[i],a[j],a[k]);
                        tmp2=now+(1<<i)+(1<<j)+(1<<k);
                        if(tmp>ans[tmp2])ans[tmp2]=tmp;
                    }
                }
            }
        }
        printf("%.2lf\n",ans2);
    }
    return 0;    
}