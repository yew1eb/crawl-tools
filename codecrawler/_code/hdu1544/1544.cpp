#include<iostream>
 #include<cstdio>
 #include<cstring>
 using namespace std;
 #define MAXN 5005
 char str[MAXN];
 
 int main(){
     while(~scanf("%s",&str)){
         int len=strlen(str),l,r;
         int ans=len;
         for(int i=0;i<len;i++){
             l=i-1,r=i+1;//奇数长度
             while(l>=0&&r<len&&str[l]==str[r]){
                 l--,r++;
                 ans++;
             }
             l=i,r=i+1;//偶数长度
             while(l>=0&&r<len&&str[l]==str[r]){
                 l--,r++;
                 ans++;
             }
         }
         printf("%d\n",ans);
     }
     return 0;
 }