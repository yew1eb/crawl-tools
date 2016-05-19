#include <iostream>
#include <cstdio>
#include <cstring>
 using namespace std;

char s[500];

 int main(){
 //    freopen("in.txt", "r", stdin);
     while(gets(s)){
         int len = strlen(s);
         int cnt = 0;
         int k = 0;
         int flag = 1;
         for(int i=0; i<len; i++){
             if(s[i] == 'A') { cnt += 4; k++; }
             else if(s[i] == 'B') { cnt += 3; k++; }
             else if(s[i] == 'C') { cnt += 2; k++; }
             else if(s[i] == 'D') { cnt += 1; k++; }
             else if(s[i] == 'F') { cnt += 0; k++; }
             else if(s[i] == ' ') continue;
             else{
                 flag = 0;
                 break;
             }
         }
         if(!flag) printf("Unknown letter grade in input\n");
         else printf("%.2f\n", (float)cnt/k);
     }
     return 0;
 }