#include<iostream>
 #include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<string>
 using namespace std;
 #define MAXN 333
 struct Node{
     int f1,f2;
 }C[MAXN];
 char str[MAXN];
 int path[MAXN];
 bool mark[MAXN];
 int p;
 struct Page{
     int tag;
     string str;
 }Text[MAXN];
 
 bool dfs(int page){
     path[p++]=page;
     if(Text[page].tag==2)return true;
     if(Text[page].tag==1)return false;
     int next1=C[page].f1;
     int next2=C[page].f2;
     if(!mark[next1]){
         mark[next1]=true;
         if(dfs(next1))return true;
         p--;
     }
     if(!mark[next2]){
         mark[next2]=true;
         if(dfs(next2))return true;
         p--;
     }
     return false;
 }
 
 
 int main(){
     int _case,t=1,n,len;
     scanf("%d",&_case);
     while(_case--){
         scanf("%d",&n);
         getchar();
         p=0;
         memset(Text,0,sizeof(Text));
         for(int page=1;page<=n;page++){
             gets(str),len=strlen(str);
             //是字母
             string s;
             if(isalpha(str[len-1])){
                 for(int i=len-5;i<len;i++)s+=str[i];
                 char s1[MAXN];
                 if(s=="HAPPY"){
                     sscanf(str,"%*[^\"]\"%[^\"]\"%*[^ ]%*s",s1);
                     s=s1;
                     Text[page].str=s;
                     Text[page].tag=2;
                 }else {
                     sscanf(str,"%*[^\"]\"%[^\"]\"%*[^ ]%*s",s1);
                     s=s1;
                     Text[page].str=s;
                     Text[page].tag=1;
                 }
             }else {
                 char s1[MAXN];
                 int x,y;
                 sscanf(str,"%*[^\"]\"%[^\"]\" %d %d",s1,&x,&y);
                 s=s1;
                 Text[page].str=s;
                 Text[page].tag=0;
                 C[page].f1=x,C[page].f2=y;
             }
         }
         memset(mark,false,sizeof(mark));
         mark[1]=true;
         dfs(1);
         printf("STORY %d\n",t++);
         for(int i=0;i<p;i++){
             cout<<Text[path[i]].str<<endl;
         }
     }
     return 0;
 }