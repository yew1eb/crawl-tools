#include <iostream>
using namespace std;
#define INF 999999999

int map[101][101],visit[101],dis[101],N;
int prim()
{
    for(int i = 2; i <= N; i++)
    {
        visit[i] = 0;
        dis[i] = map[i][1];
    }
    visit[1] = 1;
    int sum = 0;
    for(int i = 1; i <= N-1; i++)
    {
        int temp = INF,pos; 
        for(int j = 1; j <= N; j++)
        {
            if(!visit[j] && dis[j] < temp)
            {
                temp = dis[j];
                pos = j;
            }    
        }
        visit[pos] = 1;
        sum += dis[pos];
        for(int j = 1; j <= N; j++)
        {
            if(!visit[j] && dis[j] > map[pos][j] && map[pos][j]!= INF)
                dis[j] = map[pos][j];
        }
    }
    return sum;
} 

int main()
{
    while(scanf("%d",&N),N)
    {
        int u,v,w;
        for(int i = 1; i <= N; i++)
            dis[i] = INF; 
        for(int i = 1; i <= (N*(N-1))/2; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            map[u][v] = map[v][u] = w;
        }
        cout<<prim()<<endl;
    }
}