#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge
{
     int cost,id;
     Edge () {}
     Edge (int a,int b)
	 {
         cost = a,id = b;
     }
	 void Get (int _i)
	 {
		 id=_i;
		 scanf("%d",&cost);
	 }
	 bool operator < (const Edge &y) const
	 {
		 return cost>y.cost;
	 }
}data[100005];

int ans[100005],n,m;

int main ()
{
	int T,i;
	scanf("%d",&T);
	while (T--)
	{
		priority_queue<Edge> que;
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
			data[i].Get (i);
		sort (data,data+n);
		Edge temp;    //temp的id值表示它是由哪个机器处理的
		for (i=0;i<n;i++)
			if (i<m)     //都还没有任务的时候
			{
				que.push(Edge(data[i].cost,i));   //将时间和处理标号一起入队
				ans[data[i].id]=i;
			}
			else
			{
				temp=que.top ();
				ans[data[i].id]=temp.id;
				que.pop();
				que.push(Edge(temp.cost+data[i].cost,temp.id));//将目前用掉的总时间和处理标号入队
			}
		printf("%d\n",n);
		for (i=0;i<n;i++)
			printf(i==n-1?"%d\n":"%d ",ans[i]);
	}
	return 0;
}