//============================================================================
// Name        : Stars.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=32010;

int n,c[MAXN],cnt[MAXN];

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int i,int val)
{
	while(i<MAXN)
	{
		c[i]+=val;
		i+=lowbit(i);
	}
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=c[i];
		i-=lowbit(i);
	}
	return s;
}

int main() {
	int x,y;
	while(scanf("%d",&n)!=EOF)
	{
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			cnt[sum(x+1)]++;
			add(x+1,1);

		}
		for(int i=0;i<n;i++)
		{
			printf("%d\n",cnt[i]);
		}
	}
	return 0;
}