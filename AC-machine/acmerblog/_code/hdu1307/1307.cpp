#include<iostream>
 #include<cstdio>
 #include<cmath>
 #include<vector>
 #include<set>
 #include<map>
 using namespace std;
 int st,ed;
 map<int,vector<int> >Map;
 set<int>Set;
 int n;
 bool Input(int &num,int n){
     num=0;
     int x;
     for(int i=1;i<=n;i++){
         scanf("%d",&x);
         if(x==-1)return false;
         num=num*10+x;
     }
     return true;
 }
 
 bool dfs(int st,int ed){
     if(st==ed)return true;
     for(int i=0;i<Map[st].size();i++){
         int v=Map[st][i];
         //只能返回0或1，1表示该数已经插入
         if(!Set.count(v)){
             Set.insert(v);
             if(dfs(v,ed))return true;
         }
     }
     return false;
 }
 
 
 int main(){
     int x,t=1;
     while(scanf("%d",&n),n){
         Map.clear(),Set.clear();
         Input(st,n);
         Input(ed,n);
         int s,e;
         while(Input(s,n)){
             Input(e,n);
             Map[s].push_back(e);
             Map[e].push_back(s);
         }
         if(dfs(st,ed)){
             printf("Maze #%d can be travelled\n",t++);
         }else 
             printf("Maze #%d cannot be travelled\n",t++);
     }
     return 0;
 }