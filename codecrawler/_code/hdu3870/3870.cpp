#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int maxn=170000;

struct point
{
	int v,w;
}p0;

vector<point> e[maxn];
//queue<int>q;//
int n,S,T,q[maxn];
int dist[maxn];
bool inq[maxn];
int SPFA()
{
	int i,k,head=0,tail=0;

	memset(inq,false,sizeof(inq));
	for(i=0;i<=(n-1)*(n-1)+1;i++)
		dist[i]=0x3fffffff;
//	while(!q.empty()) q.pop();
//	q.push(S);
	q[tail++]=S;
	dist[S]=0;
	inq[S]=true;

	while(head!=tail)
	{
	//	k=q.front();
	//	q.pop();
		k=q[head];
		head=(head+1)%maxn;
		inq[k]=false;
		for(i=0;i<e[k].size();i++)
		{
			p0=e[k][i];
			if(dist[p0.v]>dist[k]+p0.w)
			{
				dist[p0.v]=dist[k]+p0.w;
				if(!inq[p0.v])
				{
					inq[p0.v]=true;
					q[tail]=p0.v;
					tail=(tail+1)%maxn;
				//	q.push(p0.v);
				}
			}
		}
	}
	return dist[T];
}

int main()
{
	int t,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<(n-1)*(n-1)+2;i++)
			e[i].clear();
		S=(n-1)*(n-1);
		T=(n-1)*(n-1)+1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&k);
				p0.w=k;
				if(i==0&&j!=n-1)
				{
					p0.v=j;
					e[S].push_back(p0);
				//	p0.v=S;
				//	e[j].push_back(p0);
				}
				if(j==n-1&&i!=n-1)
				{
					p0.v=i*(n-1)+j-1;
					e[S].push_back(p0);
				//	p0.v=S;
				//	e[i*(n-1)+j-1].push_back(p0);
				}
				if(j==0&&i!=n-1)
				{
					p0.v=T;
					e[i*(n-1)].push_back(p0);
				//	p0.v=i*(n-1);
				//	e[T].push_back(p0);
				}
				if(i==n-1&&j!=n-1)
				{
					p0.v=T;
					e[(n-2)*(n-1)+j].push_back(p0);
				//	p0.v=(n-2)*(n-1)+j;
				//	e[T].push_back(p0);
				}

				if(i!=n-1&&j!=n-1)
				{
					if(i)
					{
						p0.v=(i-1)*(n-1)+j;
						e[i*(n-1)+j].push_back(p0);
						p0.v=i*(n-1)+j;
						e[(i-1)*(n-1)+j].push_back(p0);
					}
					if(j)
					{
						p0.v=i*(n-1)+j-1;
						e[i*(n-1)+j].push_back(p0);
						p0.v=i*(n-1)+j;
						e[i*(n-1)+j-1].push_back(p0);
					}
				}
			}
		}

		printf("%d\n",SPFA());
	}
	return 0;
}