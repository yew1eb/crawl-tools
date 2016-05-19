#include <iostream>
 #include <vector>
 #include <algorithm>
 #include <cstdio>
 #include <cstring>
 #include <string>
 #include <map>

 #define MAX 100 + 5
 using namespace std;

 //dp[i][j]表示字符串a以a[i]结尾，字符串b以b[j]结尾的最大相似度
 int dp[MAX][MAX];

 int score[5][5]={
     {5,-1,-2,-1,-3},
     {-1,5,-3,-2,-4},
     {-2,-3,5,-2,-2},
     {-1,-2,-2,5,-1},
     {-3,-4,-2,-1,0}
 };

 int main(){
     map<char,int> table;
     table['A'] = 0;table['C'] = 1;table['G'] = 2;
     table['T'] = 3;table['-'] = 4;
     int T;
     cin >> T;
     while(T--){
         int na,nb;
         string stra,strb;
         cin >> na>>stra >> nb>>strb;
         memset(dp,0,sizeof(dp));
         //注意边界条件
         for(int i = 1; i <= na; i ++ ) dp[i][0] = dp[i-1][0] + score[ table[ stra[i-1] ] ][ table[ '-' ] ];
         for(int i = 1; i <= nb; i ++ ) dp[0][i] = dp[0][i-1] + score[ table['-'] ][ table[ strb[i-1] ] ];

         for(int i = 1 ; i <= na; i ++ ){
             for(int  j = 1; j <= nb; j ++){
                 dp[i][j]= max(dp[i- 1  ][j -1 ] + score[ table[ stra[i-1] ] ][ table[ strb[j-1] ]],
                               max(dp[i- 1  ][j] + score[ table[ stra[i-1] ]][ table[ '-' ]],  dp[i][j-1] + score[ table[ '-' ]][ table[ strb[j-1] ]]) );
             }
         }
         cout<<dp[na][nb]<<endl;

     }

     return 0;
 }