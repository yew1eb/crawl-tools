#include <stdio.h>
 #include <string.h>
 #include <iostream>
 #include <string>
 #include <vector>
 
 using namespace std;
 
 const int maxn = 2500 + 5;
 
 bool vis[maxn];
 int vs[55][55];
 int r, c;
 int link[maxn];
 vector<int> vt[maxn];
 
 int dx[]= {-1, -2, -2, -1, 1, 2,  2,  1, -1, 0, 1,  0};
 int dy[]= {-2, -1,  1,  2, 2, 1, -1, -2,  0, 1, 0, -1};
 
 bool find(int i)
 {
     int size = vt[i].size();
     for(int j = 0; j < size; j ++)
     {
         int k = vt[i][j];
         if(!vis[k])
         {
             vis[k] = true;
             if(link[k] == -1 || find(link[k]))
             {
                 link[k] = i;
                 return true;
             }
         }
     }
     return false;
 }
 
 void init()
 {
     for(int i = 0; i <= r * c; i ++)
         vt[i].clear();
     memset(vs, 0, sizeof vs);
     memset(link, -1, sizeof link);
 }
 
 int main()
 {
     int t = 1;
     while(scanf("%d%d", &r, &c) == 2 && r + c)
     {
         init();
         for(int i = 1; i <= r; i ++)
         {
             for(int j = 1; j <= c; j ++)
             {
                 scanf("%d", &vs[i][j]);
             }
         }
         for(int i = 1; i <= r; i ++)
         for(int j = 1; j <= c; j ++)
             if(vs[i][j] != -1)
             {
                 for(int k = 0; k < 12; k ++)
                 {
                     if((vs[i][j] >> k) & 1)
                     {
                         int x = i + dx[k];
                         int y = j + dy[k];
                         if(x >= 1 && x <= r && y >= 1 && y <= c && vs[x][y] != -1)
                         {
                             vt[c * (i - 1) + j].push_back(c * (x - 1) + y);
                             vt[c * (x - 1) + y].push_back(c * (i - 1) + j);
                         }
                     }
                 }
             }
         int ans = 0;
         for(int i = 1; i <= c * r; i ++)
         {
             memset(vis, false, sizeof vis);
             ans += find(i);
         }
         printf("%d. %d\n", t++, ans / 2);
     }
     return 0;
 }