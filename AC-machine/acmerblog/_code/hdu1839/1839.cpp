#include<iostream>
 #include<queue>
 #include<vector>
 typedef long long ll;
 const int MAXN=10000+10;
 const ll inf=1e60;
 using namespace std;
 struct Node{
     int v,w,t;
 };
 vector<Node>mp[MAXN];
 ll cost[MAXN];
 ll weight[MAXN*5];
 int n,m,time;
 int limit;
 
 
 int cmp(const ll a,const ll b){
     return a>b;
 }
 
 
 void SPFA(int u){
     for(int i=1;i<=n;i++)cost[i]=inf;
     cost[1]=0;
     queue<int>Q;
     Q.push(u);
     while(!Q.empty()){
         int u=Q.front();
         Q.pop();
         for(int i=0;i<mp[u].size();i++){
             int v=mp[u][i].v;
             int t=mp[u][i].t;
             int w=mp[u][i].w;
             //这儿实在是太妙了，每次选的边都有一个限制就行了
             if(cost[u]+t<cost[v]&&w>=limit){
                 cost[v]=cost[u]+t;
                 Q.push(v);
             }
         }
     }
 }
 
 int main(){
     int _case;
     scanf("%d",&_case);
     while(_case--){
         scanf("%d%d%d",&n,&m,&time);
         for(int i=1;i<=n;i++)mp[i].clear();
         memset(weight,0,sizeof(weight));
         for(int i=1;i<=m;i++){
             int u,v,w,t;
             scanf("%d%d%d%d",&u,&v,&w,&t);
             Node p1,p2;
             p1.v=u,p2.v=v;
             p1.t=p2.t=t;
             p1.w=p2.w=w;
             weight[i]=w;//用来记录每条路的容量;
             mp[u].push_back(p2);
             mp[v].push_back(p1);
         }
         sort(weight+1,weight+m+1,cmp);
         //二分
         int low=1,high=m;
         while(low<=high){
             int mid=(low+high)/2;
             limit=weight[mid];//每次都选择一个限制
             SPFA(1);
             if(cost[n]==inf||cost[n]>time){
                 low=mid+1;
             }else 
                 high=mid-1;
         }
         printf("%d\n",weight[low]);
     }
     return 0;
 }