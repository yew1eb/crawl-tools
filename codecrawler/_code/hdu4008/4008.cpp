#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=100100;
struct node{
	int x;
	node *next;
}space[MAXN<<1],*edge[MAXN];
struct node2{
	int l,r,val;
}seg[MAXN<<3];
int C,pos,fir[MAXN],sec[MAXN],fa[MAXN][20],son[MAXN][2],q[MAXN<<1],dep[MAXN];
bool done[MAXN];

void addedge(int a,int b)
{
	node *p=&space[C++];
	p->x=a; p->next=edge[b]; edge[b]=p;
	p=&space[C++];
	p->x=b; p->next=edge[a]; edge[a]=p;
}

void dfs(int x, int d)
{
	node *p=edge[x];
	pos++; q[pos]=x; fir[x]=pos; dep[x]=d;
	while (p!=NULL)
	{
		if (done[p->x]) fa[x][0]=p->x;
		else
		{
			if (son[x][0]>p->x)
			{
				son[x][1]=son[x][0]; son[x][0]=p->x;
			}
			else if (son[x][1]>p->x)
			{
				son[x][1]=p->x;
			}
			done[p->x]=true;
			dfs(p->x,d+1);
		}
		p=p->next;
	}
	pos++; q[pos]=x; sec[x]=pos;
}

bool in(int k,int t)
{
	if (fir[k]<=fir[t]&&sec[k]>=sec[t]) return true;
	else return false;
}

void build(int x,int y,int m)
{
	seg[m].l=x; seg[m].r=y;
	if (x<y)
	{
		int index=(x+y)>>1;
		build(x,index,m<<1); build(index+1,y,m<<1|1);
	}
	else seg[m].val=q[x];
	if (x<y) seg[m].val=min(seg[m<<1].val,seg[m<<1|1].val);
}

int query(int x,int y,int m)
{
	if (seg[m].l>y||seg[m].r<x) return MAXN;
	if (seg[m].l>=x&&seg[m].r<=y) return seg[m].val;
	return min(query(x,y,m<<1),query(x,y,m<<1|1));
}

int findfa(int d,int x)
{
	int p=0,b[20];
	memset(b,0,sizeof(b));
	while (d>0)
	{
		b[++p]=d%2; d/=2;
	}
	int ans=x;
	for (int i=1;i<=p;i++)
		if (b[i]) ans=fa[ans][i-1];
	return ans;
}

int main(){
	int T,n,m,i,a,b,t,k,ans1,ans2,x;
	scanf("%d",&T);
	while (T--)
	{
		for (i=0;i<MAXN;++i) edge[i]=NULL;
		C=0;
		scanf("%d%d",&n,&m);
		for (i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		for (i=1;i<=n;i++)
		{
			son[i][0]=son[i][1]=MAXN;
		}
		memset(fir,0,sizeof(fir));
		memset(sec,0,sizeof(sec));
		memset(done,false,sizeof(done));
		memset(fa,0,sizeof(fa));
		done[1]=true; pos=0; //fa[1][0]=MAXN;
		dfs(1,0); fa[1][0]=MAXN;
	    for (int i=1;i<=17;i++)
            for (int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
		build(1,pos,1);
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&k,&t);
			if (!in(t,k))
			{
				ans2=query(fir[t]+1,sec[t]-1,1);
				ans1=son[t][0];
			}
			else
			{
				int d=dep[k]-dep[t]-1;
				x=findfa(d,k);
				ans2=min(query(fir[t]+1,fir[x]-1,1),query(1,fir[t]-1,1));
				ans2=min(ans2,query(sec[x]+1,sec[t]-1,1));
				ans2=min(ans2,query(sec[t]+1,pos,1));
				if ((son[t][0]==MAXN&&t==k)||in(son[t][0],k)) ans1=min(fa[t][0],son[t][1]);
				else ans1=min(son[t][0],fa[t][0]);

			}
			if ((fir[t]==sec[t]-1&&k!=t)||ans1==MAXN||ans2==MAXN) printf("no answers!\n");
			else printf("%d %d\n",ans1,ans2);
		}
		printf("\n");
	}
	return 0;
}