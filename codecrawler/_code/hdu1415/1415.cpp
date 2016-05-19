#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=110;
int sh[maxn],result;
int vis[maxn][maxn];
struct node
{
	int v[3];
	int fa;
}q[maxn*maxn];
node path[maxn*maxn];
void Print_path(int ans)
{
	int i=0,j,k;
	node p1,p2;
	while(q[ans].fa!=ans)
	{
		path[i++]=q[ans];
		ans=q[ans].fa;
	}
	path[i]=q[ans];
	while(i>=1)
	{
		p1=path[i];
		p2=path[--i];
		if(p1.v[0]==p2.v[0])//用标号为0的水壶中德前后两个状态作为判断标准
		{
			if(p1.v[1]<p2.v[1])
				printf("pour B A\n");
			else
				printf("pour A B\n");
		}
		else
		{
			for(j=1;j<3;j++)
				if(p1.v[j]==p2.v[j])
					break;
			k=3-j;
			if(p1.v[k]<p2.v[k])
				printf("fill %c\n",k-1+'A');
			else
				printf("empty %c\n",k-1+'A');
		}
	}
	printf("success\n\n");
}
void bfs()
{
	int i,j,k,start=0,tail=1;
	int amount;
	q[0].v[0]=sh[0];
	q[0].v[1]=q[0].v[2]=q[0].fa=0;
	vis[0][0]=1;
	while(start<tail)
	{
		node &u=q[start];
		if(u.v[1]==result||u.v[2]==result)
		{
			Print_path(start);//到达目标，打印方案
			return;
		}
		for(i=0;i<3;i++)//标号为i的水壶向标号为j的水壶中倒水
			for(j=0;j<3;j++)
				if(i!=j)
				{
					node &v=q[tail];
					if(u.v[i]<sh[j]-u.v[j])
						amount=u.v[i];//amount是此次操作可以倒出的水量
					else
						amount=sh[j]-u.v[j];
					for(k=0;k<3;k++)
						v.v[k]=u.v[k];//扩展新节点
					v.v[i]-=amount;//倒出
					v.v[j]+=amount;//倒进
					if(!vis[v.v[1]][v.v[2]])
					{
						vis[v.v[1]][v.v[2]]=1;//标记为已访问
						v.fa=start;
						tail++;
					}
				}
				start++;
	}
}
int main(void)
{
	while(scanf("%d%d%d",&sh[1],&sh[2],&result)!=EOF)
	{
		sh[0]=sh[1]+sh[2];
		memset(vis,0,sizeof(vis));
		bfs();
	}
}