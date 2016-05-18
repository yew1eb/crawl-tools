　　#include<iostream>
 　　#include<stdio.h>
 　　using namespace std;
 　　struct node
 　　{
 　　    int end,next;       
 　　}edge[10002];
 　　int head[102],n,m,start,end,maxval,color[102];
 　　int answer[102];
 　　void dfs(int i,int j)
 　　{
 　　    if(i>=n)
 　　    {
 　　        if(j>maxval)
 　　        {
 　　            maxval=j;
 　　            for(int i=1;i<=n;i++)answer[i]=color[i];
 　　        }    
 　　        return ;
 　　    }
 　　    color[i]=-1;
 　　    int end;
 　　    for(end=head[i];end!=-1;end=edge[end].next)
 　　    {
 　　        if(color[edge[end].end]==-1)
 　　        break;
 　　    }
 　　    if(end==-1)dfs(i+1,j+1);
 　　    
 　　     color[i]=1;
 　　     dfs(i+1,j);
 　　     color[i]=0;
 　　    
 　　}
 　　int main()
 　　{
 　　   int t;
 　　   scanf("%d",&t);
 　　   while(t--)
 　　   {
 　　           scanf("%d%d",&n,&m);
 　　           for(int i=1;i<=n;i++)head[i]=-1;
 　　           for(int i=0,Count=0;i<m;i++)
 　　           {
 　　               scanf("%d%d",&start,&end);
 　　               edge[Count].end=end;
 　　               edge[Count].next=head[start];
 　　               head[start]=Count++;
 　　               edge[Count].end=start;
 　　               edge[Count].next=head[end];
 　　               head[end]=Count++;
 　　           }
 　　           maxval=0;
 　　           dfs(1,0);
 　　           printf("%d\n",maxval);
 　　           for(int i=1;i<=n;i++)if(answer[i]==-1)printf("%d ",i);
 　　           printf("\n");
 　　   }
 　　   return 0;    
 　　} 
 　　
 　　