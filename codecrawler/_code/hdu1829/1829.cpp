#define _CRT_SECURE_NO_WARNINGS
 #include<iostream>
 #include<cstdio>
 #include<cstring>
 using namespace std;
 const int MAXN=2000+20;
 int parent[MAXN];
 int mark[MAXN];
 int n,m;
 
 void Initiate(){
     memset(mark,0,sizeof(mark));
     for(int i=1;i<=n;i++){
         parent[i]=i;
     }
 }
 
 int Find(int x){
     int s=x;
     while(s!=parent[s]){
         s=parent[s];
     }
     return s;
     /*
     int s;
     for(s=x;parent[s]>=0;s=parent[s]);
     while(s!=x){
         int tmp=parent[x];
         parent[x]=s;
         x=tmp;
     }
     return s;
     */
 }
 
 void Union(int R1,int R2){
     int r1=Find(R1);
     int r2=Find(R2);
     if(r1<r2){
         parent[r2]=r1;
     }else
         parent[r1]=r2;
 }
 
 
 int main(){
     int _case,t=1;
     scanf("%d",&_case);
     while(_case--){
         scanf("%d%d",&n,&m);
         Initiate();
         bool flag=true;
         for(int i=1;i<=m;i++){
             int u,v;
             scanf("%d%d",&u,&v);
             if(!flag)continue;
             if(Find(u)==Find(v)){
                 //找到同性的了。。。
                 flag=false;
                 continue;
             }else {
                 if(mark[u]==0)mark[u]=v;
                 else Union(mark[u],v);//同性的并入一个集合
                 if(mark[v]==0)mark[v]=u;
                 else Union(mark[v],u);
             }
         }
         printf("Scenario #%d:\n",t++);
         if(!flag){
             printf("Suspicious bugs found!\n");
         }else {
             printf("No suspicious bugs found!\n");
         }
         puts("");
     }
     return 0;
 }