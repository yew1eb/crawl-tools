#include"stdio.h"
#include"queue"
using namespace std;


struct node
{
	int num;
	friend bool operator<(node n1,node n2)
	{
		return n2.num<n1.num;
	}
};


int main()
{
	node cur,next;
	int n,k;
	int tot;
	char str[5];


	while(scanf("%d%d",&n,&k)!=-1)
	{
		priority_queue<node>q;
		tot=0;
		while(n--)
		{
			scanf("%s",str);
			if(str[0]=='Q')
			{
				cur=q.top();
				printf("%d\n",cur.num);
			}
			else
			{
				scanf("%d",&next.num);
				if(tot<k)	{q.push(next);tot++;}
				else
				{
					cur=q.top();
					if(next.num>cur.num)
					{
						q.pop();
						q.push(next);
					}
				}
			}
		}
	}


	return 0;
}