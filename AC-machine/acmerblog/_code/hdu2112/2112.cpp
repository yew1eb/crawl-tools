#include<map>
 #include<string>
 #include<iterator>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 
 map<string, int> treeMap;
 map<string, int>::iterator mapIter1;
 map<string, int>::iterator mapIter2;
 const int inf = 1000000;
 const int Size = 160;
 
 bool vis[Size];
 int dist[Size];
 int cost[Size][Size];
 
 void Dijkstra(int v, int w, int n)
 {
     int i,j;
     int u;
     int min;
 
     for(i = 1; i <= n; i ++)
     {
         dist[i] = cost[v][i];
         vis[i] = false;
     }
 
     vis[v] = true;
     dist[v] = 0;
 
     for(i = 2; i <= n; i ++)
     {
         min = inf;
         for(j = 1; j <= n; j ++)
             if(!vis[j] && min > dist[j])
             {
                 min = dist[j];
                 u = j;
             }
 
         vis[u] = true;
 
         for(j = 1; j <= n; j ++)
             if(!vis[j] && dist[j] > dist[u] + cost[u][j])
                 dist[j] = dist[u] + cost[u][j];
     }
 
     if(dist[w] == inf)
         cout << "-1" << endl;
     else
         cout << dist[w] << endl;
 }
 
 int main()
 {
     int sp;
     int num;
     int len;
     int i,j;
     int cnt = 0;
     string start,destination;
     string begin,end;
 
     while(true)
     {
         cin >> num;
 
         if(num == -1)
             break;
 
         sp = 0;
         cnt = 0;
         treeMap.clear();
 
         cin >> start >> destination;
         if(!treeMap[start])
             {
                 cnt ++;
                 treeMap[start] = cnt;
             }
             if(!treeMap[destination])
             {
                 cnt ++;
                 treeMap[destination] = cnt;
             }
         
         for(i = 0; i < Size; i++)
             for(j = 0; j < Size; j++)
                 if(i == j)
                     cost[i][j] = 0;
                 else
                     cost[i][j] = inf;
 
         for(i = 1; i <= num; i ++)
         {
             cin >> begin >> end;
             if(!treeMap[begin])
             {
                 cnt ++;
                 treeMap[begin] = cnt;
             }
             if(!treeMap[end])
             {
                 cnt ++;
                 treeMap[end] = cnt;
             }
 
             cin >> len;
             cost[treeMap[end]][treeMap[begin]] = cost[treeMap[begin]][treeMap[end]] = len;
         }
 
         Dijkstra(treeMap[start], treeMap[destination], treeMap.size());
     }
 
     return 0;
 }