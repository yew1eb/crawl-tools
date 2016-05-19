#include<stdio.h>
 #include<string.h>
 #include<queue>
 using namespace std;
 int a[1005][1005],f[1005][1005];
 struct node
 {
     int x,y;
     int flag;
     int count;
 };
 int n,m;
 int d[4][2]={0,1,0,-1,1,0,-1,0};
 int judge(int x,int y)
 {
     if(x>=1&&x<=n&&y>=1&&y<=m)
         return 1;
     return 0;
 }
 int bfs(int x,int y,int cx,int cy)
 {
     int i;
     queue<node>q;
     node cur,next;
     cur.x=x;
     cur.y=y;
     cur.flag=-1;
     cur.count=0;
     q.push(cur);
     a[x][y]=0;
     while(!q.empty())
     {
         cur=q.front();
         q.pop();
         if(cur.count>2)
         return 0;
         for(i=0;i<4;i++)
         {
             next.x=cur.x+d[i][0];
             next.y=cur.y+d[i][1];
             if(judge(next.x,next.y))
             {
                 if(cur.flag==-1||i==cur.flag)
                 {
                     next.flag=i;
                     next.count=cur.count;
                 }
                 if(cur.flag!=-1&&i!=cur.flag)
                 {
                     next.flag=i;
                     next.count=cur.count+1;
                 }
                 
                 if((a[next.x][next.y]>=next.count)&&(next.count<=2))
                 {    
                     if(f[next.x][next.y]==0||next.x==cx&&next.y==cy)
                     {
                         a[next.x][next.y]=next.count;
                         if(next.x==cx&&next.y==cy)
                             return 1;
                         
                         q.push(next);
                     }
                 }
             }
         }
     }
     return 0;
 }
 int main()
 {
     int i,j,sx,sy,cx,cy;
     int t;
     while(scanf("%d%d",&n,&m),n!=0||m!=0)
     {
         for(i=1;i<=n;i++)
             for(j=1;j<=m;j++)
             {
                 scanf("%d",&f[i][j]);
             }
             scanf("%d",&t);
             for(i=1;i<=t;i++)
             {
                 scanf("%d%d%d%d",&sx,&sy,&cx,&cy);
                 if(f[sx][sy]!=f[cx][cy]||f[sx][sy]==0||f[cx][cy]==0||(sx==cx&&sy==cy))
                 {
                     printf("NO\n");
                     continue;
                 }
                 else
                 {
                     memset(a,9,sizeof(a));
                     if(bfs(sx,sy,cx,cy))
                         printf("YES\n");
                     else
                         printf("NO\n");
                 }
             }
     }
     return 0;
 }