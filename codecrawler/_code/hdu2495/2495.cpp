#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
#define EPS 1e-8

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

struct tri
{
	int a,b,c;
	int x,y,z;
};

pair<int,int> findxy(int x1, int y1, int x2, int y2, double a, double b, double c)
{
	double the= acos( (a+b-c)/2 / sqrt(a) / sqrt(b));
	double x3= double(x1-x2)*sqrt(b)/sqrt(a);
	double y3= double(y1-y2)*sqrt(b)/sqrt(a);

	double x3r = x3*cos(-the) - y3*sin(-the);
	double y3r = x3*sin(-the) + y3*cos(-the);

	x3r += x2;
	y3r += y2;

	int x3i = (int) floor( x3r + 0.1);
	int y3i = (int) floor( y3r + 0.1);

	return make_pair(x3i,y3i);
}

int main()
{
	int n,m;
	cin>>n>>m;
	while(n && m)
	{
		int p[1001][2]={0};
		p[1][0]= 0; p[1][1]=0;
		p[2][0]= 0; p[2][1]=1;
		p[3][0]= 1; p[3][1]=0;
		bool set[1001]={};
		set[1]=set[2]=set[3]=1;

		tri t[1001];

		map<pair<int,int>, vector<int> > e2t;

		for(int i=1; i<=n; i++)
		{
			cin>>t[i].a>>t[i].b>>t[i].c>>t[i].x>>t[i].y>>t[i].z;

			e2t[make_pair(t[i].a,t[i].b) ].push_back(i);
			e2t[make_pair(t[i].b,t[i].a) ].push_back(i);

			e2t[make_pair(t[i].b,t[i].c) ].push_back(i);
			e2t[make_pair(t[i].c,t[i].b) ].push_back(i);

			e2t[make_pair(t[i].c,t[i].a) ].push_back(i);
			e2t[make_pair(t[i].a,t[i].c) ].push_back(i);
		}
		queue<int> que;
		que.push(*e2t[make_pair(1,2)].begin());
		bool visited_t[1001]={0};

		while(!que.empty())
		{
			int x=que.front();
			que.pop();
			visited_t[x]=1;

			if (!set[t[x].a])
			{
				pair<int,int> point;
				point = findxy( p[t[x].b][0], p[t[x].b][1], p[t[x].c][0], p[t[x].c][1],  t[x].y, t[x].z, t[x].x);
				p[t[x].a][0] = point.first;
				p[t[x].a][1] = point.second;
				set[t[x].a] = 1;
			}
			else if (!set[t[x].b])
			{
				pair<int,int> point;
				point = findxy( p[t[x].c][0], p[t[x].c][1], p[t[x].a][0], p[t[x].a][1],  t[x].z, t[x].x, t[x].y);
				p[t[x].b][0] = point.first;
				p[t[x].b][1] = point.second;
				set[t[x].b] = 1;
			}
			else if (!set[t[x].c])
			{
				pair<int,int> point;
				point = findxy( p[t[x].a][0], p[t[x].a][1], p[t[x].b][0], p[t[x].b][1],  t[x].x, t[x].y, t[x].z);
				p[t[x].c][0] = point.first;
				p[t[x].c][1] = point.second;
				set[t[x].c] = 1;
			}

			vector<int>::iterator it;
			for ( it = e2t[make_pair(t[x].a,t[x].b) ].begin(); it!=e2t[make_pair(t[x].a,t[x].b) ].end(); it++)
			{
				if (!visited_t[*it]) que.push(*it);
			}
			for ( it = e2t[make_pair(t[x].b,t[x].c) ].begin(); it!=e2t[make_pair(t[x].b,t[x].c) ].end(); it++)
			{
				if (!visited_t[*it]) que.push(*it);
			}
			for ( it = e2t[make_pair(t[x].a,t[x].c) ].begin(); it!=e2t[make_pair(t[x].a,t[x].c) ].end(); it++)
			{
				if (!visited_t[*it]) que.push(*it);
			}
		}

		for(int i=1; i<=m; i++) cout<<p[i][0]<<" "<<p[i][1]<<"\n";
		cin>>n>>m;
	}
	return 0;
}