#include<iostream>
#include<queue>
#include<string>
using namespace std;
int map[10][10];
char s1[5],s2[5];
int visted[10][10];
int x1,y1;
int x2,y2;
int dir[8][2]={1,2,-1,2,1,-2,-1,-2,2,1,2,-1,-2,1,-2,-1};
struct node
{
	int x,y,step;
};
void BFS()
{
	int x,y;
	node cur,next;
	queue<node>q;
	memset(visted,0,sizeof(visted));
	cur.x=x1;
	cur.y=y1;
	cur.step=0;
	visted[x1][y1]=1;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		if(cur.x==x2&&cur.y==y2)
		{
			printf("To get from %s to %s takes %d knight moves.\n",s1,s2,cur.step);
			return ;
		}
		for(int i=0;i<8;i++)
		{
			next.x=x=cur.x+dir[i][0];
			next.y=y=cur.y+dir[i][1];
		    next.step=cur.step+1;
			if(x>=0&&x<8&&y>=0&&y<8)
			{
				visted[x][y]=1;
				q.push(next);
			}

		}
	}
}


int main()
{
	
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		x1=s1[0]-'a';
		y1=s1[1]-'1';
		x2=s2[0]-'a';
		y2=s2[1]-'1';
		BFS();
	}
	return 0;
}