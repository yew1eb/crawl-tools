#include <stdio.h>
#include <string.h>
#include <queue>
#define inf 10000
#define ll short
#define end End

using namespace std;

struct Edge{
	short from, to, cap, nex;
}edge[1007];
short head[28], edgenum;
void addedge(short u, short v, short cap){
	Edge E ={u, v, cap, head[u]};
	edge[edgenum] = E;
	head[u] = edgenum++;
	Edge E_ = {v,u,0,head[v]};
	edge[edgenum] = E_;
	head[v] = edgenum++;
}

short sign[28];
bool BFS(short from, short to){
	memset(sign, -1, sizeof(sign));
	sign[from] = 0;

	queue<short>q;
	q.push(from);
	while( !q.empty() ){
		int u = q.front(); q.pop();
		for(short i = head[u]; i!=-1; i = edge[i].nex)
		{
			short v = edge[i].to;
			if(sign[v]==-1 && edge[i].cap)
			{
				sign[v] = sign[u] + 1, q.push(v);
				if(sign[to] != -1)return true;
			}
		}
	}
	return false;
}
short Stack[4], top, cur[4];
short dinic(short from, short to){
	short ans = 0;
	while( BFS(from, to) )
	{
		memcpy(cur, head, sizeof(head));
		short u = from;		top = 0;
		while(1)
		{
			if(u == to)
			{
				short flow = inf, loc;//loc 表示 Stack 中 cap 最小的边
				for(short i = 0; i < top; i++)
					if(flow > edge[ Stack[i] ].cap)
					{
						flow = edge[Stack[i]].cap;
						loc = i;
					}

					for(short i = 0; i < top; i++)
					{
						edge[ Stack[i] ].cap -= flow;
						edge[Stack[i]^1].cap += flow;
					}
					ans += flow;
					top = loc;
					u = edge[Stack[top]].from;
			}
			for(short i = cur[u]; i!=-1; cur[u] = i = edge[i].nex)//cur[u] 表示u所在能增广的边的下标
				if(edge[i].cap && (sign[u] + 1 == sign[ edge[i].to ]))break;
			if(cur[u] != -1)
			{
				Stack[top++] = cur[u];
				u = edge[ cur[u] ].to;
			}
			else
			{
				if( top == 0 )break;
				sign[u] = -1;
				u = edge[ Stack[--top] ].from;
			}
		}
	}
	return ans;
}
ll n;
char ss[22];
short ch[27], f[27];
bool use[27];
short start, end;

short find(short x){return x==f[x]?x:(f[x]=find(f[x]));}
void Union(short x, short y){
	short fx = find(x), fy = find(y);
	short temp = fx; if(fx>fy){fx=fy;fy=temp;}
	f[fx] = fy;
}
int main(){
	short T, i, j, Cas = 1; scanf("%d",&T);
	while(T--)
	{
		memset(ch, 0, sizeof(ch));
		memset(use,0, sizeof(use));
		for(i=0;i<27;i++)f[i] = i;
		memset(head, -1,sizeof(head)), edgenum = 0;

		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			scanf("%s %d",ss,&j);
			int a = ss[0]-'a', b = ss[strlen(ss)-1] - 'a';
			ch[a]++, ch[b]--;
			use[a] = use[b] = true;
			Union(a,b);

			if(j)addedge(a,b,1);
		}
		printf("Case %d: ",Cas++);
		bool ok = true;
		for(i=0;i<26;i++)
			if(use[i])
			{
				j = i;
				for(i++;i<26;i++)
					if(use[i] && find(j)!=find(i))ok = false;
				break;
			}
			short num = 0;
			for(i=0;i<26;i++)if(use[i] &&  ch[i]%2)
			{
				num++;
				if(ch[i]<0)start = i;
				else end = i;
			}
			if(num == 1 || num>2)ok = false;
			if(!ok){ printf("Poor boy!\n"); continue;}
			if(num == 2)addedge(end, start, 1);
			start = 26, end = 27;
			short sum = 0;
			for(i=0;i<26;i++)if(ch[i] && use[i] && i!=end && i!=start)
			{
				if(ch[i]<0)
					addedge(start,i,-ch[i]/2), sum-=ch[i]/2;
				else
					addedge(i,end, ch[i]>>1);
			}
			if(sum != dinic(start, end))
				printf("Poor boy!\n");
			else 
				printf("Well done!\n");

	}
}