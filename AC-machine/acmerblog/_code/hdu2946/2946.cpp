#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b) (memset(a,b,sizeof(a)))
#define rep(i,a) for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

int a[30],b[30];
char s[2000],ss[2000];
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int len = strlen(s);
		clr(a,0);
		for(int i=0; i<len ; i++)	a[s[i]- 'A' ]++;

		scanf("%d",&n);
		while(n--)
		{
			clr(b,0);
			scanf("%s",ss);
			int l = strlen(ss);
			for(int i=0; i<l; i++)	b[ss[i] - 'A']++;

			bool ok = true;
			for(int i=0; i<26; i++)
				if(b[i] > a[i])
					ok = false;

			if(ok)	puts("YES");
			else	puts("NO");
		}


	}

	return 0;
}