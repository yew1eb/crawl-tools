//简单的队列模拟
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int priority[101];
struct Job
{
	int priority;
	bool yours;
}job[101];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p,time = 1,pt = 0;
		memset(job,0,sizeof(Job)*100);
		queue<Job> q;
		scanf("%d%d",&n,&p);
		job[p].yours = 1;
		for(int i = 0;i < n;++i)
		{
			scanf("%d",&priority[i]);
			job[i].priority = priority[i];
			q.push(job[i]);
		}
		sort(priority,priority+n,cmp);
		while(q.front().priority != priority[pt] || !q.front().yours)
		{
			Job temp;
			temp = q.front();
			q.pop();
			if(temp.priority == priority[pt])
			{			
				pt++;
				++time;
			}
			else	q.push(temp);
		}
		
		printf("%d/n",time);
	}
	return 0;
}