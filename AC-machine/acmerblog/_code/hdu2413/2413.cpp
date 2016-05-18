#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<vector>
 using namespace std;
 #define MAXN 333
 #define inf 1<<20
 typedef long long ll;
 vector<int>map[MAXN];
 int mark[MAXN];
 int ly[MAXN];
 int hp[MAXN],hq[MAXN];
 int ap[MAXN],aq[MAXN];
 int tt[MAXN][MAXN];
 int n,m;
 
 int dfs(int u)
 {
     for(int i=0;i<map[u].size();i++){
         int v=map[u][i];
         if(!mark[v]){
             mark[v]=true;
             if(ly[v]==-1||dfs(ly[v])){
                 ly[v]=u;
                 return 1;
             }
         }
     }
     return 0;
 }
 
 bool MaxMatch(int limit)
 {
     for(int i=1;i<=n;i++)map[i].clear();
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             ll t1=1ll+hp[i]+(ll)(limit-tt[i][j])*hq[i];
             ll t2=1ll+ap[j]+(ll)limit*aq[j];
             if(t1>=t2)map[i].push_back(j);
         }
     }
     int res=0;
     memset(ly,-1,sizeof(ly));
     for(int i=1;i<=n;i++){
         memset(mark,false,sizeof(mark));
         res+=dfs(i);
     }
     if(res==m)return true;
     return false;
 }
 
 int main()
 {
   //  freopen("1.txt","r",stdin);
     while(scanf("%d%d",&n,&m),(n+m)){
         for(int i=1;i<=n;i++)
             scanf("%d%d",&hp[i],&hq[i]);
         for(int i=1;i<=m;i++)
             scanf("%d%d",&ap[i],&aq[i]);
         for(int i=1;i<=n;i++)
             for(int j=1;j<=m;j++)
                 scanf("%d",&tt[i][j]);
         int low=0,high=inf,mid,ans=inf;
         while(low<=high){
             mid=(low+high)>>1;
             if(MaxMatch(mid)){
                 ans=mid;
                 high=mid-1;
             }else
                 low=mid+1;
         }
         if(ans<inf){
             printf("%d\n",ans);
         }else
             puts("IMPOSSIBLE");
     }
     return 0;
 }