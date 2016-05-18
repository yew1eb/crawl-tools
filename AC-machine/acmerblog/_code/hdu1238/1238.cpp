#include<iostream>
 #include<algorithm>
 #include<string>
 using namespace std;
 int n;
 string s[111];
 
 int cmp(const string p,const string q){
     return p.length()<q.length();
 }
 
 int dfs(string &str){
     int len=str.length();
     int flag=1;
     for(int i=len;i>=1;i--){
         for(int j=0;i+j<=len;j++){
             string temp=str.substr(j,i);
             string t=temp;
             string retemp=t.assign(t.rbegin(),t.rend());
             for(int k=1;k<n;k++){
                 if(s[k].find(temp)==-1&&s[k].find(retemp)==-1){
                     flag=0;
                     break;
                 }
             }
             if(flag)return temp.length();
             flag=1;
         }
     }
     return 0;
 }
 
 
 int main(){
     int t;
     scanf("%d",&t);
     while(t--){
         scanf("%d",&n);
         for(int i=0;i<n;i++){
             cin>>s[i];
         }
         sort(s,s+n,cmp);
         int ans=dfs(s[0]);
         printf("%d\n",ans);
     }
     return 0;
 }