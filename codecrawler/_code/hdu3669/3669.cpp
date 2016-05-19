#include <cstdio>
#include <algorithm>

using namespace std;

typedef __int64 lli;

const int N = 50000 + 10;
const int K = 100 + 10;
const lli inf = ((lli)1<<62) - 1;

struct RECT
{
	int w, h;
};

RECT person[N];
int Q[N];
lli ans[2][N];
int head, tail;

bool operator < (const RECT& a, const RECT& b)
{
	if (a.w == b.w) return a.h < b.h;
	return a.w < b.w;
}

int main()
{
	lli res;
	int n, k, s, i, j;
//	freopen("J.in", "r", stdin);
	while (scanf("%d %d", &n, &k) > 0)
	{
		if (k > n) k = n;
		for (i=0; i<n; i++) scanf("%d %d", &person[i].w, &person[i].h);
		sort(person, person + n);
		for (i=j=1; i<n; i++)
		{
			while (j > 0 && person[j-1].h <= person[i].h) j --;
			person[j++] = person[i];
		}
		n = j;
		res = inf;
		for (i=0; i<n; i++) ans[1][i] = (lli)person[i].w * person[0].h;
		if (ans[1][n-1] < res) res = ans[1][n-1];
		for (i=2,s=0; i<=k; i++,s=1-s)
		{
			head = 0;
			tail = 1;
			Q[0] = i - 2;
			for (j=i-1; j<n; j++)
			{
				while (head < tail - 1 && ans[1-s][Q[head+1]] - ans[1-s][Q[head]] < (lli)(person[Q[head]+1].h - person[Q[head+1]+1].h) * person[j].w) head ++;
				ans[s][j] = ans[1-s][Q[head]] + (lli)person[Q[head]+1].h * person[j].w;
				if (j == n - 1) break;
				while (tail > head + 1 && (person[Q[tail-1]+1].h - person[j+1].h) * (ans[1-s][Q[tail-1]] - ans[1-s][Q[tail-2]]) > (person[Q[tail-2]+1].h - person[Q[tail-1]+1].h) * (ans[1-s][j] - ans[1-s][Q[tail-1]])) tail --;
				Q[tail++] = j;
			}
			if (ans[s][n-1] < res) res = ans[s][n-1];
		}
		printf("%I64d\n", res);
	}
	return 0;
}