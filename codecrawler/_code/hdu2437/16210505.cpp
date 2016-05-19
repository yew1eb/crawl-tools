#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<stack>
#define cl(a,b) memset(a,b,sizeof(a));
#define LL long long
#define P pair<int,int>
#define X first
#define Y second
#define pb push_back
#define out(x) cout<<x<<endl;
using namespace std;
const int maxn=1005;
const int inf=9999999;

struct node {
    int to,cost;
    node(){}
    node(int a,int b):to(a),cost(b){}
};

int n,m,s,k;
char str[maxn];
vector< vector<node> > G;
bool vis[maxn];
int mod[maxn][maxn];
int ans;
int aim;
void dfs(int x,LL sum){

    if(ans!=-1&&sum>ans)return ;
    if(str[x-1]=='P'&&sum%k==0){
        if(ans==-1||ans>sum){
            ans=sum;aim=x;
        }else if(ans==sum&&x<aim){
            aim=x;
        }
        return ;
    }
    int N=G[x].size();
    for(int i=0;i<N;i++){
        int to=G[x][i].to;
        int dis=sum+G[x][i].cost;
        if(mod[to][dis%k]!=-1&&mod[to][dis%k]<=dis)continue;
        mod[to][dis%k]=dis;
        dfs(to,dis);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--){
        scanf("%d%d%d%d",&n,&m,&s,&k);
        scanf("%s",str);
        G.clear();
        G.resize(n+2);
        for(int i=0;i<m;i++){
            int x,y,cost;
            scanf("%d%d%d",&x,&y,&cost);
            vis[x]=vis[y]=false;
            G[x].pb(node(y,cost));
        }
        cl(mod,-1);
        ans=-1;
        vis[s]=true;
        dfs(s,0);
        if(ans!=-1){
            printf("Case %d: %d %d\n",cas++,ans,aim);
        }
        else {
            printf("Case %d: %d %d\n",cas++,-1,-1);
        }
    }
    return 0;
}
