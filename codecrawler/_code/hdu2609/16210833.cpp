
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define MAXN 210

int n , len;
char String[MAXN];
set<string>s;

/*æ±æå°è¡¨ç¤ºçä¸æ */
int getMin(){
   int i = 0 , j = 1 , k = 0;

   while(i+k < len && j+k < len){
      if(String[i+k] == String[j+k])
        k++;
      else{
        if(String[i+k] > String[j+k])
          i = i+k+1;
        else
          j = j+k+1;
        k = 0;
        if(i == j)
          j++;
      }
   }
   return min(i , j);
}

/*æ±åºæå°è¡¨ç¤º*/
void getMinString(char *str){
    str[len/2] = '\0';
    s.insert(str);
}

int main(){
   while(scanf("%d" , &n) != EOF){
      s.clear();
      for(int i = 0 ; i < n ; i++){
         scanf("%s" , String);
         
         char tmp[MAXN];
         memcpy(tmp , String , sizeof(String));
         strcat(String , tmp);
         len = strlen(String);/*æ±åºé¿åº¦*/
         
         int num = getMin();
         getMinString(String+num);
         
      }
      printf("%d\n" , s.size());
   }
   return 0;
}

