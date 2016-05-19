#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=200+10;
int n,m,size,val[MAX];
int dp[MAX],head[MAX],temp[MAX];

struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];

void Init(int num){
    for(int i=0;i<=num;++i)head[i]=-1;
    size=0;
}

void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++;
}

int dfs(int u,int Id){
    int last=0,now=0;
    dp[Id]=0;
    for(int i=head[u];i != -1;i=edge[i].next){
        int v=edge[i].v;
        now=dfs(v,Id+last+1)+1;
        for(int j=last+1;j<=last+now;++j)dp[Id+j]=0;
        for(int j=last;j>=0;--j){
            for(int k=1;k<=now;++k){
                dp[Id+j+k]=max(dp[Id+j+k],dp[Id+j]+temp[k-1]+val[v]);
            }
        }
        last+=now;
    }
    for(int i=1;i<=last;++i)temp[i]=dp[Id+i];
    return last;
}

int main(){
    int a;
    while(~scanf("%d%d",&n,&m),n+m){
        Init(n);
        for(int i=1;i<=n;++i){
            scanf("%d%d",&a,&val[i]);
            InsertEdge(a,i);
        }
        dfs(0,0);
        printf("%d\n",temp[m]);
    }
    return 0;
}



   
