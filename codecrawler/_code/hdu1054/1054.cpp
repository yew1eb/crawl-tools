/*
    【题意】 给定一棵树，标记一节点，则与该节点所连的边都被标记，问最少需要标记多少个节点使得所有边都被标记；
     或者说给定一个树型城堡，在交叉路口放一个士兵，则与该路口相连的路都被守住，
     问最少需要派遣多少个士兵来守住这个城堡
     
     dp[father].yes= （ min(dp[child].yes,dp[child].no) 之和）
     dp[father].yes=（ min(dp[child].yes,dp[child].no) 之和）

*/
#include<stdio.h>
#include<string.h>

struct node
{
  int father,brother,child;
  int yes,no;
  
  void init()
  {
       father=brother=child=0;
       yes=1;
       no=0;       
  }
}t[1505];

bool use[1505];
int min(int x,int y)
{
    if(x<y) return x;
    return y;
}

void dfs(int root)
{
   int child=t[root].child;
   while(child)
   {
         dfs(child);
         t[root].yes+=min(t[child].yes,t[child].no);
         t[root].no+=t[child].yes;
         child=t[child].brother;         
   }
}
/*
void dfs(int root)
{
  int child=t[root].child;
   while(child)
   {
         dfs(child);
         printf("root%d %d",root,child);
         child=t[child].brother;         
   }
}*/


int  main()
{
     int n,Root,root,cnt,j;
    while(scanf("%d",&n)!=EOF)
    {
      memset(use,0,sizeof(use));
      
      //int Root;
      
      for(int i=1;i<=n;i++)
      {
           scanf("%d:(%d)",&root,&cnt),root++;
           if(i==1) Root=root;
           
           if(!use[root])
           {
             t[root].init();
             use[root]=1;
           }
           
           while(cnt--)
           {
              scanf("%d",&j),j++;
              if(!use[j])
              {
                   t[j].init();
                   use[j]=1;
               }
               t[j].brother=t[root].child;
               t[j].father=root;
               t[root].child=j;
            }
        }
      
       dfs(Root); 
       
       printf("%d\n",min(t[Root].no,t[Root].yes));
                              
                              
    }   
     
     
 return 0;     
}