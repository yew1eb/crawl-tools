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

char s1[1000],s2[1000];
int T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s1,s2);
		if(strcmp(s1,s2) == 0)	puts("OK");
		else	puts("ERROR");
	}

	return 0;
}