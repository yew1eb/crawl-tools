#include<iostream>
#include<queue>
using namespace std;
const int INF = 100000005;

struct node
{
    int x, y;
    long long num;     
};

int sign[4][2] = {1, 0, -1, 0, 0, 1, 0, -1}, n;
long long MapValue[52][52], dp[52][52];
int map[52][52];

void bfs() //bfs求机房到各点的最短距离 
{
    int i;
    node f1, f2;
    f1.x = n;
    f1.y = n;
    f1.num = map[n][n];
    queue<node> q;
    MapValue[n][n] = map[n][n];
    q.push(f1);
    
    while(!q.empty())
    {
         f1 = q.front();
         q.pop();
          
         for(i = 0; i < 4; ++i)
         {
             f2.x = f1.x + sign[i][0];
             f2.y = f1.y + sign[i][1];     
             if(f2.x > 0 && f2.y > 0 && f2.x <= n && f2.y <= n) 
             {
                 f2.num = f1.num + map[f2.x][f2.y];
                 if(f2.num < MapValue[f2.x][f2.y])
                 {
                       MapValue[f2.x][f2.y] = f2.num;
                       q.push(f2);      
                 }    
             }     
         }               
                      
    }  
}

long long dfs(int x, int y) //记忆化搜索 
{
     if(x == n && y == n) return 1;
     if(dp[x][y] != 0) return dp[x][y];
     int x1, y1;
     long long sum = 0;
     
     for(int i = 0; i < 4; ++i)
     {
          x1 = x+sign[i][0];
          y1 = y+sign[i][1];
          if(x1 >= 1 && y1 >= 1 && x1 <= n && y1 <= n) 
          {
              if(MapValue[x][y] > MapValue[x1][y1]) 
              {
                  sum+=dfs(x1, y1);
                  dp[x][y] = sum;
              }
          }      
     }  
     return sum;
}

int main()
{
    int i, j;
    
    while(cin>>n)
    {
        for(i = 1; i <= n; ++i)
        {
           for(j = 1; j <= n; ++j)
           {
               scanf("%d",&map[i][j]);
               MapValue[i][j] = INF;      
           }      
        }  
         
        bfs();
        memset(dp, 0, sizeof(dp));
        cout<<dfs(1, 1)<<endl;
                  
    }
    return 0;
}