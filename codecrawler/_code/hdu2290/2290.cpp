#include <iostream>
#include <cstdio>

using namespace std;
#define INF 10000000
struct Node
{
    int num,id;       
    bool operator<(Node a) const
    {
         return num < a.num;     
    }
}cop[210];
int pos[210],dp[210][210][210];

int main()
{
    int n,m,ca;
    scanf("%d",&ca);
    while(ca--)
    {
         scanf("%d %d",&n,&m);     
         for(int i=0;i<n;i++)                
         {
            scanf("%d",&cop[i].num);        
            cop[i].id=i;
         }
         sort(cop,cop+n);
         for(int i=0;i<n;i++)
           pos[cop[i].id]=i+1;
         for(int i=1;i<=n;i++)  
         for(int j=1;j<=n;j++)
            dp[i][j][0]=INF;
         int a,b,c;
         for(int i=0;i<m;i++)  
         {
               scanf("%d %d %d",&a,&b,&c);        
               dp[pos[a]][pos[b]][0]=dp[pos[b]][pos[a]][0]=c;
         } 
         for(int k=1;k<=n;k++)
         {
             for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
               dp[i][j][k]=dp[i][j][k-1];
             for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
               dp[i][j][k]=min(dp[i][j][k],dp[i][k][k-1]+dp[k][j][k-1]);
         }
         int Q;
         scanf("%d",&Q);
         while(Q--)
         {
              scanf("%d %d %d",&a,&b,&c); 
              int ans=dp[pos[a]][pos[b]][0];
              for(int i=n-1;i>=0;i--)         
                if(cop[i].num<=c) {ans=dp[pos[a]][pos[b]][i+1];break;}
              if(ans==INF) puts("-1");  
              else printf("%d\n",ans);
         }
         printf("\n");
    }
    return 0;    
}
