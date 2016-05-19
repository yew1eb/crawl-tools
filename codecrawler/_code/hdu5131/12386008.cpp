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
const int maxn=205;


int n,m,ans;
int a[maxn],b[maxn];
int ans1[maxn],ans2[maxn];
char c[maxn][maxn],cc[maxn];

int cmp(int x,int y){
    if(a[x]==a[y]){
        return strcmp(c[x]+1,c[y]+1)<0;
    }
    return a[x]>a[y];
}
int main(){
    while(~scanf("%d",&n)){
        if(!n)return 0;
        REP1(i,n){
            scanf("%s%d",c[i]+1,&a[i]);
            b[i]=i;
        }
        sort(b+1,b+n+1,cmp);
        REP1(i,n){
            printf("%s %d\n",c[b[i]]+1,a[b[i]]);
        }
        for(int i=1;i<=n;){
            int j=i,k=0;
            for(;i<=n && (a[b[i]]==a[b[j]]);++i,++k){
                ans1[b[i]]=j;
                ans2[b[i]]=i-j+1;
            }
        }
        scanf("%d",&m);
        REP1(i,m){
            scanf("%s",cc+1);
            for1(ans,n){
                if(!strcmp(cc+1,c[ans]+1))break;
            }
            if(ans2[ans]<2)printf("%d\n",ans1[ans]);
            else printf("%d %d\n",ans1[ans],ans2[ans]);
        }
    }
    return 0;
}