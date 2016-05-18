#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

long value[20];
long Step[20][20];
char Map[60][60];
long W,H,L,M;
int stx, sty;

typedef struct
{
	long mi,mj;
	long step;
	long from;
}Node;

queue<Node> q;

bool hs[60][60][20];
long dx[]={0,1,-1,0};
long dy[]={1,0,0,-1};


long b;

inline void BFS()
{
	while (!q.empty())
	{
		q.pop();
	}
	memset(hs,0,sizeof(hs));

	Node point;
	point.mi = stx;
	point.mj = sty;
	point.from = 0;
	point.step = 0;
	q.push(point);
	hs[point.mi][point.mj][point.from]=true;


	while (!q.empty())
	{
		Node cur=q.front();
		q.pop();

		long j;
		Node next;

		for (j=0;j<4;++j)
		{
			next.mi=cur.mi+dx[j];
			next.mj=cur.mj+dy[j];
			next.step=cur.step+1;
			next.from=cur.from;
			if (next.mi>=0&&next.mi<H&&next.mj>=0&&next.mj<W)
			{
				if (next.step<=L&&!hs[next.mi][next.mj][next.from]&&Map[next.mi][next.mj]!='*')
				{
					hs[next.mi][next.mj][next.from]=true;
					q.push(next);

					if (Map[next.mi][next.mj]>='A'&&Map[next.mi][next.mj]<='J')
					{
						Step[next.from][Map[next.mi][next.mj]-'A'+2]=Step[Map[next.mi][next.mj]-'A'+2][next.from]=next.step;
						next.from=Map[next.mi][next.mj]-'A'+2;
						next.step=0;
						hs[next.mi][next.mj][next.from]=true;
						q.push(next);    
					}                
					else if (Map[next.mi][next.mj]=='@')
					{
						Step[next.from][0]=Step[0][next.from]=next.step;
						next.from=0;
						next.step=0;
						hs[next.mi][next.mj][next.from]=true;
						q.push(next);    
					}
					else if (Map[next.mi][next.mj]=='<')
					{
						Step[next.from][1]=Step[1][next.from]=next.step;
						next.from=1;
						next.step=0;
						hs[next.mi][next.mj][next.from]=true;
						q.push(next);    
					}
				}
			}

		}
	}
}

bool vist[20];
long lmax;
long all;

inline void dfs(long pos,long now,long step)
{
	if (lmax==all||step>L)
	{
		return;
	}
	if (Step[pos][1]!=-1&&step+Step[pos][1]<=L&&now>lmax)
	{
		lmax=now;
	}
	long i;
	for (i=2;i<M+2;++i)
	{
		if (!vist[i]&&Step[pos][i]!=-1)
		{
			vist[i]=true;
			dfs(i,now+value[i],step+Step[pos][i]);
			vist[i]=false;
		}
	}
}


int main()
{
	long T;
	scanf("%ld",&T);
	b=1;
	while (T--)
	{
		scanf("%ld%ld%ld%ld",&W,&H,&L,&M);
		long i,j;
		all=0;
		for (i=2;i<M+2;++i)
		{
			scanf("%ld",&value[i]);
			all+=value[i];
		}
		value[0]=value[1]=0;

		gets(Map[0]);
		for (i=0;i<H;++i)
		{
			gets(Map[i]);
			for (j=0;j<W;++j)
			{
				if (Map[i][j]=='@')
				{
					stx = i;
					sty = j;
				}
			}
		}

		memset(Step,-1,sizeof(Step));
		BFS();
		if (b!=1)
			puts("");
		printf("Case %ld:\n",b++);

		if (Step[0][1]==-1||Step[0][1]>L)
		{
			puts("Impossible");
			continue;
		}
		memset(vist,0,sizeof(vist));
		lmax=-1;
		vist[0]=true;
		dfs(0,0,0);
		if (lmax!=-1)
			printf("The best score is %ld.\n",lmax);
		else
			puts("Impossible");                
	}
	return 0;
}