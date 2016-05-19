/*
 * Author: NICK WONG
 * Created Time:  2015/8/4 13:50:07
 * File Name: 1010.cpp
 */
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
#define out(x) cout<<#x<<": "<<x<<endl
const double eps(1e-8);
const int maxn=210;
const long long maxint=-1u>>1;
const long long maxlong=maxint*maxint;
typedef long long lint;
int tt,_n,_m,k,mp[510][maxn],year,ans;
bool a[maxn][maxn],vis[maxn];
#define MAXN 710
#define INF 1000000000

void init()
{
    cin>>_n>>_m>>k;
}

void dfs(int x)
{
    vis[x]=true;
    mp[year][++mp[year][0]]=x;
    for (int i=1; i<=_n; i++)
        if (!vis[i] && a[x][i]) dfs(i);
}

#define a aaa
struct Edge {
    int from , to , cap , flow , cost;
};

int n ;
vector<Edge> edges;
vector<int> G[MAXN];
int inq[MAXN];
int d[MAXN];
int p[MAXN];
int a[MAXN];

void G_init()
{
    for ( int i = 0 ; i < n ; i++ ) G[i].clear();
    edges.clear();
}

void addedge ( int from , int to , int cap , int cost ) 
{
    edges.push_back((Edge){from,to,cap,0,cost});
    edges.push_back((Edge){to,from,0,0,-cost});
    int m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

bool spfa ( int s , int t , int &flow , int &cost ) 
{
    for ( int i = 0 ; i < n ; i++ ) d[i] = INF;
    memset ( inq  , 0 , sizeof (inq ) );
    d[s] = 0; inq[s] = 1; p[s] = 0 ; a[s] = INF;
    
    queue<int> Q;
    Q.push(s);
    while ( !Q.empty() ) {
        int u = Q.front() ; Q.pop();
        inq[u] = 0;
        for ( int i = 0 ; i < (int) G[u].size() ; i++ ) {
            Edge &e = edges[G[u][i]];
            if ( e.cap > e.flow && d[e.to] > d[u] + e.cost ) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = G[u][i];
                a[e.to] = min( a[u] , e.cap - e.flow );
                if ( !inq[e.to] ) { Q.push(e.to); inq[e.to] = 1; }
            }
        }
    }
    if ( d[t] == INF ) return false;
    flow += a[t];
    cost += d[t] * a[t];//d[t]å¢å¹¿åä½æµéçè´¹ç¨ * a[t]æµé
    int u = t;
    while ( u != s ) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
        u = edges[p[u]].from;
    }
    return true;
}

int Mincost (int s, int t) 
{
    int flow = 0 , cost = 0;
    //int time=10;
    while ( spfa(s,t,flow,cost) )
    {
        //out(flow);
        //if (--time)  break;
    }
    return flow;
}
#undef a

void work()
{
    memset(a,false,sizeof(a));
    memset(mp,0,sizeof(mp));
    year=0;
    for (int i=1; i<=_m; i++)
    {
        int type,x,y,p;
        scanf("%d",&type);
        if (type==1)
        {
            scanf("%d",&x);
            year++;
            memset(vis,false,sizeof(vis));
            dfs(x);
        } else 
            if (type==2)
            {
                scanf("%d%d",&x,&y);
                a[x][y]=a[y][x]=true;
            } else
                if (type==3)
                {
                    scanf("%d",&p);
                    for (int j=1; j<=p; j++)
                    {    
                        scanf("%d%d",&x,&y);
                        a[x][y]=a[y][x]=false;
                    }
                }
    }
    /*
       out(year);
       for (int i=1; i<=year; i++)
       {
       for (int j=1; j<=mp[i][0]; j++)
       cout<<mp[i][j]<<" ";
       cout<<endl;
       } */
    //memset(cost,0,sizeof(cost));
    //memset(mat,0,sizeof(mat));
    //memset(flow,0,sizeof(flow));
    n=2+_n+year;
    G_init();
    for (int i=1; i<=_n; i++)
        addedge(0,i,1,0);
    //for (int i=year; i>=1; i--)
    for (int i=1; i<=year; i++)
        for (int j=1; j<=mp[i][0]; j++)
            addedge(mp[i][j],_n+i,1,0);
            //mat[mp[i][j]][_n+i]=1;
    for (int i=1; i<=year; i++)
    {
        addedge(_n+i,1+_n+year,k,year-i);
        //addedge(1+_n+year,_n+i,0,-(year-i));
        //mat[_n+i][1+_n+year]=k;
        //cost[_n+i][1+_n+year]=year-i;
        //cost[1+_n+year][_n+i]=-(year-i);//reflect
    }
    //G.addedge(2+_n+year,1+_n+i,k);
    //ans=G.max_flow(2+_n+year,1);
    //out(122);
    ans=Mincost(0,1+_n+year);
    cout<<ans<<endl;
    //out(233);
    int build[510];
    memset(build,0,sizeof(build));
    for ( int i = 0 ; i < (int) G[1+_n+year].size() ; i++ ) 
    {
        Edge& e = edges[G[1+_n+year][i]];
        build[e.to]=-e.flow;
    }
    for (int i=1; i<=year; i++)
    {
        //out(G.head[1+_n+i]);
        cout<<build[_n+i];
        if (i==year) cout<<endl; else cout<<" ";   
    }
}

int main()
{
    cin>>tt;
    while(tt--)
    {
        init();
        work();
    } 
    return 0;
}

