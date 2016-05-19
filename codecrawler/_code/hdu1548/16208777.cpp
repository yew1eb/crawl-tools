#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
const int M = 1005;
int n;
bool visit[M];
int buttom[M],step[M];
int loc[M];

int judge( int x )
{
    if( x >= 1 && x<=n )
        return 1;
    return 0;    
}

int BFS( int start , int end )
{
    int front , tail;
    front = tail = 0;
    loc[front++] = start;
    while( front > tail ){
           int x = loc[tail++];
           if( x == end )
               break;
           int up,down;
           up = x+buttom[x];
           down = x-buttom[x];
           if( !visit[up] && judge(up) ){
               visit[up] = true;
               step[up] = step[x]+1;
               loc[front++] = up;    
           }
           if( !visit[down] && judge(down) ){
               visit[down] = true;
               step[down] = step[x]+1;
               loc[front++] = down;    
           }
    }
    return step[end];
}

int main( )
{
    int start, end;
    while( scanf("%d",&n) == 1 && n ){
           scanf("%d%d",&start,&end);       
           for( int i=1 ; i<=n ; i++ ){
                scanf("%d",&buttom[i]);
                visit[i] = false;
                step[i] = 0;
           }
           if( start == end )
               printf("0\n");
           else{
               int ans;
               ans = BFS( start , end );
               if( ans == 0 )
                   printf("-1\n");
               else
                   printf("%d\n",step[end]);
           }
    }    
    return 0;
}
