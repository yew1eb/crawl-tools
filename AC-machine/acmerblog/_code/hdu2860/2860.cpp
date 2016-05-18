#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 #define MAXN 100000+100
 int parent[MAXN];
 int value[MAXN];
 int n,m,k;
 
 void Initiate()
 {
     memset(value,-1,(n+2)*sizeof(int));
     for(int i=0;i<n;i++)parent[i]=i;
     while(k--){
         int u,v;
         scanf("%d%d",&u,&v);
         if(value[v]==-1||u<value[v])value[v]=u;
     }
 }
 
 
 int Find(int x)
 {
     if(x==parent[x])
         return x;
     parent[x]=Find(parent[x]);
     return parent[x];
 }
 
 int main(){
     char str[11];
     int u,v;
     while(~scanf("%d%d%d",&n,&k,&m))
     {
         Initiate();
         while(m--){
             scanf("%s",str);
             if(str[0]=='A'){
                 scanf("%d%d",&u,&v);
                 if(parent[v]!=v){ puts("Reject");continue;}
                 puts("Accept");
                 if(value[v]==-1||u<value[v])value[v]=u;
             }else if(str[0]=='M'){
                 scanf("%d%d",&u,&v);
                 if(parent[u]!=u||parent[v]!=v||u==v){
                     puts("Reject");
                     continue;
                 }
                 puts("Accept");
                 parent[v]=u;
                 if(value[v]!=-1&&(value[u]==-1||value[u]>value[v])){
                     value[u]=value[v];
                 }
             }else {
                 scanf("%d",&u);
                 if(parent[u]==u&&value[u]!=-1)printf("Lowest rate: %d.\n",value[u]);
                 else if(parent[u]==u&&value[u]==-1)printf("Company %d is empty.\n",u);
                 else printf("Company %d is a part of company %d.\n",u,Find(u));
             }
         }
         puts("");
     }
     return 0;
 }