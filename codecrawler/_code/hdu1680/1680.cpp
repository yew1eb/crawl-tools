#include<iostream>

using namespace std;

#include<queue>

int xK,yK,xP,yP;

struct Node

{

     int K_x,K_y,P_x,P_y;

     int t;

}N,P;

char map[10][10];

int dir[][2]={-1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1, -1,-1};

int mark[8][8][10];

bool bfs()

{

     int i,tx,ty,flag;

     memset(mark,0,sizeof(mark));

     queue<Node>Q;

     N.K_x=xK;

     N.K_y=yK;

     N.P_x=xP;

     N.P_y=yP;

     N.t=0;

     mark[N.K_x][N.K_y][N.t]=1;

     Q.push(N);

     while(!Q.empty())

     {

         N=Q.front();

         Q.pop();

         for(i=0;i<8;i++)

         {

             tx=N.K_x;ty=N.K_y;     

             tx+=dir[i][0];

             ty+=dir[i][1];

             if(tx <0 || tx >8 || ty<0 || ty > 8 || map[tx][ty]!='.' || (tx == N.P_x+1&& ty== N.P_y-1) || (tx==N.P_x+1 && ty== N.P_y+1))

                 continue;

             P.K_x=tx;

             P.K_y=ty;

             P.P_x=N.P_x+1;

             P.P_y=N.P_y;

             P.t=N.t+1;

             if((P.P_x==P.K_x && P.P_y== P.K_y)||(P.K_x==N.P_x && P.K_y== N.P_y) || map[P.P_x][P.P_y]=='F')

             {

                 flag=1;

                 return 1;

             }

             if(P.P_x<=7 && !mark[P.K_x][P.K_y][P.t])

             {

                 Q.push(P);

                 mark[P.K_x][P.K_y][P.t]=1;

             }     

         }

     }

     return 0;

}

int main()

{

     int i,t;

     scanf("%d",&t);

     while(t--)

     {

         for(i=0;i<8;i++)

             scanf("%s",&map[i]);

         scanf("%d %d",&yK,&xK);yK--;xK=8-xK;

         scanf("%d %d",&yP,&xP);yP--;xP=8-xP;     

         if(bfs())

             printf("White\n");

         else printf("Black\n");

     }

}