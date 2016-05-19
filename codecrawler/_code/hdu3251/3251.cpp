/*
题意：给你f个可选城市，每个城市都有其价值w0,国王的城市在1,现在国王不想见到你（国王不想通过某种路径到达你选定的城市）——将你选的若干城市隔离出去，每条道路隔断都需要花费w1,现在问你可以达到的最大价值
并要求输出你割断的路的编号
题解：网络流模型题，将所有可选点连入超级汇点，求出最小割（等于最大流），最大价值为所有可选点的价值和减去最小割
我们默认最小割靠近源点的为左侧，靠近汇点为右侧
所有的割边的求法：最后一次求增广路的过程中，汇点不可达，此时从源点可增流的点都在记录路径的数组Qu里面
枚举数组里的值x，求出以x为起点，终点不在Qu中的所有边，这些边就是组成最小割的边
*/
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <map>
#include <string.h>
#include<queue>
#include<iostream>
#define N 60010
using namespace std;
const int maxn=1009;
const int inf=1<<30;
int n,m,f;
//**************************************************  
//为dinic求最大流模版  
struct edge  
{   
    int v, next;   
    int val;   
} net[ 200010 ];   
int Qnum;  //记录左侧点的数量
int level[maxn], Qu[maxn], out[maxn],next[maxn],ins[maxn],first[maxn];  
class Dinic {   
public:   
    int end;  
	int now;
	int low,high;
    Dinic() {   
        end = 0;   
        memset( next, -1, sizeof(next) );   
    }   
    inline void insert( int x, int y, int c) {   
        net[end].v = y, net[end].val = c,  
        net[end].next = next[x],   
        next[x] = end ++;   
        net[end].v = x, net[end].val = 0,  
        net[end].next = next[y],   
        next[y] = end ++;   
    }   
    bool BFS( int S, int E ) {   
        memset( level, -1, sizeof(level) );   
        low = 0, high = 1;   
        Qu[0] = S, level[S] = 0;   
        for( ; low < high; ) {   
            int x = Qu[low];   
            for( int i = next[x]; i != -1; i = net[i].next ) {   
                if( net[i].val == 0 ) continue;   
                int y = net[i].v;   
                if( level[y] == -1 ) {   
                    level[y] = level[x] + 1;   
                    Qu[ high ++] = y;   
                }   
            }   
            low ++;   
        }   
        return level[E] != -1;   
    }    
    
    int MaxFlow( int S, int E ){   
        int maxflow = 0;   
        for( ; BFS(S, E) ; ) {   
            memcpy( out, next, sizeof(out) );   
            now = -1;   
            for( ;; ) {   
                if( now < 0 ) {   
                    int cur = out[S];   
                    for(; cur != -1 ; cur = net[cur].next )    
                        if( net[cur].val && out[net[cur].v] != -1 && level[net[cur].v] == 1 )   
                            break;   
                    if( cur >= 0 ) Qu[ ++now ] = cur, out[S] = net[cur].next;   
                    else break;   
                }   
                int u = net[ Qu[now] ].v;   
                if( u == E ) {   
                    int flow = inf;   
                    int index = -1;   
                    for( int i = 0; i <= now; i ++ ) {   
                        if( flow > net[ Qu[i] ].val )   
                            flow = net[ Qu[i] ].val, index = i;   
                    }   
                    maxflow += flow;   
                    for( int i = 0; i <= now; i ++ )   
                        net[Qu[i]].val -= flow, net[Qu[i]^1].val += flow;   
                    for( int i = 0; i <= now; i ++ ) {   
                        if( net[ Qu[i] ].val == 0 ) {   
                            now = index - 1;   
                            break;   
                        }   
                    }   
                }   
                else{   
                    int cur = out[u];   
                    for(; cur != -1; cur = net[cur].next )    
                        if (net[cur].val && out[net[cur].v] != -1 && level[u] + 1 == level[net[cur].v])   
                            break;   
                    if( cur != -1 )   
                        Qu[++ now] = cur, out[u] = net[cur].next;   
                    else out[u] = -1, now --;   
                }   
            }   
        }   
		Qnum=high;//一定要记录此时在Qu数组里点的个数，方便后面枚举
        return maxflow;   
    }   
};   
  
struct E
{
	int v,next;
}edg[200011];
int ans;
void init(int k)
{
	int u,v,w;
	scanf("%d%d%d",&n,&m,&f);
	memset(ins,0,sizeof(ins));
	memset(first,-1,sizeof(first));
	Dinic my;
	int edg_num=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		edg[i].v=v;
		edg[i].next=first[u];
		first[u]=i;
		my.insert(u,v,w);
	}
	int sum=0;
	for(int i=0;i<f;i++)
	{
		scanf("%d%d",&u,&w);
		my.insert(u,n+1,w);
		sum+=w;
	}
	printf("Case %d: %d\n",k,sum-my.MaxFlow(1,n+1));
	sum=0;
	for(int i=0;i<Qnum;i++)
	ins[Qu[i]]=1;//标记所有左侧的点
	ans=0;
	//dfs(1);
	for(int i=0;i<Qnum;i++)
	{
		int x=Qu[i];
		for(int j=first[x];j!=-1;j=edg[j].next)
		{
			if(!ins[edg[j].v])
			out[ans++]=j;
		}
	}
	printf("%d",ans);
	for(int i=0;i<ans;i++)
	{
		printf(" %d",out[i]);
	}
	printf("\n");
}
int main() 
{
    int Case;
	scanf("%d",&Case);
	for(int i=1;i<=Case;i++)
	{
		init(i);
		//solve();
	}
    return 0;
}