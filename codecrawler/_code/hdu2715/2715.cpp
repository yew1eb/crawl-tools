#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50 + 10;
const int maxpoint = 10000;
const int maxm = 200000;
struct Edge
{
	int d,c,w,pos;
	int next;
}E[maxm];
int w[maxn][maxn],h[maxn][maxn];
int pre[maxpoint],dis[maxpoint],head[maxpoint];
int que[maxm];
bool vis[maxpoint];
int NE,T;
int n,m,k;
int s,t;
void init()
{
	freopen("hoj2715.in","r",stdin);
	freopen("hoj2715.out","w",stdout);
}

void insert(int u,int v,int c,int w)
{
	E[NE].c = c;E[NE].pos = v;E[NE].d = u;E[NE].w = w;
	E[NE].next = head[u];head[u] = NE++;
    E[NE].c = 0;E[NE].pos = u;E[NE].d = v;E[NE].w = -w;
	E[NE].next = head[v];head[v] = NE++;	
}

void build_map()
{
	int tmp = n * n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			insert((i - 1) * n + j,((i - 1) * n + j) + tmp,1,-w[i][j]);
			insert((i - 1) * n + j,((i - 1) * n + j) + tmp,inf,0);
			insert(s,(i - 1) * n + j,k,0);
			if(i > 1 && h[i][j] > h[i-1][j])insert(((i - 1) * n + j) + tmp,(i - 2) * n + j,inf,0);
			if(i < n && h[i][j] > h[i+1][j])insert(((i - 1) * n + j) + tmp,i * n + j,inf,0);
			if(j > 1 && h[i][j] > h[i][j-1])insert(((i - 1) * n + j) + tmp,(i - 1) * n + j - 1,inf,0);
			if(j < n && h[i][j] > h[i][j+1])insert(((i - 1) * n + j) + tmp,(i - 1) * n + j + 1,inf,0);
			if(i == 1 || i == n || j == 1 || j == n)insert(((i - 1) * n + j) + tmp,t,inf,0);
		}
	}
}

int spfa()
{
	int l,r;
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	l = 0,r = 0;
	que[r++] = s;
	vis[s] = true;
	while(l < r)
	{
		int u = que[l++];l %= maxm;
		vis[u] = false;
		for(int i = head[u];i != -1;i = E[i].next)
		{
			int v = E[i].pos;
			if(E[i].c && dis[u] + E[i].w < dis[v])
			{
				dis[v] = dis[u] + E[i].w;
				pre[v] = i;
				if(!vis[v])
				{
					vis[v] = true;
					que[r++] = v;r %= maxm;
				}
			}
		}
	}
	if(dis[t] == inf)return false;
	else return true;
}

int MCMF()
{
	int ret = 0,flow = 0,cnt = 0;
	while(spfa())
	{
		int u = t;
		int min = inf;
		while(u != s)
		{
			if(E[pre[u]].c < min)min = E[pre[u]].c;
			u = E[pre[u]].d;
		}
		flow += min;
		u = t;
		while(u != s)
		{
			E[pre[u]].c -= min;
			E[pre[u]^1].c += min;
			u = E[pre[u]].d;
		}
		ret += dis[t];
		cnt++;
		if(cnt == k)break;
	}
	return ret;
}

void solve()
{
	memset(E,0,sizeof(E));
	memset(head,-1,sizeof(head));
	NE = 0,s = 0,t = n * n * 2 + 1;
	build_map();
	printf("%d\n",-MCMF());
}

void readdata()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(w,0,sizeof(w));
		memset(h,0,sizeof(h));
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				scanf("%d",&w[i][j]);
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				scanf("%d",&h[i][j]);
			}
		}
		solve();
	}
}

int main()
{
	init();
	readdata();
	return 0;
}