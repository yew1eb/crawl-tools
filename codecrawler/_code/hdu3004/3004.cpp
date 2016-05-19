# include <iostream>
# include <queue>
using namespace std;
const int size = 11;
struct node
{
       int mx, my;
       int px, py;
       int cx, cy;
       int step; 
};
int n, m;
int sx, sy;
bool hash[size][size][size][size][size][size];
node start, next, pre;
const int GoM[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
const int GoM1[8][2] = {{0, 1}, {0, -1}, {0, 1}, {0, -1}, {1, 0}, {1, 0}, {-1, 0}, {-1, 0}};
const int GoC[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mapp[size][size];
int ans;
bool check(int x, int y)
{
     return (x >= 0 && x < n && y >= 0 && y < m);     
}
/*void pri(node a)
{
     for (int i = 0; i < n; i ++){
         for (int j = 0; j < m; j ++){
             if (i == a.mx && j == a.my)cout<<"M";
             else
             if (i == a.cx && j == a.cy)cout<<"C";
             else
             if (i == a.px && j == a.py)cout<<"P";
             else if (mapp[i][j] == 'D')cout<<"D";
             else if (mapp[i][j] == 'S')cout<<"S";
             else cout<<'.';
         }    
         cout<<endl;
     }     
}*/
void bfs()
{
     memset(hash, false, sizeof(hash));
     start.step = 0;
     queue <node> Que;
     Que.push(start);
     hash[start.mx][start.my][start.px][start.py][start.cx][start.cy] = true;
     while (!Que.empty()){
           node pre = Que.front();
           Que.pop();
           //pri(pre);
           //cout<<pre.px<<' '<<pre.py<<endl;
           for (int i = 0; i < 8; i ++){//m
               int xx = pre.mx + GoM[i][0];
               int yy = pre.my + GoM[i][1];
               int judx = pre.mx + GoM1[i][0];
               int judy = pre.my + GoM1[i][1];// 
               if (!check(xx, yy) )continue;
               
               if ((judx == pre.px && judy == pre.py) || (judx == pre.cx && judy == pre.cy)||mapp[judx][judy] == 'D' || mapp[judx][judy] == 'S')continue;
               if ((xx == pre.px && yy == pre.py) || (xx == pre.cx && yy == pre.cy) || mapp[xx][yy] == 'D')continue;
               //cout<<"xx:"<<xx<<' '<<"yy:"<<yy<<' '<<"judx:"<<judx<<' '<<"judy:"<<judy<<' '<<mapp[xx][yy]<<endl;
               if (!hash[xx][yy][pre.px][pre.py][pre.cx][pre.cy]){
                  if (mapp[xx][yy] == 'S'){
                     //if (ans < pre.step)
                     ans = pre.step+1;
                     //pri(pre);                    
                     return ;                 
                  }
                  hash[xx][yy][pre.px][pre.py][pre.cx][pre.cy] = true;
                  next = pre;
                  next.mx = xx, next.my = yy;
                  next.step ++;
                  Que.push(next);
               }
               
           } 
           for (int i = 0; i < 4; i ++){//c
               for (int k = 1; k <= 10; k ++){ //cout<<"adsasd"<<endl;
                   int xx = pre.cx + k*GoC[i][0];
                   int yy = pre.cy + k*GoC[i][1];
                   if (!check(xx, yy) || (pre.mx == xx && pre.my == yy) || (pre.px == xx && pre.py == yy) || mapp[xx][yy] == 'D')break;
                   if (!hash[pre.mx][pre.my][pre.px][pre.py][xx][yy]){
                      
                      if (mapp[xx][yy] == 'S'){
                         ans = pre.step+1;
                         return ;                 
                      }
                      hash[pre.mx][pre.my][pre.px][pre.py][xx][yy] = true;
                      next = pre;
                      next.cx = xx, next.cy = yy;
                      next.step ++;
                      Que.push(next);
                   }
               }
               
           }
           for (int i = 0; i < 4; i ++){//p
               int flag = 0;
               for (int k = 1; k <= 10; k ++){
                   int xx = pre.px + k*GoC[i][0];
                   int yy = pre.py + k*GoC[i][1];//
                   
                   if (!check(xx, yy))break;
                   if ((pre.mx == xx && pre.my == yy) || (pre.cx == xx && pre.cy == yy) || mapp[xx][yy] == 'D' || mapp[xx][yy] == 'S')flag ++;
                    if (flag == 1 && mapp[xx][yy] == 'S')break;
                    if (flag == 1 )continue; 
                    
                   if (flag > 2 )break;//
                  
                  //cout<<"flag:"<<flag<<endl;
                   if (flag == 2 && mapp[xx][yy] != 'S')break;//cout<<"xx:"<<xx<<' '<<"yy:"<<yy<<' '<<flag<<' '<<mapp[xx][yy]<<endl;
                   //if (mapp[xx][yy] == 'S')
                   if (!hash[pre.mx][pre.my][xx][yy][pre.cx][pre.cy]){
                                                                      
                      if (mapp[xx][yy] == 'S'){
                         ans = pre.step+1;
                         //pri(pre);
                         return ;                 
                      }
                      hash[pre.mx][pre.my][xx][yy][pre.cx][pre.cy] = true;
                      next = pre;
                      next.px = xx, next.py = yy;
                      next.step ++;
                      Que.push(next);          
                   }   
               }
               
               
           }    
     }
     //pri(pre);
}
int main()
{
    //freopen("IN.txt", "r", stdin);
    //freopen("OUT.txt", "w", stdout);
    int nc = 0;
    while (scanf("%d%d", &n, &m) != EOF){
          for (int i = 0; i < n; i ++){
              scanf("%s", mapp[i]);   
              for (int j = 0; j < m; j ++){
                  if (mapp[i][j] == 'M'){
                     start.mx = i, start.my = j; 
                     mapp[i][j] = '.';              
                  }
                  if (mapp[i][j] == 'C'){
                     start.cx = i, start.cy = j;
                     mapp[i][j] = '.';               
                  }
                  if (mapp[i][j] == 'P'){
                     start.px = i, start.py = j;
                     mapp[i][j] = '.';               
                  }            
              } 
          }      
          ans = -1;
          printf("Scenario #%d\n", ++nc);
          bfs();
          if (ans == -1)printf("OH!That's impossible!\n\n");
          else
          printf("%d\n\n", ans);
    }
    return 0 ;
}
/*
5 5
P.DDS
...DD      
...CD
..M..
.....

5 5
....S
...MD
...DC
.....
.P...

5 5
C.DDS
P..D.      
...D.
..DM.
.....
7 9
PCD....S.
DD.......     
......D..
.....DMD.
......D..
.........
.........

5 5
P.DDS
.....      
.....
..DMD
....C

8 10
D.......CD
MDDD......
...D......
D..D...D..
.DD.DD.DD.
D.D...DD.D
DDD......D
..DDP..DDS

4 10
...DD.....
.P.......D
D..DDC...D
.MDDSD....

4 6
...D..
....D.
CM...S
..DP.D
*/