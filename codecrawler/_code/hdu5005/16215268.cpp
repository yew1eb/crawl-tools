#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define maxn 210
using namespace std;
struct node{
    int id,A,B;
    node(){}
    node(int x,int y,int z){
        id=x,A=y,B=z;
    }
};
vector<int> e[maxn];
vector<node> vec;
int bel[maxn],A[maxn],B[maxn],dp[maxn][2],vis[maxn];;
bool cmp(const node &x,const node &y){
    return x.B>y.B;
}
void init(int n){
    for(int i=1;i<=n;i++)
    e[i].clear();
}
void dfs1(int now){//cannot make the claim.
    if(dp[now][0]!=-1)//è®°å¿åæç´¢
    return;
    if(bel[now]==-1){//ä¸å±äºä»»ä½äºº
        dp[now][0]=A[now];
        dp[now][1]=B[now];
        return;
    }
    for(int i=0;i<e[now].size();i++){
        int v=e[now][i];
        dfs1(v);
        if(bel[now]==0){//å±äºA
            if(dp[v][0]>dp[now][0]){
                dp[now][0]=dp[v][0];
                dp[now][1]=dp[v][1];
            }
        }
        else{//å±äºX
            if(dp[v][1]>dp[now][1]){
                dp[now][0]=dp[v][0];
                dp[now][1]=dp[v][1];
            }
        }
    }
}
int dfs2(int now,int limit){//can make the claim
    if(vis[now]!=-1)
    return vis[now];
    if(bel[now]==-1){
        if(A[now]>limit)
        return vis[now]=0;
        return vis[now]=1;
    }
    for(int i=0;i<e[now].size();i++){
        int v=e[now][i];
        dfs2(v,limit);
    }
    for(int i=0;i<e[now].size();i++){
        int v=e[now][i];
        if(bel[now]==0){
            if(!vis[v])
            return vis[now]=0;
        }
        else if(vis[v])
        return vis[now]=1;
    }
    if(bel[now]==0)
    return vis[now]=1;
    return vis[now]=0;
}
int dfs3(int now,int limit){
    if(bel[now]==-1){
        return limit==A[now];
    }
    for(int i=0;i<e[now].size();i++){
        int v=e[now][i];
        if(vis[v]==1&&dfs3(v,limit))
        return 1;
    }
    return 0;
}
int main()
{
   // freopen("dd.txt","r",stdin);
    int ncase,n,num,x;
    char typ[4];
    scanf("%d",&ncase);
    while(ncase--){
        scanf("%d",&n);
        init(n);
        vec.clear();
        memset(bel,-1,sizeof(bel));
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            if(num==0){//å¶å­èç¹
                scanf("%d%d",&A[i],&B[i]);
                vec.push_back(node(i,A[i],B[i]));
            }
            else{
                for(int j=0;j<num;j++){
                    scanf("%d",&x);
                    e[i].push_back(x);
                }
                scanf("%s",typ);
                if(typ[0]=='A')
                bel[i]=0;
                else
                bel[i]=1;
            }
        }
        dfs1(1);
        int ans1=dp[1][1];
        sort(vec.begin(),vec.end(),cmp);
        int ans2=-1;
        for(int i=0;i<(int)vec.size();i++){//æä¸¾Xå°è¾¾çå¶å­èç¹
            memset(vis,-1,sizeof(vis));
            int now=vec[i].id;
            if(dp[now][0]==-1)//è¥nowä¸è½ç±æ ¹èç¹å°è¾¾ï¼åè·³è¿
            continue;
            if(dfs2(1,vec[i].A)){
                if(dfs3(1,vec[i].A)){
                    ans2=vec[i].B;
                    break;
                }
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
