#include<iostream>
 #include<vector>
 #include<queue>
 using namespace std;
 #define INF 1000000000
 vector<int>road[120];

 int dis[120],va[120],mark[120];
 int main()
 {
     int n,num,i,j,k,e;
     while(scanf("%d",&n)!=EOF)
     {
         if(n==-1)
             break;
         for(i=1;i<=n;i++)
         {
             road[i].clear();
             dis[i]=0;
             mark[i]=0;
         }
         dis[1]=100;
         for(i=1;i<=n;i++)
         {
             scanf("%d%d",&va[i],&num);
             while(num--)
             {
                 scanf("%d",&e);
                 road[i].push_back(e);
             }
         }
         mark[1]=1;
         int flag=1;
         for(i=1;i<n;i++)
         {
             flag=0;
             for(j=1;j<=n;j++)
             {
                 if(!mark[j])
                     continue;
                 int size=road[j].size();
                 for(k=0;k<size;k++)
                 {
                     int e=road[j][k];
                     if(dis[j]+va[e]>dis[e])
                     {
                         flag=1;
                         dis[e]=dis[j]+va[e];
                         mark[e]=1;
                     }
                 }
             }
             if(!flag) break;
         }
         while(1)
         {
             flag=0;
             for(j=1;j<=n;j++)
             {
                 if(!mark[j])
                     continue;
                 int size=road[j].size();
                 for(k=0;k<size;k++)
                 {
                     int e=road[j][k];
                     if(dis[j]+va[e]>dis[e])
                     {
                         flag=1;
                         dis[e]=INF;
                         mark[e]=1;
                         va[e]=-100;
                     }
                 }
             }
             if(!flag)
                 break;
         }
         if(dis[n]>0)
             printf("winnable\n");
         else
             printf("hopeless\n");
     }
 return 0;
 }