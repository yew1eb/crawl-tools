#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<vector>
 using namespace std;
 #define MAXN 33
 int map[MAXN][MAXN];
 int n;
 
 int main(){
     while(~scanf("%d",&n)&&n){
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 scanf("%d",&map[i][j]);
             }
         }
         int _case;
         scanf("%d",&_case);
         vector<int>vet;
         vector<int>::iterator iter;
         int start=0,end,dist=0;
         while(_case--){
             char str[10];
             scanf("%s",str);
             if(str[0]=='U'){
                 scanf("%d",&end);
                 if(end==start||vet.size()==7)continue;
                 vet.push_back(end);
             }else {
                 if(!vet.empty()){end=vet.front();dist+=map[start][end];start=end;}
                 iter=vet.begin();
                 while(iter!=vet.end()){
                     if((*iter)==end){
                         iter=vet.erase(iter);//返回指向vector的下一个位置
                     }else 
                         iter++;
                 }
             }
         }
         printf("%d\n",dist);
     }
     return 0;
 }