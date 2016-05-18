#include<stdio.h>
 #include<iostream>
 #include<string.h>
 #include<stdlib.h>
 #include<math.h>
 #include<map>
 #include<stack>
 #include<queue>
 #include<algorithm>
 #define mem(a,b) memset(a,b,sizeof(a))
 #define MAX(a,b) ((a)>(b)?(a):(b))
 #define MIN(a,b) ((a)<(b)?(a):(b))
 #define INF 0x3f3f3f3f
 #pragma comment(linker, "/STACK:102400000,102400000")
 using namespace std;
 
 int vis[1000009];
 int prime[10000];
 int cc = 0;
 
 void init() {
     int i;
     mem(vis, -1);
     cc = 1;
     for(i = 2; ; i++) {
         if(vis[i] == -1) {
             prime[cc++] = i;
             if(cc > 3000) {
                 break;
             }
             vis[i] = 1;
             int cnt = 0;
             for(int j = i + 1; j <= 100000; j++) {
                 cnt -= vis[j];
                 if(cnt == i) {
                     cnt = 0;
                     vis[j] = 0;
                 }
             }
         }
     }
 }
 
 int main() {
 #ifndef ONLINE_JUDGE
     freopen("E:/ACMData.txt","r",stdin);
 #endif
     int n;
     init();
     while(cin>>n, n) {
         cout<<prime[n]<<endl;
     }
     return 0;
 }