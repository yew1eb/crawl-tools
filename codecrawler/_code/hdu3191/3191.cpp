/*
	对于这个题目我又该做何解释，Dijsk是过了的，可是优先队列 + BFS 就是Wrong，想不明白，xwc也改不出来
	渐渐的觉得我就是一个悲剧，为何总是会出现那么离奇的事情呢？开始对自己无语了，一下几乎完全是XWC的代码，
	因为我实在在自己写的找不出错误。何也？？
求最短路和比最短路长一的路的总条数.

解法一、A*求第K短路，把前面K条路都求出来，象pku 2449 ,但是据说这个题的最后答案超过10^8，把路全部找出来肯定会爆priority_queue

解法二、

dp[i][1]表示到达点i最短的路有多少条，dp[i][2]表示次短的条数 

dist[i][1]表示到达点i最短路的长度,dist[i][2].........................

初始化为dist[st][1]=0 其他为max_int dp[st][1]=1 其他为0

用v去松驰u时有四种情况 (设当前dist[v][cas])

情况1：dist[v][cas]+w(v,u)<dist[u][1]，找到一个更短的距离，则把原来最短的距离作为次短的距离，同时更新最短的.即

dist[u][2]=dist[u][1] 

dist[u][1]=dist[v][cas]+w(v,u);  

dp[u][2]=dp[u][1] 

dp[u][1]=dp[v][cas]，

把Node(dist[u][1],u,1)和Node(dist[u][2],u,2)放入队列

情况2：dist[v][cas]+w(v,u)==dist[u][1]，找到一条新的相同距离的最短路，则dp[u][1]+=dp[v][cas],其他不用更新,也不入队

情况3：dist[v][cas]+w(v,u)<dist[u][2]，不可以更新最短距离，但可以更新次短的，则更新dist[u][2]和dp[u][2] 

dist[u][2]=dist[v][cas]+w(v,u); 

dp[u][2]=dp[v][cas];

把Node(dist[u][2],u,2)放入队列

情况4：dist[v][cas]+w(v,u)==dist[u][2] 找到一条新的相同距离的次短路,则dp[u][2]+=dp[v][cas],其他不更新。

*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x7f7f7f7f;
const int N = 55;
int cost[N][N];
bool hash[N][2];
int dis[N][2];
int dp[N][2];
void Dijsktra(int n, int s, int e)
{
	memset(hash, false, sizeof(hash));
	memset(dis, 0x7f, sizeof(dis));
	memset(dp, 0, sizeof(dp));
	dis[s][0] = 0;
	dp[s][0] = 1;
	int j;http://202.120.80.191 在for里面定义2次就是CE
	for(int i = 0; i < 2 * n; i++)
	{
		int min = INF;
		int x;
		int flag;
		for(j = 0; j < n; j++)
		{
			if(!hash[j][0] && dis[j][0] < min)
			{
				min = dis[j][0];
				x = j;
				flag = 0;
			}
			else if(!hash[j][1] && dis[j][1] < min)
			{
				min = dis[j][1];
				x = j;
				flag = 1;
			}
			
		}
		if(min == INF)
			break;
		hash[x][flag] = true;
		for(j = 0; j < n ; j++)
		{
			if(min + cost[x][j] < dis[j][0])
			{
				dis[j][1] = dis[j][0];
				dis[j][0] = min + cost[x][j];
				dp[j][1] = dp[j][0];
				dp[j][0] = dp[x][flag];
			}
			else if(min + cost[x][j] == dis[j][0])
			{
				dp[j][0] += dp[x][flag];
			}
			else if(min + cost[x][j] < dis[j][1])
			{
				dis[j][1] = min + cost[x][j];
				dp[j][1] = dp[x][flag];
			}
			else if(min + cost[x][j] == dis[j][1])
			{
				dp[j][1] += dp[x][flag];
			}
		}

	}


}
int main()
{
	int n, m, s, e;
	while(scanf("%d %d %d %d", &n, &m, &s, &e) != EOF )
	{
		int a, b, c;
		memset(cost, 0x7f, sizeof(cost));
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			cost[a][b] = c;
		}
		Dijsktra(n, s, e);
		printf("%d %d/n", dis[e][1], dp[e][1]);//printf("%d %d /n", dis[e][1], dp[e][1]);居然会写出这个的代码，在一个oj叫就是Wrong
							// 可是在hdu就是PE，我的god
	}
	return 0;//http://202.120.80.191  这里不加就是CE
}