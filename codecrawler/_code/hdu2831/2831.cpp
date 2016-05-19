#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 #define MAXN 111
 struct Node{
    int v,d,index;
 }node[MAXN];
 int n,t;
 bool flag;
 
 int cmp(const Node &p,const Node &q){
    return p.v-p.d-t<q.v-q.d-t;
 }
 
 
 int main(){
  //  freopen("1.txt","r",stdin);
    while(~scanf("%d%d",&n,&t)){
       for(int i=1;i<=n;i++){
          scanf("%d%d",&node[i].v,&node[i].d);
          node[i].index=i;
       }
       sort(node+1,node+1+n,cmp);
       flag=true;
       int tt=t;
       for(int i=1;i<=n;i++){
          if(node[i].v-node[i].d-t<0){ flag=false;break; }
          t+=tt;
       }
       if(!flag){ puts("The zombies eat your brains!");continue; }
       for(int i=1;i<=n;i++){
          i==1?printf("%d",node[i].index):printf(" %d",node[i].index);
       }
       puts("");
    }
    return 0;
 }