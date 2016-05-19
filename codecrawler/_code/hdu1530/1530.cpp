#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define debug puts("here")
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define foreach(i,vec) for(unsigned i=0;i<vec.size();i++)
#define pb push_back
#define RD(n) scanf("%d",&n)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define RD4(x,y,z,w) scanf("%d%d%d%d",&x,&y,&z,&w)
#define All(vec) vec.begin(),vec.end()
#define MP make_pair
#define PII pair<int,int>
#define PQ priority_queue
#define cmax(x,y) x = max(x,y)
#define cmin(x,y) x = min(x,y)
#define Clear(x) memset(x,0,sizeof(x))
/*

#pragma comment(linker, "/STACK:1024000000,1024000000")

int size = 256 << 20; // 256MB
char *p = (char*)malloc(size) + size;
__asm__("movl %0, %%esp\n" :: "r"(p) );

*/

char IN;
bool NEG;
inline void Int(int &x){
    NEG = 0;
    while(!isdigit(IN=getchar()))
        if(IN=='-')NEG = 1;
    x = IN-'0';
    while(isdigit(IN=getchar()))
        x = x*10+IN-'0';
    if(NEG)x = -x;
}
inline void LL(ll &x){
    NEG = 0;
    while(!isdigit(IN=getchar()))
        if(IN=='-')NEG = 1;
    x = IN-'0';
    while(isdigit(IN=getchar()))
        x = x*10+IN-'0';
    if(NEG)x = -x;
}

/******** program ********************/

const int MAXN = 50;

int g[MAXN][MAXN],n;
bool use[MAXN];
int dp[MAXN],best;
//int pre[MAXN],path[MAXN]; // 记录路径

bool dfs(int *id,int top,int cnt){
    if(!top){
        if(best<cnt){
            //copy( pre+1,pre+cnt+1,path ); // 记录路径
            best = cnt;
            return true;
        }
        return false;
    }
    int a[MAXN];
    rep(i,top){
        if(cnt+top-i<=best)return false;
        if(cnt+dp[id[i]]<=best)return false;
        //pre[cnt] = id[i]; // 记录路径
        int k = 0;
        for(int j=i+1;j<top;j++)
            if(g[id[i]][id[j]])
                a[k++] = id[j];
        if(dfs(a,k,cnt+1))return true;
    }
    return false;
}

inline int solve(){
    int id[MAXN];
    best = 0;
    for(int i=n-1;i>=0;i--){
        int top = 0;
        for(int j=i+1;j<n;j++)
            if(g[i][j])
                id[top++] = j;
        dfs(id,top,1);
        dp[i] = best;
    }
    return best;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
#endif

    while(1){
        Int(n);
        if(!n)break;
        rep(i,n)
            rep(j,n)
                Int(g[i][j]);
        cout<<solve()<<endl;
    }

    return 0;
}