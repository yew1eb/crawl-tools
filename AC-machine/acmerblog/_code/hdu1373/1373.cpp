#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct point
{
	int x,y,step;
};
int f[10][10];
int sx,sy,ex,ey;
int dir[][2]={1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
bool isval(int x,int y)
{
	if(x<=0||y<=0||x>8||y>8)return false;
	return true;
}
int bfs()
{
	queue<point>Q;
	point p;
	p.x=sx;p.y=sy;
	p.step=0;
	memset(f,0,sizeof(f));
	Q.push(p);
	while(!Q.empty())
	{
		point temp=Q.front();
		Q.pop();
		for(int i=0;i<8;i++)
		{
			point next;
			next.x=temp.x+dir[i][0];
			next.y=temp.y+dir[i][1];
			if(isval(next.x,next.y)&&f[next.x][next.y]==0)
			{
				next.step=temp.step+1;
				if(next.x==ex&&next.y==ey)return next.step;
				f[temp.x][temp.y]=1;
				Q.push(next);
			}
		}
	}
	return 0;
}
int main()
{
	char s[3],e[3];
	while(scanf("%s%s",s,e)!=EOF)
	{
		sx=s[0]-'a'+1;
		sy=s[1]-'0';
		ex=e[0]-'a'+1;
		ey=e[1]-'0';
		if(sx==ex&&sy==ey)
			printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],e[0],e[1],0);
		else printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],e[0],e[1],bfs());
	}
	return 0;
}