#include<stdio.h>
#include<iostream>
#include<memory.h>
#include<vector>
#include<string>
using namespace std;
int dir[8][2]={-1,-2,-1,2,1,-2,1,2,-2,-1,-2,1,2,-1,2,1};
int n;
struct pt
{
	int x,y;
	pt(){}
	pt(int xx,int yy){x=xx;y=yy;}
};
struct seg
{
	pt p1,p2;
	seg(pt pp1,pt pp2){p1=pp1;p2=pp2;}
};
int cross(pt a,pt b)
{
	return a.x*b.y-a.y*b.x;
}
int cross(pt a,pt b,pt c)
{
	return cross(pt(a.x-c.x,a.y-c.y),pt(b.x-c.x,b.y-c.y));
}
vector<seg> SEG;
int visited[100][100];
vector<int> g[1001];
bool SegCross(seg s1,seg s2)
{
	if ((cross(s1.p1,s2.p1,s1.p2)*cross(s1.p1,s2.p2,s1.p2)<0)
		&& (cross(s2.p1,s1.p1,s2.p2)*cross(s2.p1,s1.p2,s2.p2)<0))
		return true;
	else return false;
}
bool judge(seg l)
{
 int i,j;
 for(i=0;i<SEG.size();i++)
	 if (SegCross(l,SEG[i])) return false;
 return true;
}
bool vtd[20000];
bool dfs(int x)
{
	int i;
	if (x/25==n) return true;
	if (vtd[x]) return false;
	vtd[x]=true;
	for(i=0;i<g[x].size();i++)
	{
		if (dfs(g[x][i])) return true;
	}
	return false;
}
bool is_win()
{
	int i;
	memset(vtd,0,sizeof(vtd));
	for(i=0;i<=n;i++)
	{
		if (dfs(i)) return true;
	}
	return false;
}

int main()
{
	int m,i,j,color,x,y;
	bool fl;
	while(cin>>n>>m)
	{
		if (n==0) break;
 SEG.clear();
		 memset(visited,0,sizeof(visited));
		 for(i=0;i<=1000;i++) g[i].clear();
		 color=1;
		 for(i=1;i<=m;i++)
		 {
			 scanf("%d%d",&x,&y);
			 visited[x][y]=color;
			 int xx,yy;
			 for(j=0;j<8;j++)
			 {
				 xx=x+dir[j][0];
				 yy=y+dir[j][1];
				 if ((xx>=0)&&(xx<=n)&&(yy>=0)&&(yy<=n))
				 if (visited[xx][yy]==color)
					 if ( judge(seg(pt(x,y),pt(xx,yy))) )
					 {
					//	 cout<<x<<' '<<y<<endl;
				//		 cout<<xx<<' '<<yy<<endl;
 SEG.push_back(seg(pt(x,y),pt(xx,yy)));
						 g[x*25+y].push_back(xx*25+yy);
						 g[xx*25+yy].push_back(x*25+y);
					 }
			 }
		//	 cout<<SEG.size()<<endl;
			 color=3-color;		
		 }
		 if (is_win()) printf("yes\n");
		 else printf("no\n");
	}

}