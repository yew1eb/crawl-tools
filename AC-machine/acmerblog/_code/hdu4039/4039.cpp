#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

const int N=2010;
int n, q, up, num;
char s[20], s1[20];
struct trie
{
	int a[26];
	int num;
	void init()
	{
		memset(a, -1, sizeof(a));
		num = -1;
	}
} t[10000];
vector<int> a[N];
vector<int>::iterator it, it1;
int cnt[N], flag[N], flag1;
struct node
{
	int i;
	char s[16];
} ss[N], ss1[N];

inline int insert(char *s)
{
	int p=0;
	while(*s)
	{
		if(t[p].a[*s-'a']==-1)
		{
			t[up].init();
			t[p].a[*s-'a'] = up++;
		}
		p = t[p].a[*s-'a'];
		s++;
	}
	if(t[p].num==-1)
	{
		t[p].num = num++;
		flag1 = 1;
	}
	return t[p].num;
}
inline int query(char *s)
{
	int p=0;
	while(*s)
	{
		if(t[p].a[*s-'a']==-1)
			return -1;
		p = t[p].a[*s-'a'];
		s++;
	}
	return t[p].num;
}
int cmp(const node &a, const node &b)
{
	return strcmp(a.s, b.s)<0;
}

int main()
{
	int i, j, cas, cas1, x, y, mx;
	
	scanf("%d", &cas);
	for(cas1=1; cas1<=cas; cas1++)
	{
		scanf("%d%d%d", &n, &q);
		t[0].init();
		up = num = 1;
		for(i=1; i<=n; i++)
		{
			scanf("%s %s", s, s1);
			flag1 = 0;
			x = insert(s);
			if(flag1==1)
				strcpy(ss[x].s, s);
			flag1 = 0;
			y = insert(s1);
			if(flag1==1)
				strcpy(ss[y].s, s1);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		printf("Case %d:\n", cas1);
		while(q--)
		{
			scanf("%s", s);
			for(i=1; i<num; i++)
				cnt[i] = 0;
			x = query(s);
			mx = 0;
			for(i=1; i<num; i++)
				flag[i] = 0;
			flag[x] = 1;
			for(it=a[x].begin(); it!=a[x].end(); it++)
				flag[*it] = 1;
			for(it=a[x].begin(); it!=a[x].end(); it++)
			{
				y = *it;
				for(it1=a[y].begin(); it1!=a[y].end(); it1++)
				{
					if(flag[*it1]==0)
					{
						cnt[*it1]++;
						if(cnt[*it1]>mx)
							mx = cnt[*it1];
					}
				}
			}
			if(mx==0)
			{
				printf("-\n");
				continue;
			}
			up = 0;
			for(i=1; i<num; i++)
			{
				if(cnt[i]==mx)
				{
					strcpy(ss1[up].s, ss[i].s);
					up++;
				}
			}
			sort(ss1, ss1+up, cmp);

			printf("%s", ss1[0].s);
			for(i=1; i<up; i++)
				printf(" %s", ss1[i].s);
			printf("\n");
		}
		
		for(i=1; i<num; i++)
			while(!a[i].empty())
				a[i].pop_back();
	}

	return 0;
}