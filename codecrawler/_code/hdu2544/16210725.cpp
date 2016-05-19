#include<iostream>

using namespace std;

#define  INF 10000009
int d[105][105];

int n,m;

void init()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=(i==j?0:INF);
            
}

//   1 floyd  2 Dijkstra  3 Bellman-Ford  4 Dijkstra priority_queue  5  Bellman-Ford with queue
int main()
{
    while(cin>>n>>m)
    
    {
      
     if(n==0&&m==0)  break;
     
        init();
        
    int u,v,w;
    
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        d[u-1][v-1]=w;
        d[v-1][u-1]=w;
        
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(d[i][k]!=INF&&d[k][j]!=INF)d[i][j]=d[i][j]<(d[i][k]+d[k][j])?d[i][j]:(d[i][k]+d[k][j]);
    
    
    cout<<d[0][n-1]<<endl;
        
    }
    
}