#include <cstdio>
#include <set>
using namespace std;
template<class T> inline void checkmax(T &a, T b)
{if (b > a) a = b;}

int v[1000005];
int T, n;
set<int> S;

void work()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	int l = 1;
	int ans = 0;
	S.clear();
	for (int i = 1; i <= n; ++i) {
		int tmp = S.count(v[i]);
		if (tmp == 0) {
			S.insert(v[i]);
			checkmax(ans, i - l + 1);
		} else {
			while (v[l] != v[i]) {
				S.erase(v[l]);
				++l;
			}
			++l;
			checkmax(ans, i - l + 1);
		}
	}
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d", &T) != EOF)
		while (T--) work();
		
}