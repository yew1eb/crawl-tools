#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<stack>
#define Max 100005
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct
{
	int lds;
	int rds;
	int mds;
	int lns;
	int rns;
	int mns;
	int coverds;
	int coverns;
}tree[Max<<2];
void build(int l,int r,int rt)
{
	tree[rt].lds=tree[rt].rns=tree[rt].rds=tree[rt].lns=tree[rt].mds=tree[rt].mns=r-l+1;
	tree[rt].coverds=tree[rt].coverns=-1;
	if(l==r)
	    return ;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void push_up(int rt,int len,int p)
{
	if(p==0)
	{
	    tree[rt].lds=tree[rt<<1].lds;
	    tree[rt].rds=tree[rt<<1|1].rds;
	    if(tree[rt].lds==len-(len>>1))
		    tree[rt].lds+=tree[rt<<1|1].lds;
	    if(tree[rt].rds==(len>>1))
		    tree[rt].rds+=tree[rt<<1].rds;
	    tree[rt].mds=max(tree[rt<<1].rds+tree[rt<<1|1].lds,max(tree[rt<<1].mds,tree[rt<<1|1].mds));
	}
	else
	{
		tree[rt].lds=tree[rt<<1].lds;
	    tree[rt].rds=tree[rt<<1|1].rds;
	    if(tree[rt].lds==len-(len>>1))
		    tree[rt].lds+=tree[rt<<1|1].lds;
	    if(tree[rt].rds==(len>>1))
		    tree[rt].rds+=tree[rt<<1].rds;
	    tree[rt].mds=max(tree[rt<<1].rds+tree[rt<<1|1].lds,max(tree[rt<<1].mds,tree[rt<<1|1].mds));
		tree[rt].lns=tree[rt<<1].lns;
	    tree[rt].rns=tree[rt<<1|1].rns;
	    if(tree[rt].lns==len-(len>>1))
		    tree[rt].lns+=tree[rt<<1|1].lns;
	    if(tree[rt].rns==(len>>1))
		    tree[rt].rns+=tree[rt<<1].rns;
	    tree[rt].mns=max(tree[rt<<1].rns+tree[rt<<1|1].lns,max(tree[rt<<1].mns,tree[rt<<1|1].mns));
	}
}
void push_down(int rt,int len)
{
	if(tree[rt].coverds!=-1)
	{
		tree[rt<<1].coverds=tree[rt<<1|1].coverds=tree[rt].coverds;
		tree[rt<<1].lds=tree[rt<<1].rds=tree[rt<<1].mds=tree[rt].coverds?0:len-(len>>1);
		tree[rt<<1|1].lds=tree[rt<<1|1].rds=tree[rt<<1|1].mds=tree[rt].coverds?0:(len>>1);
		tree[rt].coverds=-1;
	}
	if(tree[rt].coverns!=-1)
	{
		tree[rt<<1].coverns=tree[rt<<1|1].coverns=tree[rt].coverns;
		tree[rt<<1].lns=tree[rt<<1].rns=tree[rt<<1].mns=tree[rt].coverns?0:len-(len>>1);
		tree[rt<<1|1].lns=tree[rt<<1|1].rns=tree[rt<<1|1].mns=tree[rt].coverns?0:(len>>1);
		tree[rt].coverns=-1;
	}
}
int query(int pos,int p,int l,int r,int rt)
{
	if(l==r)
		return l;
	push_down(rt,r-l+1);
	int m=(l+r)>>1;
	if(p==0)
	{
	    if(pos<=tree[rt<<1].mds)
			return query(pos,p,lson);
		else if(tree[rt<<1].rds+tree[rt<<1|1].lds>=pos)
			return m-tree[rt<<1].rds+1;
		else
			return query(pos,p,rson);
	}
	else
	{
		if(pos<=tree[rt<<1].mns)
			return query(pos,p,lson);
		else if(tree[rt<<1].rns+tree[rt<<1|1].lns>=pos)
			return m-tree[rt<<1].rns+1;
		else
			return query(pos,p,rson);
	}
}
void update(int L,int R,int p,int c,int l,int r,int rt)
{
	if(L<=l&&R>=r)
	{
		if(p==0)
		{
			tree[rt].lds=tree[rt].rds=tree[rt].mds=c?0:r-l+1;
			tree[rt].coverds=c;
		}
		else
		{
			tree[rt].lns=tree[rt].rns=tree[rt].mns=c?0:r-l+1;
			tree[rt].coverns=c;
		}
		return ;
	}
	push_down(rt,r-l+1);
	int m=(l+r)>>1;
	if(L<=m)
		update(L,R,p,c,lson);
	if(R>m)
		update(L,R,p,c,rson);
	push_up(rt,r-l+1,p);
}
int main()
{
	int i,t,m,n,time,a,b,ans;
	char op[10];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		a=b=0;
		scanf("%d%d",&n,&m);
		build(1,n,1);
		printf("Case %d:\n",i);
		while(m--)
		{
			scanf("%s",op);
			switch(op[0])
			{
			case 'D':
				scanf("%d",&time);
				if(time>tree[1].mds)
					printf("fly with yourself\n");
				else
				{
				    ans=query(time,0,1,n,1);
				    printf("%d,let's fly\n",ans);
					update(ans,ans+time-1,0,1,1,n,1);
				}
				break;
			case 'N':
				scanf("%d",&time);
				if(time>tree[1].mds)
				{
				    if(time>tree[1].mns)
					    printf("wait for me\n");
				    else
				    {
					    ans=query(time,1,1,n,1);
					    printf("%d,don't put my gezi\n",ans);
					    update(ans,ans+time-1,0,1,1,n,1);
					    update(ans,ans+time-1,1,1,1,n,1);
				    }
				}
				else
				{
					ans=query(time,0,1,n,1);
					printf("%d,don't put my gezi\n",ans);
					update(ans,ans+time-1,0,1,1,n,1);
					update(ans,ans+time-1,1,1,1,n,1);
				}
				break;
			case 'S':
				scanf("%d%d",&a,&b);
				printf("I am the hope of chinese chengxuyuan!!\n");
				update(a,b,0,0,1,n,1);
				update(a,b,1,0,1,n,1);
				break;
			}
		}
	}
	return 0;
}