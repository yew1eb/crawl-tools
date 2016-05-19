#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define sz 10005
#define inf 0x7fffffff
struct node{int s,t,v,nxt;}e[sz*100];
int hd[sz],dis[sz],cur[sz],que[sz],cnt;
void insert(int s,int t,int v){
 e[cnt].s=s,e[cnt].t=t,e[cnt].v=v,e[cnt].nxt=hd[s],hd[s]=cnt++;
 e[cnt].s=t,e[cnt].t=s,e[cnt].v=0,e[cnt].nxt=hd[t],hd[t]=cnt++;
}
bool bfs(int s,int t,int n){
 int head=0,tail=0,i;
 memset(dis,-1,sizeof(dis[0])*(n+1)),dis[s]=0;
 que[tail++]=s;
 while(head<tail){
 for(i=hd[que[head++]];i!=-1;i=e[i].nxt)
 if(e[i].v>0&&dis[e[i].t]==-1){
 dis[e[i].t]=dis[e[i].s]+1;
 if(e[i].t==t)return 1;
 que[tail++]=e[i].t;
 }
 }
 return 0;
}
int dinic(int s,int t,int n){
 int i,mf=0,tp;
 while(bfs(s,t,n)){
 for(i=0;i<n;i++)cur[i]=hd[i];
 int u=s,tail=0;
 while(cur[s]!=-1){
 if(u!=t&&cur[u]!=-1&&e[cur[u]].v>0&&dis[u]+1==dis[e[cur[u]].t]){
 que[tail++]=cur[u];u=e[cur[u]].t;
 }
 else if(u==t){
 for(tp=inf,i=tail-1;i>=0;i--)tp=min(tp,e[que[i]].v);
 for(mf+=tp,i=tail-1;i>=0;i--){
 e[que[i]].v-=tp;e[que[i]^1].v+=tp;
 if(e[que[i]].v==0)tail=i;
 }
 u=e[que[tail]].s;
 }
 else {
 while(u!=s&&cur[u]==-1)u=e[que[--tail]].s;
 cur[u]=e[cur[u]].nxt;
 }
 }
 }
 return mf;
}
int main(){
 int T,n,m,s,t,c,flag;
 scanf("%d",&T);
 for(int cas=1;cas<=T;cas++){
 scanf("%d%d",&n,&m);
 memset(hd,-1,sizeof(hd));
 cnt = 0;
 while(m--){
 scanf("%d%d%d%d",&s,&t,&c,&flag);
 if(flag){
 insert(t,s,c);
 }
 insert(s,t,c);
 }
 int ans = dinic(0,n-1,n);
 // cout<<ans<<endl;

 for(int i=0;i<cnt;i+=2){
 if(e[i].v==0){
 e[i].v=1;
 e[i^1].v=0;
 }
 else {
 e[i].v=inf;
 e[i^1].v=0;
 }
 }

 printf("Case %d: %d\n",cas,dinic(0,n-1,n));
 }
}