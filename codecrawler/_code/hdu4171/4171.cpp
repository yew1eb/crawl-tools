#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define inf 2000000000
struct point
{
	vector<pair<int,int> > v;
};

int school[100005];
int zero[100005];
int biaoji[100005];

/*void dfs(int now,int val,vector<point> v)//TLE
{
	int i;
	for(i=0;i<v[now].v.size();i++)
	{
		if(biaoji[v[now].v[i].first]) continue;
		zero[v[now].v[i].first]=v[now].v[i].second+val;
		biaoji[v[now].v[i].first]=1;
		dfs(v[now].v[i].first,zero[v[now].v[i].first],v);
	}
}*/

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(biaoji,0,sizeof(biaoji));
		zero[0]=0;
		int i,j;
		for(i=0;i<n+1;i++)
			scanf("%d",&school[i]);
		vector<point> v(n+1);
		int total=0;
		for(i=0;i<n;i++)
		{
			int a,b,val;
			scanf("%d%d%d",&a,&b,&val);
			pair<int,int> t,tt;
			t.first=b;tt.first=a;
			t.second=val;tt.second=val;
			v[a].v.push_back(t);
			v[b].v.push_back(tt);
			total+=val;
		}
		queue<pair<int,int> > qu;
		int sum=0;
		biaoji[0]=1;
		while(1)
		{
			if(sum==0)
			{
				for(i=0;i<v[0].v.size();i++)
				{
					//v[0].v[i].second+=zero[0];
					qu.push(v[0].v[i]);
					sum=1;
				}
			}
			else
			{
				pair<int,int> t=qu.front();
				zero[t.first]=t.second;
				biaoji[t.first]=1;
				qu.pop();
				for(i=0;i<v[t.first].v.size();i++)
				{
					if(biaoji[v[t.first].v[i].first]) continue;
					v[t.first].v[i].second+=t.second;
					qu.push(v[t.first].v[i]);
				}
			}
			if(qu.empty()) break;
		}
		//dfs(0,0,v);
		total*=2;
		int min=inf;
		for(i=0;i<n+1;i++)
		{
			if(total-zero[i]+school[i]<min) min=total-zero[i]+school[i];
		}
		printf("%d\n",min);
	}
}