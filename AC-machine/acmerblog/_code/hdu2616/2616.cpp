#include<stdio.h>
 #include<queue>
 using namespace std;
 
 int n,m,data[10][2];
 struct node
 {
     int spell,dist,hp;
 };
 
 int bfs(void)
 {
     node sn={0,0,m};
     queue<node> Q;
 
     Q.push(sn);
     while( !Q.empty() )
     {
         node cur=Q.front();
 
         Q.pop();
         for(int i=0;i<n;i++)
         {
             if( cur.spell&(1<<i) )  continue;
             node next={cur.spell|(1<<i),cur.dist+1,cur.hp-data[i][0]};
 
             if( cur.hp<=data[i][1] )    next.hp-=data[i][0];
             if( next.hp<=0 )    return next.dist;
             Q.push(next);
         }
     }
     return -1;
 }
 
 int main()
 {
     while( ~scanf("%d%d",&n,&m) )
     {
         for(int i=0;i<n;i++)
             scanf("%d%d",&data[i][0],&data[i][1]);
         printf("%d\n",bfs());
     }
     return 0;
 }
 /*
     简单的bfs+状压
     本来有个state[1024]数组，想剪掉一些肯定不是最优的情况
     但发现有没有这个数组时间都一样，就舍掉了。
     于是一个赤果果的bfs诞生了!!!
 */